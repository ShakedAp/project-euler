#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXNUM 20

// Function to calculate the greatest common divisor (GCD) of two numbers
long int gcd(long int a, long int b) {
    if (b != 0)
        return gcd(b, a % b);
    else
        return a;
}

// Function to calculate the least common multiple (LCM) of two numbers
long int lcm(long int a, long int b) {
    return (a * b) / gcd(a, b);  // A formula from math. 
}

// Function to calculate the LCM of a set of numbers
// The LCM of a set of number is LCM of a number and the result of the previous pair.
int main(void) {
    long int result = 1;
    for (int i = 2; i <= MAXNUM; i++)
        result = lcm(result, i);
    
    printf("%ld\n", result);

    return 0;
}