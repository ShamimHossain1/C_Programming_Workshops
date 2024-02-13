#include <stdio.h>

int main(void)
{
    char inputChar;
    int inputNum;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+");

    do
    {
        printf("\n\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &inputChar, &inputNum);

        if (inputChar == 'Q' && inputNum != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!");
        }
        else if (inputChar != 'Q' && inputNum != 0)
        {
            if (inputNum > 20 || inputNum < 3)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
            else
            {
                switch (inputChar)
                {
                case 'D':
                    printf("Do-While: ");
                    for (int i = 0; i < inputNum; i++)
                    {
                        printf("D");
                        // Your do-while logic here
                    }
                    break;

                case 'W':
                    printf("While   : ");
                    int i = 0;
                    while (i < inputNum)
                    {
                        printf("W");
                        // Your while logic here
                        i++;
                    }
                    break;

                case 'F':
                    printf("For     : ");
                    for (int i = 0; i < inputNum; i++)
                    {
                        printf("F");
                        // Your for loop logic here
                    }
                    break;

                default:
                    printf("ERROR: Invalid entered value(s)!");
                }
            }
        }

    } while (inputChar != 'Q' || inputNum != 0);

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}
