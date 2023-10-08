#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
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
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase
    char lowerWord[LENGTH + 1];
    for (int i = 0; word[i]; i++)
    {
        lowerWord[i] = tolower(word[i]);
    }
    lowerWord[strlen(word)] = '\0';

    // Hash the word to find the index
    unsigned int index = hash(lowerWord);

    // Traverse the linked list at the index
    node *cursor = table[index];
    while (cursor != NULL)
    {
        // Compare the lowercase word with the dictionary word
        if (strcmp(cursor->word, lowerWord) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Simple hash function using the first letter
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Open dictionary file for reading
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    // Read words from file and insert into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for the word
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy the word into the node
        strcpy(newNode->word, word);

        // Hash the word to find the index
        unsigned int index = hash(word);

        // Insert the node at the beginning of the linked list
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Close the dictionary file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            count++;
            cursor = cursor->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            // Keep a pointer to the current node
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
