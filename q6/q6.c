#include <stdio.h>
#include <math.h>

#define MAXNUM 100

int main()
{
    long int sum = 0;
    long int squareSum = 0;

    for(int i = 1; i <= MAXNUM; i++)
    {
        sum += i;
        squareSum += pow(i, 2);
    }

    printf("%ld\n", (long int) (pow(sum, 2) - squareSum));

    return 0;
}