#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int rgbt = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = rgbt;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        //iterate through array until reach mid-point
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE copy = image[i][j];
            //swap pixels
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = copy;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Make a copy of image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Create varibales and initialize them
            int sum_blue = 0;
            int sum_green = 0;
            int sum_red = 0;
            float counter = 0;

            //Check if a pixel have other pixels around it, if not continue to search
            //iterate through column
            for (int h = -1; h < 2; h++) //started from -1 to check the pixel above
            {
                //iterate through rows
                for (int w = -1; w < 2; w++) //started from -1 to check the pixel on the left
                {
                    //check if the pixel is outside image
                    if (i + h < 0 || i + h > (height - 1))
                    {
                        continue;
                    }
                    if (j + w < 0 || j + w > (width - 1))
                    {
                        continue;
                    }
                    //sum the values of all the pixels
                    sum_blue += image[i + h][j + w].rgbtBlue;
                    sum_green += image[i + h][j + w].rgbtGreen;
                    sum_red += image[i + h][j + w].rgbtRed;
                    counter++;
                }
            }

            //find average color value
            copy[i][j].rgbtRed = round(sum_red / counter);
            copy[i][j].rgbtGreen = round(sum_green / counter);
            copy[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    //Copy color values from copy to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
        }
    }
    return;
}
