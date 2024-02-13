/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Shamim Hossain Srabon
Student ID#: 135646230
Email      : shsrabon@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    char inputChar;
    int inputNum, i;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+");

    do

    {
        printf("\n\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &inputChar, &inputNum);
        if (inputChar == 'Q' && inputNum != 0)
            printf("ERROR: To quit, the number of iterations should be 0!");

        if (inputChar != 'Q')
        {

            switch (inputChar)
            {
            case 'D':
                if (inputNum > 20 || inputNum < 3)
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                }
                else
                {
                    printf("Do-While: ");
                    for (i = 0; i < inputNum; i++)
                    {
                        printf("%c", inputChar);
                    }
                }
                break;

            case 'W':
                if (inputNum > 20 || inputNum < 3)
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                }

                else
                {
                    printf("While   : ");
                    for ( i = 0; i < inputNum; i++)
                    {
                        printf("%c", inputChar);
                    }
                }
                break;

            case 'F':
                if (inputNum > 20 || inputNum < 3)
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                }
                else
                {
                    printf("For     : ");
                    for ( i = 0; i < inputNum; i++)
                    {
                        printf("%c", inputChar);
                    }
                }

                break;
            default:
                printf("ERROR: Invalid entered value(s)!");
            }
        }

    } while (inputChar != 'Q' || inputNum != 0);

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}