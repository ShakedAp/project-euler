#include <stdio.h>

/* 
    This method implements brute force, since there isn't a lot of numbers.
    This method isn't the best by any means, but it gets the job done realtively quickly.
    
    The brute force could be improved, and the whole algorithm by itself could be improved as well.
*/

int collatzSequenceLength(int num);

int main()
{
    int term = 0;
    int highestLength = 0;

    for(int i = 1; i < 1000000; i++)
    {
        int len = collatzSequenceLength(i);
        if (len > highestLength)
        {
            highestLength = len;
            term = i;
        }
    }

    printf("%d\n", term);

    return 0;
}

int collatzSequenceLength(int num)
{
    long int collatzTerm = num;
    int count = 0;

    while(collatzTerm != 1)
    {
        if (collatzTerm % 2 == 0)
            collatzTerm /= 2;
        else
            collatzTerm = collatzTerm*3 + 1;       
        
        count++;
    }

    return count;
}