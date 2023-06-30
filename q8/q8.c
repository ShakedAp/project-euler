#include <stdio.h>
#include <stdlib.h>

#define NUMBERAMOUNT 13

int main(void)
{
    FILE *numberf = fopen("q8/number.txt", "r");
    if (numberf == NULL)
    {
        printf("Couldn't open number file\n");
        printf("It's path might need to be changed in the source file, q8.c\n");
        return -1;
    }

    char c;
    short numbers[NUMBERAMOUNT] = {0};
    long long int product = 0;

    while((c = getc(numberf)) != EOF && c != '\n')
    {
        long long int current_product = 1;
        for (int i = 0; i < NUMBERAMOUNT; i++)
        {
            if (i < NUMBERAMOUNT-1)
                numbers[i] = numbers[i+1];
            else
                numbers[i] = c - '0';
            current_product *= numbers[i];
            if (current_product > product)
                product = current_product;
        }
        
    }

    printf("%lld\n", product);

    fclose(numberf);
    return 0;
}