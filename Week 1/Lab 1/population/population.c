#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_population, end_population, years = 0;
    //Prompt for start size
    do
    {
        start_population = get_int("Enter the starting population size (must be at least 9): ");
    }
    while (start_population < 9);
    //Prompt for end size
    do
    {
        end_population = get_int("Enter the ending population size (must be greater than start population): ");
    }
    while (start_population > end_population);

    //Calculate number of years until we reach threshold
    while (start_population < end_population)
    {
        start_population += start_population / 3 - start_population / 4;
        years++;
    }
    //Print number of years
    printf("Years: %d\n", years);
}
