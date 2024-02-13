/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Shamim Hossain Srabon
Student ID#: 135646230
Email      : shsrabon@myseneca.ca
Section    : NHH

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

    // All variables

    int apples, oranges, pears, tomatoes, cabbages;
    int pickedApples, pickedOranges, pickedPears, pickedTomatoes, pickedCabbages;
    int needMoreApples, needMoreOranges, needMorePears, needMoreTomatoes, needMoreCabbages;
    int totalPickedApples, totalPickedOranges, totalPickedPears, totalPickedTomatoes, totalPickedCabbages;
    int doAnotherShopping;

    do
    {

        // Set Innitail value

        needMoreApples = 0;
        needMoreOranges = 0;
        needMorePears = 0;
        needMoreTomatoes = 0;
        needMoreCabbages = 0;
        totalPickedApples = 0;
        totalPickedOranges = 0;
        totalPickedCabbages = 0;
        totalPickedPears = 0;
        totalPickedTomatoes = 0;

        // Input the quantity need

        printf("Grocery Shopping\n================\n");

        // ------------------------Input Apple-----------------------------

        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apples < 0);

        printf("\n");

        // ----------------------Input oranges------------------------

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);

        printf("\n");

        // ----------------------Input Pears-------------------------

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);

        printf("\n");

        //------------------- Input Tomatoes-----------------------

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);

        printf("\n");

        //----------------- Input cabbages------------------------

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);

        printf("\n");

        // Time to pick the products

        printf("--------------------------\nTime to pick the products!\n--------------------------\n\n");

        // ----------Pick apples---------------------

        if (apples != 0)
        {
            int needApples = apples;

            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickedApples);

                totalPickedApples = totalPickedApples + pickedApples;

                if (pickedApples > needApples)
                {
                    totalPickedApples = totalPickedApples - pickedApples;
                    needMoreApples = apples - totalPickedApples;

                    printf("You picked too many... only %d more APPLE(S) are needed.\n", needMoreApples);
                }
                else if (pickedApples < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                    totalPickedApples = totalPickedApples - pickedApples;
                }
                else
                {
                    needApples = apples - totalPickedApples;
                    if (totalPickedApples != apples)
                    {
                        printf("Looks like we still need some APPLES...\n");
                    }
                }

            } while (totalPickedApples != apples);
            printf("Great, that's the apples done!\n\n");
        }

        // ---------Pick oranges-----------

        if (oranges != 0)
        {
            int needOranges = oranges;

            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedOranges);

                totalPickedOranges = totalPickedOranges + pickedOranges;

                if (pickedOranges > needOranges)
                {
                    totalPickedOranges = totalPickedOranges - pickedOranges;
                    needMoreOranges = oranges - totalPickedOranges;

                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", needMoreOranges);
                }
                else if (pickedOranges < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                    totalPickedOranges = totalPickedOranges - pickedOranges;
                }

                else
                {
                    needOranges = oranges - totalPickedOranges;
                    if (totalPickedOranges != oranges)
                    {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                }

            } while (totalPickedOranges != oranges);
            printf("Great, that's the oranges done!\n\n");
        }

        // ---------------Pick pears---------

        if (pears != 0)
        {
            int needPears = pears;

            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedPears);

                totalPickedPears = totalPickedPears + pickedPears;

                if (pickedPears > needPears)
                {
                    totalPickedPears = totalPickedPears - pickedPears;
                    needMorePears = pears - totalPickedPears;

                    printf("You picked too many... only %d more PEAR(S) are needed.\n", needMorePears);
                }
                else if (pickedPears < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                    totalPickedPears = totalPickedPears - pickedPears;
                }
                // if (pickedPears < needPears)
                else
                {
                    needPears = pears - totalPickedPears;
                    if (totalPickedPears != pears)
                    {
                        printf("Looks like we still need some PEARS...\n");
                    }
                }

            } while (totalPickedPears != pears);
            printf("Great, that's the pears done!\n\n");
        }

        // ----------------Pick tomatoes-------------------

        if (tomatoes != 0)
        {
            int needTomatoes = tomatoes;

            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedTomatoes);

                totalPickedTomatoes = totalPickedTomatoes + pickedTomatoes;

                if (pickedTomatoes > needTomatoes)
                {
                    totalPickedTomatoes = totalPickedTomatoes - pickedTomatoes;
                    needMoreTomatoes = tomatoes - totalPickedTomatoes;

                    printf("You picked too many... only %d more TOMATOE(S) are needed.\n", needMoreTomatoes);
                }
                else if (pickedTomatoes < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                    totalPickedTomatoes = totalPickedTomatoes - pickedTomatoes;
                }
                // if (pickedTomatoes < needTomatoes)
                else
                {
                    needTomatoes = tomatoes - totalPickedTomatoes;
                    if (totalPickedTomatoes != tomatoes)
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                }

            } while (totalPickedTomatoes != tomatoes);
            printf("Great, that's the tomatoes done!\n\n");
        }

        // ----------------Pick cabbages-------------------

        if (cabbages != 0)
        {
            int needCabbages = cabbages;

            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedCabbages);

                totalPickedCabbages = totalPickedCabbages + pickedCabbages;

                if (pickedCabbages > needCabbages)
                {
                    totalPickedCabbages = totalPickedCabbages - pickedCabbages;
                    needMoreCabbages = cabbages - totalPickedCabbages;

                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", needMoreCabbages);
                }
                else if (pickedCabbages < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                    totalPickedCabbages = totalPickedCabbages - pickedCabbages;
                }
                // if (pickedCabbages < needCabbages)
                else
                {
                    needCabbages = cabbages - totalPickedCabbages;
                    if (totalPickedCabbages != cabbages)
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                }

            } while (totalPickedCabbages != cabbages);
            printf("Great, that's the cabbages done!\n\n");
        }

        // Ask if user wants to do another shopping

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &doAnotherShopping);

        printf("\n");

    } while (doAnotherShopping != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}