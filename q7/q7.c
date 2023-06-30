#include <stdio.h>
#include <stdbool.h>

#define PRIMEAMOUNT 10001


bool isprime(int);

int main()
{
    long int i = 1;
    int count;
    for(count = 0; count < PRIMEAMOUNT; i++)
        if (isprime(i))
            count++;
    i--; // The loop increments i one more time after the count reached it's limit

    printf("%ld\n", i);

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