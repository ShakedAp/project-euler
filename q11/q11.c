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

    for (int i = 0; i < GRIDSIZE; i++)
    {
        for(int j = 0; j < GRIDSIZE; j++)
        {
            printf("%02d ", gridarr[i][j]);
        }
        printf("\n");
    }



    fclose(gridf);
    return 0;
}