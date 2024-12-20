/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : ILHYUN CHO
Student ID#: 116342221
Email      : icho8@myseneca.ca
Section    : ZCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int number;
    char iteration;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &iteration, &number);

        switch (iteration)
        {

        case 'D':
            if (number >= 3 && number < 21)
            {
                printf("DO-WHILE: ");
                do
                {
                    printf("D");
                    number--;
                } while (number > 0);
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            break;

        case 'W':
            if (number >= 3 && number < 21)
            {
                    printf("WHILE   : ");
                do
                {
                    printf("W");
                    number--;
                } while (number > 0);
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            break;

        case 'F':
            if (number >= 3 && number < 21)
            {
                    printf("FOR     : ");
                do
                {
                    printf("F");
                    number--;
                } while (number > 0);
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            break;

        case 'Q':
            if (number != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            }
            break;

        default: printf("ERROR: Invalid entered value(s)!\n\n");
            break;
        }
    } while (!(iteration == 'Q' && number == 0));

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}