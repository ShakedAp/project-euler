#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAXNUM 10

int main()
{
    int amount[MAXNUM-1]; // val = i+2
    for(int i = 0; i < MAXNUM -1; amount[i++] = 1);

    for(int i = MAXNUM-2, val = MAXNUM; i >= 0; val = (--i) + 2)
    {
        for(int j = 0, jval = 2, root = sqrt(i) + 1; j < root; jval = (++j) + 2)
        {
            if(val % jval == 0)
            {
                amount[j] += 1;
                amount[(int) (val/jval) - 2] += 1;
                amount[i] -= 1;
                break;
            }
        }
        if(val == 7)
            break;
    }

    for(int i = 0; i < MAXNUM-1; i++)
    {
        printf("%d %d\n", i+2, amount[i]);
    }

    return 0;
}