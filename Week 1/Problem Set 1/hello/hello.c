#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Take name as input
    string name = get_string("What's your name?: ");
    //Print output sentence
    printf("hello, %s\n", name);
}