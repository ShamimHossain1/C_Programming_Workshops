#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Constants for income and cost validation
const double MIN_INCOME = 500.00;
const double MAX_INCOME = 400000.00;
const int MAX_ITEMS = 10;
const double MIN_COST = 100.00;

int main() {
    double monthlyIncome;
    int numWishListItems;

    // Prompt for monthly income
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &monthlyIncome);

        if (monthlyIncome < MIN_INCOME) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2f\n", MIN_INCOME);
        }
        else if (monthlyIncome > MAX_INCOME) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2f\n", MAX_INCOME);
        }
    } while (monthlyIncome < MIN_INCOME || monthlyIncome > MAX_INCOME);

    // Prompt for the number of wish list items
    do {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &numWishListItems);

        if (numWishListItems < 1 || numWishListItems > MAX_ITEMS) {
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITEMS);
        }
    } while (numWishListItems < 1 || numWishListItems > MAX_ITEMS);

    // Arrays to store wish list item details
    double costs[10];
    int i, priorities[10];
    char financing[10];

    // Input wish list item details
    for (i = 0; i < numWishListItems; ++i)
    {
        printf("\nItem-%d Details:\n", i + 1);

        // Cost validation
        do {
            printf("   Item cost: $");
            scanf("%lf", &costs[i]);

            if (costs[i] < MIN_COST)
            {
                printf("      ERROR: Cost must be at least $%.2f\n", MIN_COST);
            }
        } while (costs[i] < MIN_COST);

        // Priority validation
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priorities[i]);

            if (priorities[i] < 1 || priorities[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priorities[i] < 1 || priorities[i] > 3);

        // Financing validation
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);

            if (financing[i] != 'y' && financing[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (financing[i] != 'y' && financing[i] != 'n');
    }

    // Display wish list item table
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for ( i = 0; i < numWishListItems; ++i)
    {
        printf("%3d      %d        %c    %11.2f\n", i + 1, priorities[i], financing[i], costs[i]);
    }

    // Calculate and display total cost
    double totalCost = 0.0;
    for (i = 0; i < numWishListItems; ++i)
    {
        totalCost += costs[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2f\n\n", totalCost);

    // Exit message
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
