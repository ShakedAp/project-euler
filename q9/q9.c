#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define TARGETSUM 1000

/*
    This solution is based on Leonard Eugene Dickson's mehtod to generate Pythagorean triples.
    To find integer solution to x^2 + y^2 = z^2, you need to find positive integers r, s and t such that
    r^2 = 2st. Then x = r + s, y = r + t, z = r + s + t.
    Using this method I find Pythagorean triples, calculates their sum and if it matches the traget sum
    we found the triplet we want. This is faster then just trying to find triplets that match, but I am sure
    there are faster algorithms to implement that, generatign the triplets or their sums.
    But it was nice to read about this subject.
*/

int main()
{
    bool found = false;

    for(int r = 2, square = 2; r <= TARGETSUM/3 && !found; r += 2, square = (r * r) / 2)
        for (int s = 1; s <= sqrt(square) && !found; s++)
            if(square % s == 0)
            {
                int t = square / s;
                if ( (r*3 + s*2 + t*2) == TARGETSUM)
                {
                    int x = r + s;
                    int y = r + t;
                    int z = r + s + t;
                    printf("%d\n", x * y * z);
                    found = true;
                }
    }


    return 0;
}