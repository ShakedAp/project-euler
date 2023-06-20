#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main()
{
    int i, j;
    int biggest = 0;

    for(i = 999; i > 99; i--)
        for(j = 999; j > 99; j --)
            if(isPalindrome(i*j) && i*j > biggest)
                biggest = i*j;

    printf("%d\n", biggest);
    return 0;
}

bool isPalindrome( int x)
{
     int num = x;
     int revNum = 0;
    while (num > 0) {
        revNum = revNum * 10 + num % 10;
        num = num / 10;
    }

    return x == revNum;
}