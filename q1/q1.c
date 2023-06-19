/*
    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23
    Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>

#define MAXNUM 1000

int main()
{

    long int result = 0;

    for(int i = 1; i <= (MAXNUM-1)/3; i++)
        result += 3 * i;
    
    for(int i = 1, k = 5; i <= (MAXNUM-1)/5; i++, k = i * 5)
        if (k % 3 != 0)
            result += k;

    printf("The sum is %ld\n", result);
    return 0;
}


// 5 10
// 3 6 9 12