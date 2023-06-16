// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//Choose number of buckets in hash table
const unsigned int N = 456976;

// Hash table
node *table[N];

int total_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Obtain hash value
    int hash_value = hash(word);

    //Access Linked list
    node *n = table[hash_value];

    //Look for the word
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }

    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Open Dictionary file
    FILE *dic_ptr = fopen(dictionary, "r");

    //Check if null
    if (dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    //Initialize word array
    char next_word[LENGTH + 1];

    //Read strings from file
    while (fscanf(dic_ptr, "%s", next_word) != EOF)
    {
        //Create new node for each word found
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        //Copy word into node using strcopy
        strcpy(n->word, next_word);

        //Has word to obtain has value
        int hash_value = hash(next_word);

        // Insert node into hash table
        n->next = table[hash_value];
        table[hash_value] = n;
        total_words++;
    }
    //close file
    fclose(dic_ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //Free the linked list
    for (int i = 0; i < N; i++)
    {
        //Assign a pointer
        node *n = table[i];

        //Loop through linked list
        while (n != NULL)
        {
            //make temporary cursor
            node *tmp = n;
            //point n to next element
            n = n->next;
            //free tmp
            free(tmp);
        }

        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }

    return false;
}
