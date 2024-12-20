#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int apples, oranges, pears, tomatoes, cabbages;

    // Initialize quantities to 0


    int continueShopping = 1;

    while (continueShopping)
    {
        // Input phase
        printf("Grocery Shopping\n");
        printf("================");

        printf("\nHow many APPLES do you need? : ");
        scanf("%d", &apples);
        while (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
        }

        printf("\nHow many ORANGES do you need? : ");
        scanf("%d", &oranges);
        while (oranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
        }

        printf("\nHow many PEARS do you need? : ");
        scanf("%d", &pears);
        while (pears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
        }

        printf("\nHow many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        while (tomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
        }

        printf("\nHow many CABBAGES do you need? : ");
        scanf("%d", &cabbages);
        while (cabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
        }

        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        // Picking phase
        if (apples > 0)
        {
            int pickedapples;
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &pickedapples);


            while (pickedapples > apples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickedapples);

            }
            while (pickedapples < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickedapples);

            }
            while (pickedapples < apples)
            {
                printf("Looks like we still need some APPLES...\n");
                apples = apples - pickedapples;
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickedapples);
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickedapples);
                if (pickedapples == apples)
                {
                    printf("Great, that's the apples done!\n\n");

                }

            }

        }


        if (pears > 0)
        {
            int pickedpears;
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pickedpears);


            while (pickedpears > pears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedpears);

            }
            while (pickedpears < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedpears);

            }
            while (pickedpears < pears)
            {
                printf("Looks like we still need some PEARS...\n");
                pears = pears - pickedpears;
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedpears);
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedpears);
                if (pickedpears == pears)
                {
                    printf("Great, that's the pears done!\n\n");

                }

            }

        }
        if (oranges > 0)
        {
            int pickedoranges;
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &pickedoranges);


            while (pickedoranges > oranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedoranges);

            }
            while (pickedoranges < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedoranges);

            }
            while (pickedoranges < oranges)
            {
                printf("Looks like we still need some ORANGES...\n");
                oranges = oranges - pickedoranges;
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedoranges);
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedoranges);
                if (pickedoranges == oranges)
                {
                    printf("Great, that's the oranges done!\n\n");

                }

            }

        }


        if (tomatoes > 0)
        {
            int pickedtomatoes;
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &pickedtomatoes);


            while (pickedtomatoes > tomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedtomatoes);

            }
            while (pickedtomatoes < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedtomatoes);

            }
            while (pickedtomatoes < tomatoes)
            {
                printf("Looks like we still need some TOMATOES...\n");
                tomatoes = tomatoes - pickedtomatoes;
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedtomatoes);
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedtomatoes);
                if (pickedtomatoes == tomatoes)
                {
                    printf("Great, that's the tomatoes done!\n\n");

                }

            }

        }



        if (cabbages > 0)
        {
            int pickedcabbages;
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &pickedcabbages);


            while (pickedcabbages > cabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedcabbages);

            }
            while (pickedcabbages < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedcabbages);

            }
            while (pickedcabbages < cabbages)
            {
                printf("Looks like we still need some CABBAGES...\n");
                cabbages = cabbages - pickedcabbages;
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedcabbages);
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedcabbages);
                if (pickedcabbages == cabbages)
                {
                    printf("Great, that's the cabbages done!\n\n");

                }

            }

        }












        // Check if all items are picked


        if (apples == 0 && oranges == 0 && pears == 0 && tomatoes == 0 && cabbages == 0)
        {
            printf("All the items are picked!\n");
            printf("\nDo another shopping? (0=NO): ");
            scanf("%d", &continueShopping);
            printf("\n");
        }
        else
        {
            printf("All the items are picked!\n");
            printf("\nDo another shopping? (0=NO): ");
            scanf("%d", &continueShopping);
            printf("\n");
        }













    }
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}