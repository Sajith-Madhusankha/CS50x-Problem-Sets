#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Get User Input
    string text = get_string("Text: ");

    //Declaring variables to store letter, word and sentence count
    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    //Calculating L and S values for Coleman-Liau index
    //For L
    float L = ((float)letter_count * 100) / word_count;
    //For S
    float S = ((float)sentence_count * 100) / word_count;

    //Calculating Coleman-Liau index
    float subindex = 0.0588 * L - 0.296 * S - 15.8;
    //Rounding Decimal subindex value to Integer index value
    int index = round(subindex);

    //Printing Grade
    //For Grades lower than 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    //For grades above 16
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }

    //For grades between 1 and 16
    else
    {
        printf("Grade %i\n", index);
    }

}

//Calculating letters count
int count_letters(string text)
{
    int length = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            length++;
        }
    }
    return length;

}

//Calculating words count
int count_words(string text)
{
    int words = 1;

    for (int j = 0, len = strlen(text); j < len; j++)
    {
        if (isblank(text[j]))
        {
            words++;
        }
    }
    return words;

}

//Calculating Sentences count
int count_sentences(string text)
{
    int sentences = 0;
    for (int k = 0, len = strlen(text); k < len; k++)
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}