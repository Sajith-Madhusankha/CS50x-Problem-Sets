#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Get Key as CLI
int main(int argc, string argv[])
{
    //Check if argument count not equal to 2. Print eroor if not equal to 2
    if (argc != 2)
    {
        printf("Usage: .caesar key\n");
        return 1;
    }

    //Check if Key have any alphabetical characters. Print error mesasage if any
    for (int key = 0; key < strlen(argv[1]); key++)
    {
        if (isalpha(argv[1][key]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;

    //Ask for Plain text from user
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, length = strlen(plaintext); i < length;  i++)
    {
        //Check if any characters from plain text is not an alphabetic character
        if (!isalpha(plaintext[i]))
        {
            //print non alphabetical characters without any change
            printf("%c", plaintext[i]);
            continue;
        }

        //Assign 65 to offset if character i is uppercase letter. If lower 97.
        int offset = isupper(plaintext[i]) ? 65 : 97;

        // calculating how far the current element is from lowercase "a" or uppercase "A"
        int pi = plaintext[i] - offset;

        // index of the letter cyphering
        int ci = (pi + key) % 26;

        // printing the new character cyphered
        printf("%c", ci + offset);
    }

    printf("\n");
    return 0;
}