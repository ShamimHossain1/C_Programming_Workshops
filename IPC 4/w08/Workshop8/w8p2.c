/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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
#include "w8p2.h"

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



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* ptrLbs, double* ptrKg)
{
	double lbsToKg = (*ptrLbs) / POUNDT0KG;
	
	if (ptrKg != NULL)
	{
		*ptrKg = lbsToKg;
	}
	return lbsToKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
double convertLbsG(const double* ptrLbs, int* ptrG)
{
	int lbsToG = ((*ptrLbs) / POUNDT0KG) * 1000;

	if (ptrG != NULL)
	{
		*ptrG = lbsToG;
	}
	return lbsToG;
}

// 10. convert lbs: kg and g
void convertLbs(const double* ptrLbs, double* ptrKg, int* ptrG)
{
	double lbsToKg = (*ptrLbs) / POUNDT0KG;
	int lbsToG = ((*ptrLbs) / POUNDT0KG) * 1000;

	if (ptrKg != NULL && ptrG != NULL)
	{
		*ptrKg = lbsToKg;
		*ptrG = lbsToG;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servSizeG, const int totalG, double* numOfServ)
{
	double serving = (double)totalG / servSizeG;

	if (numOfServ != NULL)
	{
		*numOfServ = serving;
	}

	return serving;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServ, double* costPerServ)
{
	double costPerServing = *price / *totalServ;

	if (costPerServ != NULL)
	{
		*costPerServ = costPerServing;
	}

	return costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCal, double* costPerCal)
{
	double costPerCalorie = *price / *totalCal;
	if (costPerCal != NULL)
	{
		*costPerCal = costPerCalorie;
	}

	return costPerCalorie;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cfi)
{
	struct ReportData rd = { 0 };

	rd.skuNum = cfi.skuNum;
	rd.prodPrice = cfi.prodPrice;
	rd.prodLbs = cfi.prodLbs;
	rd.calories = cfi.calories;

	rd.prodKg = convertLbsKg(&rd.prodLbs, &rd.prodKg);
	rd.prodG = convertLbsG(&rd.prodLbs, &rd.prodG);
	rd.totalServ = calculateServings(GRAM_MAX, rd.prodG, &rd.totalServ);

	double totalCal = rd.calories * rd.totalServ;

	rd.costPerServ= calculateCostPerServing(&rd.prodPrice, &rd.totalServ, &rd.costPerServ);
	rd.costCalPerServ = calculateCostPerCal(&rd.prodPrice, &totalCal, &rd.costCalPerServ);

	return rd;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAM_MAX);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rd, const int prodOption)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.skuNum, rd.prodPrice, rd.prodLbs, rd.prodKg, rd.prodG, rd.calories, rd.totalServ, rd.costPerServ, rd.costCalPerServ);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cfi)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n\n", cfi.skuNum, cfi.prodPrice);

	// Ending line
	printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo cfi[PRODUCT_MAX] = { {0} };
	struct ReportData rd[PRODUCT_MAX] = { {0} };

	int i;
	int cheapest = 0;
	double cheapestPrice = 0.0;

	openingMessage(PRODUCT_MAX);
	for (i = 0; i < PRODUCT_MAX; i++)
	{
		cfi[i] = getCatFoodInfo(i + 1);
	}

	displayCatFoodHeader();

	for (i = 0; i < PRODUCT_MAX; i++)
	{
		displayCatFoodData(cfi[i].skuNum, &cfi[i].prodPrice, &cfi[i].prodLbs, cfi[i].calories);
	}
	printf("\n");

	for (i = 0; i < PRODUCT_MAX; i++)
	{
		rd[i] = calculateReportData(cfi[i]);
	}

	displayReportHeader();

	cheapestPrice = rd[0].prodPrice;
	for (i = 0; i < PRODUCT_MAX; i++)
	{
		if (cheapestPrice > rd[i].costPerServ)
		{
			cheapestPrice = rd[i].costPerServ;
			cheapest = i;
		}
	}
	
	for (i = 0; i < PRODUCT_MAX; i++)
	{
		displayReportData(rd[i], cheapest);
		if (cheapest == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	for (i = 0; i < PRODUCT_MAX; i++)
	{
		if (i == cheapest)
		{
			displayFinalAnalysis(cfi[i]);
		}
	
	}

}