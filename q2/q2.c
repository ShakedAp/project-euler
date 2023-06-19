#include <stdio.h>

#define MAXVALUE 4000000

int main()
{
    long int sum = 0;
    long int num1 = 1, num2 = 1;
    long int temp = 0;

    while (num2 < MAXVALUE)
    {
        if(num2 % 2 == 0)
            sum += num2;
        temp = num2;
        num2 += num1;
        num1 = temp;
    }
    
    printf("%li\n", sum);

    return 0;
}