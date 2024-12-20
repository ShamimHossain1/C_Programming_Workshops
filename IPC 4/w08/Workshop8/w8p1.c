/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : ILHYUN CHO
Student ID#: 116342221
Email      : icho8@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* ptrInt)
{
	int input = 0;

	do
	{
		scanf("%d", &input);

		if (input < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else 
		{
			if (ptrInt != NULL)
			{
				*ptrInt = input;
			}
		}
	} while (input < 1);
	
	return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* ptrDbl)
{
	double input = 0.0;

	do
	{
		scanf("%lf", &input);

		if (input <= 0.0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			if (ptrDbl != NULL)
			{
				*ptrDbl = input;
			}
		}
	} while (input <= 0.0);

	return input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int prodNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", PRODUCT_MAX);
	printf("NOTE: A 'serving' is %dg\n\n", GRAM_MAX);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int prodDetail)
{
	struct CatFoodInfo food = { 0 };
	printf("Cat Food Product #%d\n", prodDetail);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.skuNum);
	printf("PRICE         : $");
	getDoublePositive(&food.prodPrice);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.prodLbs);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);
	printf("\n");

	return food;//structure return 
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNum, const double* prodPrice, const double* prodLbs, const int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuNum, *prodPrice, *prodLbs, calories);
}

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo food[PRODUCT_MAX] = { {0} };
	int i;

	openingMessage(PRODUCT_MAX);
	for (i = 0; i < PRODUCT_MAX; i++)
	{
		food[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0; i < PRODUCT_MAX; i++)
	{
		displayCatFoodData(food[i].skuNum, &food[i].prodPrice, &food[i].prodLbs, food[i].calories);
	}


}