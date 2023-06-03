#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    //Get User Input
    string message = get_string("Message: ");

    //Calculation to get 8-bit binary number
    for (int i = 0, len = strlen(message); i < len; i++)
    {
        char c = message[i];
        for (int j = 7; j >= 0; j--)
        {
            char bit = ((c >> j) & 1);
            print_bulb(bit);
        }
        //Go to New Line for every character
        printf("\n");
    }


}
//Print Bulbs
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
