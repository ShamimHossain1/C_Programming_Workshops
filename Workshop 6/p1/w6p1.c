/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P1)
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

int main()
{
	// <---------- Variables --------------->

	double monthlyIncome, totalCost = 0.0;
	int numItems;

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

	for (int i = 0; i < numItems; ++i)
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
	

	for (int i = 0; i < numItems; ++i)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOption[i], cost[i]);
		totalCost += cost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);

	printf("Best of luck in all your future endeavors!\n");

	return 0;
}

/*
	HELPER: printf formatting statements....
	=========================================

	Step #7:
		printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");

		printf("%3d  %5d    %5c    %11.2lf\n", ...


	Step #8:
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", ...

*/