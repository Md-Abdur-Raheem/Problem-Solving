#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    BYTE buffer[512];
    int bytes_read, counter = 0;
    char filename[8];

    FILE *img = NULL;

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open memory card
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("./recover card.raw\n");
        return 2;
    }
    while (1)
    {
        // read 512 bytes into the buffer
        bytes_read = fread(&buffer, sizeof(BYTE), 512, f);

        // if starts of a new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            // if it is the first jpeg
            if (counter == 0)
            {
                // create a file & write it
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, img);
                counter++;
            }
            // if it is not first file then close the existing file & open a new file.
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, img);
                counter++;
            }
        }
        // if already found jpeg keep writing to it and it might occur multiple times.
        else if (counter != 0)
        {
            fwrite(buffer, sizeof(BYTE), bytes_read, img);
            // if end of file reached close the file
            if (bytes_read == 0)
            {
                fclose(img);
                fclose(f);
                return 0;
            }
        }
    }
    // close any remaining files
    fclose(img);
    fclose(f);
}