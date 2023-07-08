#include <stdio.h>
#include <stdlib.h>

#define GRIDSIZE 20

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Invalid amount of arguments.\n");
        return 1;
    }

    char *gridPath = "grid.txt";
    if(argc == 2)
        gridPath = argv[1];
    
    FILE *gridf = fopen(gridPath, "r");
    if(gridf == NULL)
    {
        printf("couldn't open file %s\n", gridPath);
        return 2;
    }

    int gridarr[GRIDSIZE][GRIDSIZE];
    char c;
    int row = 0, col = 0;
    int num = 0;

    // Importing grid from file
    while((c = getc(gridf)) != EOF)
    {
        if(c == ' ' || c == '\n')
        {
            gridarr[row][col] = num;
            num = 0;
            col++;
        }
        if(c == '\n')
        {
            row++;
            col = 0;
        }
        if (c >= '0' && c <= '9')
            num = num*10 + (c - '0'); 
    }

    int max_product = 0; 
    int product = 0;

    // finding the max product
    for (int i = 0; i < GRIDSIZE-3; i++)
    {
        for(int j = 0; j < GRIDSIZE; j++)
        {
            if (j+3 < GRIDSIZE)
            {
                product = gridarr[i][j];
                product *= gridarr[i+1][j+1];
                product *= gridarr[i+2][j+2];
                product *= gridarr[i+3][j+3];

                if(product > max_product)
                    max_product = product;
            }
            if (j-3 >= 0)
            {
                product = gridarr[i][j];
                product *= gridarr[i+1][j-1];
                product *= gridarr[i+2][j-2];
                product *= gridarr[i+3][j-3];

                if(product > max_product)
                    max_product = product;
            }  
        }
    }

    printf("%d\n", max_product);

    fclose(gridf);
    return 0;
}