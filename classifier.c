#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    char *filename = 0;
    int total = 0;
    int min = 0;
    int max = 10;
    int x[5] = {8, 7, 4, 1, 3};  // dog
    int x2[5] = {5, 4, 3, 6, 4}; // dog
    int x3[5] = {1, 2, 4, 5, 3}; // cat
    int x4[5] = {0, 9, 2, 4, 6}; // cat
    int dog = 500;
    int cat = 0;
    int weights[5];
    int learning_rate = 4;

    for (int i = 0; i < 5; ++i)
    {
        weights[i] = rand() % (max - min + 1) + min;
    }
    printf("The weights are: ");
    // weight and x dot product
    for (int j = 0; j < 5; ++j)
    {
        printf(" %d ", weights[j]);
    }
    for (int i = 0; i < 5; i++)
    {
        if (i < 2)
        {
            weights[i] = weights[i] + learning_rate * (-x[i] + (dog - weights[i] * x[i]));
        }
        else
        {
            weights[i] = weights[i] + learning_rate * (-x[i] * (cat - weights[i] * x[i]));
        }
    }
    
    printf("\nThe new weights are: ");
    // weight and x dot product
    for (int j = 0; j < 5; ++j)
    {
        printf(" %d ", weights[j]);
    }


    return 0;
}

int sigma(int i, int m, int* weights[], int* x[])
{
    int sum;
    for(i; i<m; ++i){
        sum += (*weights)[i] * (*x)[i];
    }
    return sum;
}