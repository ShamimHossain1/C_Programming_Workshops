/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
Full Name  : URVISH DINESHBHAI CHAUDHARI
Student ID#: 153158225
Email      : udchaudhari1@myseneca.ca
Section    : NCC

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
int getIntPositive(int* integerInput)
{

	int postvInt = 0;
	int validInput;

	do
	{
		validInput = 1;
		scanf("%d", &postvInt);
		if (postvInt < 1)
		{
			printf("ERROR: Enter a positive value: ");
			validInput = 0;
		}
	} while (validInput == 0);

	if (integerInput != NULL)
	{
		*integerInput = postvInt;
	}

	return postvInt;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)



double getDoublePositive(double* doubleInput)
{
	double postvDouble = 0;
	int validInput;

	do
	{
		validInput = 1;

		scanf("%lf", &postvDouble);
		if (postvDouble < 1)
		{
			printf("ERROR: Enter a positive value: ");
			validInput = 0;
		}
	} while (validInput == 0);

	if (doubleInput != NULL)
	{
		*doubleInput = postvDouble;
	}

	return postvDouble;
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int maxProducts)
{

	printf("Cat Food Cost Analysis\n"
		"======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n"
		"NOTE: A 'serving' is %dg\n\n", maxProducts, NUM_OF_GRAMS);

}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int sequenceNum)
{
	struct CatFoodInfo inputCatfood;

	printf("Cat Food Product #%d\n", (sequenceNum + 1));
	printf("--------------------\n");

	printf("SKU           : ");
	inputCatfood.sku = getIntPositive(NULL);

	printf("PRICE         : $");
	inputCatfood.price = getDoublePositive(NULL);

	printf("WEIGHT (LBS)  : ");
	inputCatfood.weight = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	inputCatfood.calories = getIntPositive(NULL);

	printf("\n");

	return inputCatfood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int skuInput, const int caloriesInput,
	const double* priceInput, const double* weightInput)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuInput, *priceInput, *weightInput, caloriesInput);

}

// ----------------------------------------------------------------------------
// PART-2


// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* pounds, double* kg)
{
	double poundTokg;
	poundTokg = *pounds / LBS_TO_KG;
	if (kg != NULL)
	{
		*kg = poundTokg;
	}
	return poundTokg;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* pounds, int* g)
{
	double poundTokg;
	int kgToG;
	poundTokg = convertLbsKg(pounds, &poundTokg);
	kgToG = (int)(poundTokg * 1000);
	if (g != NULL)
	{
		*g = kgToG;
	}
	return kgToG;
}

// 10. convert lbs: kg and g

void  convertLbs(const double* pounds, double* kg, int* g)
{
	convertLbsKg(pounds, kg);
	convertLbsG(pounds, g);
}
// 11. calculate: servings based on gPerServ

double calculateServings(const int gPerserve, const int gTotal, double* numOfserving)
{
	double totalServings;
	totalServings = (double)gTotal / gPerserve;
	if (numOfserving != NULL)
	{
		*numOfserving = totalServings;
	}

	return totalServings;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double* productPrice, const double* totalServings, double* costPerserve)
{
	double eachServeprice;
	eachServeprice = *productPrice / *totalServings;
	if (costPerserve != NULL)
	{
		*costPerserve = eachServeprice;
	}
	return eachServeprice;
}

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* costPercal)
{
	double priceOfcal;
	priceOfcal = *productPrice / *totalCalories;
	if (costPercal != NULL)
	{
		*costPercal = priceOfcal;
	}

	return priceOfcal;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo tempCatfoodInfo)
{
	double totalCalories;
	struct ReportData catFooddata;

	catFooddata.sku = tempCatfoodInfo.sku;
	catFooddata.price = tempCatfoodInfo.price;
	catFooddata.calPerserve = tempCatfoodInfo.calories;
	catFooddata.weightLbs = tempCatfoodInfo.weight;

	catFooddata.weightKg = convertLbsKg(&catFooddata.weightLbs,
		&catFooddata.weightKg);

	catFooddata.weightG = convertLbsG(&catFooddata.weightLbs,
		&catFooddata.weightG);

	catFooddata.totalServe = calculateServings(NUM_OF_GRAMS,
		catFooddata.weightG, &catFooddata.totalServe);

	catFooddata.costPerserve = calculateCostPerServing(&catFooddata.price,
		&catFooddata.totalServe, &catFooddata.costPerserve);

	totalCalories = catFooddata.calPerserve * catFooddata.totalServe;

	catFooddata.costCalperServe = calculateCostPerCal(&catFooddata.price,
		&totalCalories, &catFooddata.costCalperServe);

	return catFooddata;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_OF_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void  displayReportData(const struct ReportData tempCatfoodInfo, const int cheapestOption)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		tempCatfoodInfo.sku,
		tempCatfoodInfo.price,
		tempCatfoodInfo.weightLbs,
		tempCatfoodInfo.weightKg,
		tempCatfoodInfo.weightG,
		tempCatfoodInfo.calPerserve,
		tempCatfoodInfo.totalServe,
		tempCatfoodInfo.costPerserve,
		tempCatfoodInfo.costCalperServe);

	if (cheapestOption != 0)
	{
		printf(" ***");
	}
	
}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct)
{
	printf("Final Analysis\n"
		"--------------\n"
		"Based on the comparison data, the PURRR-fect economical option is:\n"
		"SKU:00%d Price: $%.2lf\n\n"
		"Happy shopping!\n", cheapestProduct.sku, cheapestProduct.price);
}
// ----------------------------------------------------------------------------


// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFood[MAX_PRODUCTS] = { {0} };
	struct ReportData catFooddata[MAX_PRODUCTS] = { {0} };
	int cheapestProduct, cheapestOption = 0, i;

	openingMessage(MAX_PRODUCTS);

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		catFood[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(catFood[i].sku, catFood[i].calories,
			&catFood[i].price, &catFood[i].weight);

		catFooddata[i] = calculateReportData(catFood[i]);
	}

	cheapestProduct = 0; // Initialize with the first product
	for (i = 1; i < MAX_PRODUCTS; i++) {
		if (catFooddata[i].costPerserve < catFooddata[cheapestProduct].costPerserve) {
			cheapestProduct = i; // Update cheapestProduct if the current one is cheaper
		}
	}

	printf("\n");
	displayReportHeader(); // Report Header

	for (i = 0; i < MAX_PRODUCTS; i++) {
		cheapestOption = (i == cheapestProduct) ? 1 : 0; // Set cheapestOption based on the current product
		displayReportData(catFooddata[i], cheapestOption); // Display Report Data
		printf("\n");
	}

	printf("\n");
	displayFinalAnalysis(catFood[cheapestProduct]); // Display the findings (cheapest)
}