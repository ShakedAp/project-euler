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

    printf("%ld\n", result);
    return 0;
}