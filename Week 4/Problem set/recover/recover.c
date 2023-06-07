#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check for number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    //open input file
    FILE *input_pointer = fopen(argv[1], "r");

    if (input_pointer == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    //set output pointer to NULL
    FILE *output_pointer = NULL;

    //Create an array to store 512bytes from the memory card
    BYTE buffer[512];

    //Count amount of jpeg files found
    int jpeg_number = 0;

    //String to hold a file name
    char filename[8];

    //Check until end of the card
    while (fread(&buffer, 512, 1, input_pointer) == 1)
    {
        //Check first 4 bytes to verify JPEG format
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if not first JPEG, close previous
            if (!(jpeg_number == 0))
            {
                fclose(output_pointer);
            }
            //Initialize file
            sprintf(filename, "%03i.jpg", jpeg_number);
            output_pointer = fopen(filename, "w");
            jpeg_number++;
        }
        //if JPEG has been found, write to the file
        if (!(jpeg_number == 0))
        {
            fwrite(&buffer, 512, 1, output_pointer);
        }
    }

    fclose(input_pointer);
    fclose(output_pointer);
    return 0;
}