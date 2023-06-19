#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./test <problem_number>\n");
        return 1;
    }

    const int problemNumber = atoi(argv[1]);
    if (problemNumber > 838 || problemNumber < 1)
    {
        printf("Invalid problem number\n");
        return 1;
    }

    const char *answersFilePath = "answers.txt";
    FILE *answersFile = fopen(answersFilePath, "r");
    if (answersFile == NULL)
    {
        printf("Coudln't open file %s\n", answersFilePath);
        return -1;
    }
    
    char c;
    const char *pattern = "DATA\n";
    int i = 0, len = strlen(pattern);
    

    while(i != len && (c = getc(answersFile)) != EOF)
    {
        if(c == pattern[i])
            i++;
        else 
            i = 0;
    }

    if (i != len)
    {
        printf("Couldn't file the data... \n");
        return -1;
    }

    int answerNumber;
    char buffer[100];

    while(fscanf(answersFile, "Problem %3d: %[^\n]\n", &answerNumber, buffer) == 2)
    {
        if (answerNumber == problemNumber)
        {
            long double value = strtold(buffer, 0);
            printf("Problem %i, answer: %Lf\n", answerNumber, value);
            printf("Buffer: %s\n", buffer);
            answerNumber = -1;
            break;
        }
    }

    if(answerNumber != -1)
        printf("Coulnd't find a match...\n");

    fclose(answersFile);
    return 0;
}