#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../includes/lodepng.h"

void decode(const char *, unsigned char **);

unsigned WIDTH = 250;
unsigned HEIGHT = 187;

int main()
{
    srand(time(NULL));
    int *weights = malloc(WIDTH * HEIGHT * 4);
    int learning_rate = 2;
    unsigned char *pixels = NULL;
    FILE *ptrweight;
    const char *filename = "cat.0.png";
    decode(filename, &pixels);

    ptrweight = fopen("weights.txt", "w");

    printf("The pixels are: \n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int index = (i * WIDTH + j) * 4;
            unsigned char r = pixels[index + 0];
            unsigned char g = pixels[index + 1];
            unsigned char b = pixels[index + 2];
            unsigned char a = pixels[index + 3];
            printf("\n x%d =  R=%u G=%u B=%u A=%u", index, r, g, b, a);
        }
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++)
    {
        int random1 = rand() % 255;
        int random2 = rand() % 255;
        int random3 = rand() % 255;
        int random4 = rand() % 255;
        char str[20]; // Increase buffer size to avoid overflow.
        sprintf(str, "%d %d %d %d\n", random1, random2, random3, random4);
        fprintf(ptrweight, "%s", str); // Use "%s" to print the string safely.
    }

    return 0;
}

void decode(const char *filename, unsigned char **pixels)
{
    unsigned error;

    error = lodepng_decode32_file(pixels, &WIDTH, &HEIGHT, filename);
    if (error)
        printf("error %u: %s\n", error, lodepng_error_text(error));
}
