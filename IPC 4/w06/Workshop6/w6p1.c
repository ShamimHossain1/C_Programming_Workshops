/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : ilhyun cho
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

#define MIN_LIST 1
#define MAX_LIST 10

#define IMPORTANT_MUST 1
#define IMPORTANT_WANT 3

int main(void)
{
    const double min = 500.00;
    const double max = 400000.00;
    const double detailMin = 100.00;

    int i;
    int repeat;
    int items;
    double income;

    double detailCostSum = 0.0;

    double detailCost[MAX_LIST] = { 0.0 };
    int important[MAX_LIST] = { 0 };
    char option[MAX_LIST] = { 0 };


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    do
    {
        repeat = 0;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < min)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", min);
            repeat = 1;
        }
        else if (income > max)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", max);
            repeat = 1;
        }
    } while (repeat);
    printf("\n");

    do
    {
        repeat = 0;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &items);
        if (items < MIN_LIST || items > MAX_LIST)
        {
            printf("ERROR: List is restricted to between %d and %d items.\n\n", MIN_LIST, MAX_LIST);
            repeat = 1;
        }
    } while (repeat);
    printf("\n");

    for (i = 0; i < items; i++)//--------------
    {
        printf("Item-%d Details:\n", i + 1);
        do
        {
            repeat = 0;
            printf("   Item cost: $");
            scanf("%lf", &detailCost[i]);
            if (detailCost[i] < detailMin)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", detailMin);
                repeat = 1;
            }
        } while (repeat);

        do
        {
            repeat = 0;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &important[i]);
            if (important[i] < IMPORTANT_MUST || important[i] > IMPORTANT_WANT)
            {
                printf("      ERROR: Value must be between %d and %d\n", IMPORTANT_MUST, IMPORTANT_WANT);
                repeat = 1;
            }
        } while (repeat);

        do
        {
            repeat = 0;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &option[i]);
            if (option[i] != 'y' && option[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                repeat = 1;
            }
        } while (repeat);
        printf("\n");
    }
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < items; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, important[i], option[i], detailCost[i]);
        detailCostSum += detailCost[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", detailCostSum);

    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}