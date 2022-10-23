// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE]; // creating 44 bytes of array to start reading & writing

    fread(header, HEADER_SIZE, 1, input);   // reading "HEADER_SIZE" bytes from "input" into "header" variable's address "1" each time;
    fwrite(header, HEADER_SIZE, 1, output); // writing "HEADER_SIZE" bytes from "header" variable's address into "output" "1" each time;

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer; // creating a variable to start reading & writing;

    while (fread(&buffer, sizeof(int16_t), 1, input)) // reading "int16_t" size of bytes from "input" into "buffer" variable's address "1" each time;
    {
        buffer *= factor; // multiplying the volume;

        fwrite(&buffer, sizeof(int16_t), 1, output); // writing "int16_t" size of bytes from "buffer" variable's address into "output" "1" each time;
    }

    // Close files
    fclose(input);
    fclose(output);
}
