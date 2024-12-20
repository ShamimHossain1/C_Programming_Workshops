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


// ----------------------------------------------------------------------------
#define PRODUCT_MAX 3
#define GRAM_MAX 64
#define POUNDT0KG 2.20462

// structures
struct CatFoodInfo
{
    int skuNum;
    double prodPrice;
    int calories;
    double prodLbs;
};

struct ReportData
{
    int skuNum;
    double prodPrice;
    int calories;
    double prodLbs;
    double prodKg;
    int prodG;
    double totalServ;
    double costPerServ;
    double costCalPerServ;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* ptrInt);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* ptrDbl);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int prodNum);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int prodDetail);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNum, const double* prodPrice, const double* prodLbs, const int calories);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* ptrLbs, double* ptrKg);

// 9. convert lbs: g
double convertLbsG(const double* ptrLbs, int* ptrG);

// 10. convert lbs: kg / g
void convertLbs(const double* ptrLbs, double* ptrKg, int* ptrG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servSizeG, const int totalG, double* numOfServ);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServ, double* costPerServ);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCal, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cfi);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rd, const int prodOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cfi);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);