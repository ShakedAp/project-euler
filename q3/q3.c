#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
This problem has few approaches:
- Find the factors from biggest, and if they are primes they are it.
- Find the prime factors using complex algorithm and return the largest.
- Lookup the prime numbers below the number and find which one is the a factor.
and more...

Some algorithms are more complex than others. But since this number is not that big,
I'll just implement the easiest.
And it is just the simple process of finding primes.

*/

int main()
{
    long int num = 600851475143;
    int largestPrime = 2;
    int root = sqrt(num);

    while (num % 2 == 0)
        num /= 2;

    for (int i = 3; i < root + 1; i += 2)
    {
        if (num % i == 0)
        {
            largestPrime = i;
            num /= i;
        }
    }

    if (num > 2)
        largestPrime = num;

    printf("%d\n", largestPrime);
    return 0;
}