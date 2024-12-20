
/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : ILHYUN CHO
Student ID#: 116342221
Email      : icho8@myseneca.ca
Section    : ZCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages;
    int pickNumber;
    int repeat = 1;

    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (apples < 0);

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (oranges < 0);

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (pears < 0);

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (tomatoes < 0);

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (cabbages < 0);

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        while (apples > 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &pickNumber);
            if (pickNumber > apples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
            }
            else if (pickNumber <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pickNumber < apples)
            {
                printf("Looks like we still need some APPLES...\n");
                apples -= pickNumber;
            }
            else if (pickNumber == apples)
            {
                printf("Great, that's the apples done!\n\n");
                apples = 0;
            }
        }

        while (oranges > 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &pickNumber);
            if (pickNumber > oranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            }
            else if (pickNumber <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pickNumber < oranges)
            {
                printf("Looks like we still need some ORANGES...\n");
                oranges -= pickNumber;
            }
            else if (pickNumber == oranges)
            {
                printf("Great, that's the oranges done!\n\n");
                oranges = 0;
            }
        }

        while (pears > 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pickNumber);
            if (pickNumber > pears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
            }
            else if (pickNumber <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pickNumber < pears)
            {
                printf("Looks like we still need some PEARS...\n");
                pears -= pickNumber;
            }
            else if (pickNumber == pears)
            {
                printf("Great, that's the pears done!\n\n");
                pears = 0;
            }
        }

        while (tomatoes > 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &pickNumber);
            if (pickNumber > tomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
            }
            else if (pickNumber <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pickNumber < tomatoes)
            {
                printf("Looks like we still need some TOMATOES...\n");
                tomatoes -= pickNumber;
            }
            else if (pickNumber == tomatoes)
            {
                printf("Great, that's the tomatoes done!\n\n");
                tomatoes = 0;
            }
        }

        while (cabbages > 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &pickNumber);
            if (pickNumber > cabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
            }
            else if (pickNumber <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pickNumber < cabbages)
            {
                printf("Looks like we still need some CABBAGES...\n");
                cabbages -= pickNumber;
            }
            else if (pickNumber == cabbages)
            {
                printf("Great, that's the cabbages done!\n\n");
                cabbages = 0;
            }
        }

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &repeat);
        printf("\n");
    } while (repeat);

    printf("Your tasks are done for today - enjoy your free time!\n\n");

    return 0;
}