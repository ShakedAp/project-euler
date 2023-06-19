/* Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
   The numbers are stored in numbers.txt
   Shaked Apter 9.6.2023
*/

#include <stdio.h>
#include <stdlib.h>


#define BUFFSIZE 21
#define ANSWER 5537376230

int freadline(FILE* file, char buffer[], int digits);

int main(int argc, char * argv[])
{
    char *filepath = "numbers.txt";

    if(argc == 2)
    {
        filepath = argv[1];
    }
    if(argc > 2)
    {
        printf("Too much arguments.\n");
        return -1;
    }

    FILE *numberf = fopen(filepath, "r");
    if(numberf == NULL)
    {
        printf("Couldn't open file %s\n", filepath);
        return -1;
    }

    char buffer[BUFFSIZE] = {0};
    int length = 0;
    long int sum = 0;

    while((length = freadline(numberf, buffer, 17)) != 0)
        sum += atol(buffer);
    
    while(sum > 9999999999) 
        sum /= 10;


    printf("%ld\n", sum);
}

int freadline(FILE* file, char buff[], int digits)
{
    char c;
    int i = 0;

    while((c = getc(file)) != EOF && c != '\n')
    {
        if (i < digits)
            buff[i++] = c;
    }

    buff[i] = '\0';
    return i;
}
