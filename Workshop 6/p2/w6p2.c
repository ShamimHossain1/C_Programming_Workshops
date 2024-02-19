/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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

#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00
#define MAX_WISH_LIST_ITEMS 10
#define MIN_ITEM_COST 100.00
#define EXIT_OPTION 0
#define ALL_ITEMS_OPTION 1
#define BY_PRIORITY_OPTION 2

int main()
{
    // <---------- Variables --------------->

    double monthlyIncome, totalCost = 0.0;
    int numItems, menuSelection, priorityFilter, i, months, years;

    // <--- Arrays to store wish list details --->

    double cost[MAX_WISH_LIST_ITEMS];
    int priority[MAX_WISH_LIST_ITEMS];
    char financeOption[MAX_WISH_LIST_ITEMS];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    // <--------------- Monthly NET income section-------------->

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyIncome);

        if (monthlyIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_INCOME);
        }
        else if (monthlyIncome > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME);
        }
    } while (monthlyIncome < MIN_INCOME || monthlyIncome > MAX_INCOME);

    printf("\n");

    // <-------------- Number of wish list items section ---------->

    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);

        if (numItems < 1 || numItems > MAX_WISH_LIST_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and %d items.\n\n", MAX_WISH_LIST_ITEMS);
        }
    } while (numItems < 1 || numItems > MAX_WISH_LIST_ITEMS);

    // printf("\n");

    // <--------------- Input wish list item details----------------->

    for (i = 0; i < numItems; ++i)
    {
        printf("\nItem-%d Details:\n", i + 1);

        // <---------- Input item cost  ----------------->

        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < MIN_ITEM_COST)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", MIN_ITEM_COST);
            }
        } while (cost[i] < MIN_ITEM_COST);

        // <---------- Input item Priority ---------------->
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);

        // <-------- Input item Financing option ----------->
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOption[i]);

            if (financeOption[i] != 'y' && financeOption[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (financeOption[i] != 'y' && financeOption[i] != 'n');
    }

    // <----------- Display wish list items in a table ------------->

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < numItems; ++i)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOption[i], cost[i]);
        totalCost += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);


 // <------------------------------ Forecast Section ---------------------------------->


    do
    {

        printf("\nHow do you want to forecast your wish list?\n");
        printf(" %d. All items (no filter)\n", ALL_ITEMS_OPTION);
        printf(" %d. By priority\n", BY_PRIORITY_OPTION);
        printf(" %d. Quit/Exit\n", EXIT_OPTION);
        printf("Selection: ");
        scanf("%d", &menuSelection);

        // <--------------- Menu Selection --------------->

        switch (menuSelection)
        {
        case ALL_ITEMS_OPTION:
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);

            // <--------- Calculate Forecast ------------>

            months = (totalCost / monthlyIncome) + 0.5;
            years = months / 12;
            months %= 12;

            printf("Forecast: %d years, %d months\n", years, months);

            // <--------- Display note if financing options are available ------------>

            int messagePrinted = 0;
            for (i = 0; i < numItems; ++i)
            {

                if (financeOption[i] == 'n' && !messagePrinted)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");

                    messagePrinted = 1;
                }
            }

            printf("====================================================\n");
            break;

        case BY_PRIORITY_OPTION:

            // <--------- priority filter ------------>

            do
            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &priorityFilter);

                if (priorityFilter < 1 || priorityFilter > 3)
                {
                    printf("ERROR: Invalid priority. Please enter a value between 1 and 3.\n");
                }
                else
                {
                }
            } while (priorityFilter < 1 || priorityFilter > 3);

            //<-------- Calculate priority total amount ------------>

            double totalAmount;
            int priorityFinance = 0;
            for (i = 0; i < numItems; i++)
            {
                if (priority[i] == priorityFilter)
                {
                    if (financeOption[i] == 'n')
                    {
                        priorityFinance = 1;
                    }

                    totalAmount += cost[i];
                }
            }

            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", priorityFilter);
            printf("Amount:   $%.2lf\n", totalAmount);

            // <--------- Calculate Forecast ------------>

            months = (totalAmount / monthlyIncome) + 0.5;
            years = months / 12;
            months %= 12;
            printf("Forecast: %d years, %d months\n", years, months);


            // <--------- Display note if financing options are available ------------>

            if (priorityFinance == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");

            break;

        case EXIT_OPTION:
            printf("\nBest of luck in all your future endeavors!\n");
            break;

        default:
            printf("\nERROR: Invalid menu selection.\n");
        }

    } while (menuSelection != EXIT_OPTION);

    return 0;
}
