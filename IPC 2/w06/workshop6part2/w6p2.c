#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


const double MIN_INCOME = 500.00;
const double MAX_INCOME = 400000.00;
const int MAX_ITEMS = 10;
const double MIN_COST = 100.00;

int main(void) {
    double monthlyIncome;
    int numWishListItems;

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


    do {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &numWishListItems);

        if (numWishListItems < 1 || numWishListItems > MAX_ITEMS) {
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITEMS);
        }
    } while (numWishListItems < 1 || numWishListItems > MAX_ITEMS);

    double costs[10];
    int priorities[10];
    char financing[10];
    int i;
 
    for ( i = 0; i < numWishListItems; ++i) {
        printf("\nItem-%d Details:\n", i + 1);

   
        do {
            printf("   Item cost: $");
            scanf("%lf", &costs[i]);

            if (costs[i] < MIN_COST) {
                printf("      ERROR: Cost must be at least $%.2f\n", MIN_COST);
            }
        } while (costs[i] < MIN_COST);

    
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priorities[i]);

            if (priorities[i] < 1 || priorities[i] > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priorities[i] < 1 || priorities[i] > 3);

   
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);

            if (financing[i] != 'y' && financing[i] != 'n') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (financing[i] != 'y' && financing[i] != 'n');
    }

  
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for ( i = 0; i < numWishListItems; ++i) {
        printf("%3d      %d        %c    %11.2f\n", i + 1, priorities[i], financing[i], costs[i]);
    }

  
    double totalCost = 0.0;
    for ( i = 0; i < numWishListItems; ++i) {
        totalCost += costs[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2f\n", totalCost);




    int selection;
    do {
        
        int totalCostInt = (int)totalCost;
        int monthlyIncomeInt = (int)monthlyIncome;
        int months = totalCostInt / monthlyIncomeInt;

        
        int years;
        int remainingMonths = months % 12;
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");

        printf("Selection: ");
        scanf("%d", &selection);

        if (selection == 1) {
            printf("\n====================================================\n");
            printf("Filter:   All items\nAmount:   $%.2f\n", totalCost);
            years = (int)months / 12;
            printf("Forecast: %d years, %d months\n", years, (remainingMonths)+1);
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n");
        }
        else if (selection == 2) {
            int priorityFilter;
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityFilter);

            double filteredAmount = 0.0;

            for ( i = 0; i < numWishListItems; ++i) {
                if (priorities[i] == priorityFilter) {
                    filteredAmount += costs[i];
                }
            }

            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\nAmount:   $%.2f\n", priorityFilter, filteredAmount);
            months = filteredAmount / monthlyIncomeInt;
            years = (int)months / 12;

            printf("Forecast: %d years, %d months\n", years, (months % 12) + 1);
            if (selection != 2 || priorityFilter != 2)
            {
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
        else if (selection == 0) {
            printf("\nBest of luck in all your future endeavours!\n");
        }
        else {
            printf("\nERROR: Invalid menu selection.\n");
        }
    } while (selection != 0);

    return 0;
}