#include <stdio.h>
#include <stdbool.h>

#define LIMITNUM 2000000

bool isprime(int);

int main()
{

    long int sum = 0;
    for (int i = 0; i < LIMITNUM; i++)
    {
        if (isprime(i))
            sum += i;
    }

    printf("%ld\n", sum);
    return 0;
}


// simple primality check test
bool isprime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}