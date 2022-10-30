// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100;
int count_word = 0;

// Hash table
node *table[N];

// prototypes
void free_node(node *n);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // find the position of the word from the table
    int hash_num = hash(word);

    // create a cursor variable
    node *cursor = table[hash_num];

    // loop until the end of the linked list
    while (cursor != NULL)
    {
        // check if the words are the same
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        // otherwise, move cursor to the next node
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    int value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        value += tolower(word[i]);
    }
    return value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *dict_file = fopen(dictionary, "r");

    // check if return value is null
    if (dict_file == NULL)
    {
        return false;
    }

    // read strings from file one at a time
    char str[LENGTH + 1];
    while (fscanf(dict_file, "%s", str) != EOF)
    {
        // create a new node for each word
        // use malloc
        node *temp = malloc(sizeof(node));
        // check if return value is NULL
        if (temp == NULL)
        {
            return false;
        }

        // copy word into node using strcpy
        strcpy(temp->word, str);

        // use the hash function
        int hash_num = hash(str);

        // check if the head is pointing to NULL
        if (table[hash_num] == NULL)
        {
            // point temp to null
            temp->next = NULL;
        }
        else
        {
            // otherwise point temp to the first word of the linked lis
            temp->next = table[hash_num];
        }
        // point the header to temp
        table[hash_num] = temp;

        count_word++;
    }
    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count_word;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            free_node(table[i]);
        }
    }
    return true;
}

void free_node(node *n)
{
    if (n->next != NULL)
    {
        free_node(n->next);
    }
    free(n);
}
