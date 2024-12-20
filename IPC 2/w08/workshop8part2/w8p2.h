#pragma once
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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define NUM_OF_GRAMS 64
#define LBS_TO_KG 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
};

struct ReportData
{
    int sku;
    double price;
    int calPerserve;
    double weightLbs;
    double weightKg;
    int weightG;
    double totalServe;
    double costPerserve;
    double costCalperServe;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* integerInput);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* doubleInput);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int maxProducts);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int sequenceNum);

// 5. Display the formatted table header

void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int skuInput, const int caloriesInput,
    const double* priceInput, const double* weightInput);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg

double convertLbsKg(const double* pounds, double* kg);


// 9. convert lbs: g

int convertLbsG(const double* pounds, int* g);


// 10. convert lbs: kg / g

void  convertLbs(const double* pounds, double* kg, int* g);

// 11. calculate: servings based on gPerServ

double calculateServings(const int gPerserve, const int gTotal, double* numOfserving);

// 12. calculate: cost per serving

double calculateCostPerServing(const double* productPrice, const double* totalServings, double* costPerserve);

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* costPercal);

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo tempCatfoodInfo);

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void  displayReportData(const struct ReportData tempCatfoodInfo, const int cheapestOption);

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
