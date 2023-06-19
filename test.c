#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ANSWERSIZE 256

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./test <problem_number>\n");
        printf("Example q23/q23 | ./test 23\n");

        return 1;
    }

    // Find problem number
    const int problemNumber = atoi(argv[1]);
    if (problemNumber > 838 || problemNumber < 1)
    {
        printf("Invalid problem number.\n");
        return 1;
    }

    // Get answer input
    char buffer[ANSWERSIZE];
    long double answer;
    int i = 0;
    char c;
    // printf("Enter the solution for problem: ");
    fgets(buffer, ANSWERSIZE, stdin);
    answer = strtold(buffer, 0);
    printf("The answer you entered is: %Lf\n", answer);

    // Open answers file
    const char *answersFilePath = "answers.txt";
    FILE *answersFile = fopen(answersFilePath, "r");
    if (answersFile == NULL)
    {
        printf("Coudln't open file %s\n", answersFilePath);
        return -1;
    }
    
    // Read the answers file until the data
    const char *pattern = "DATA\n";
    int patternLen = strlen(pattern);

    while(i != patternLen && (c = getc(answersFile)) != EOF)
    {
        if(c == pattern[i])
            i++;
        else 
            i = 0;
    }

    if (i != patternLen)
    {
        printf("Couldn't file the data... \n");
        return -1;
    }

    // Read the data
    int solutionNumber;

    while(fscanf(answersFile, "Problem %3d: %[^\n]\n", &solutionNumber, buffer) == 2)
    {
        if (solutionNumber == problemNumber)
        {
            long double value = strtold(buffer, 0);
            printf("The correct answer for problem %d is: %Lf\n", problemNumber, value);
            if (value == answer)
                printf("\n\tCORRECT!\n");
            else
                printf("\n\tIncorrect.\n");

            solutionNumber = -1;
            break;
        }
    }

    if(solutionNumber != -1)
        printf("Coulnd't find a match...\n");

    fclose(answersFile);
    return 0;
}