/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : URVISH DINESHBHAI CHAUDHARI
Student ID#: 153158225
Email      : udchudhari1@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"w8p1.h"

// 1. get user input of int type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num)
{
	int val;
	do {
		scanf("%d", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);
	if (num != NULL)
		*num = val;
	return val;
}
// 2. Get user input of double type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num)
{
	double val;
	do {
		scanf("%lf", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);
	if (num != NULL)
		*num = val;
	return val;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product)
{

	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
}
// 4. Get user input for the details of cat food product
double getCatFoodInfo(int* sku, double* rate, double* weight, int* cal_serve, const int sequence_num)
{
	printf("\n");
	printf("Cat Food Product #%d\n", sequence_num);
	printf("--------------------\n");
	printf("SKU           : ");
	*sku = getIntPositive(NULL);
	printf("PRICE         : $");
	*rate = getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");
	*weight = getDoublePositive(NULL);
	printf("CALORIES/SERV.: ");
	*cal_serve = getIntPositive(NULL);
	return 0;
}
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}
// 6. Display a formatted rescord of cat food data
void displayCatFoodDate(const int sku, const double* price, const double* weight, const int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point

void start()
{

	int i;
	struct CatFoodInfo catFoodData[MAX_PRODUCT] = { {0} };
	openingMessage(MAX_PRODUCT);
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		getCatFoodInfo(&catFoodData[i].sku, &catFoodData[i].product_rate, &catFoodData[i].weight, &catFoodData[i].calories, i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayCatFoodDate(catFoodData[i].sku, &catFoodData[i].product_rate, &catFoodData[i].weight, catFoodData[i].calories);
	}



}
