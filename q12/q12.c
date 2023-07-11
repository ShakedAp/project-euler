#include <stdio.h>
#include <math.h>

int countDivisors(int num);

int main()
{
    int triangle_num = 0;

    for(int i = 0; countDivisors(triangle_num) <= 500; triangle_num += ++i);

    printf("%d\n", triangle_num);

    return 0;
}

int countDivisors(int num)
{
    int count = 0;
    for (int i = 1, root = sqrt(num)+1; i < root; i++)
        if(num % i == 0)
            count += 2;

    return count;
}

