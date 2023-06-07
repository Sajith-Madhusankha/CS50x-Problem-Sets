#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    //Go through height
    for (int i = 0; i < height; i++)
    {
        //Go through width
        for (int j = 0; j < width; j++)
        {
            //Check for black pixels
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                //Make black pixels yellow
                image[i][j].rgbtRed = 0xff;
                image[i][j].rgbtGreen = 0xff;
            }
        }
    }
}
