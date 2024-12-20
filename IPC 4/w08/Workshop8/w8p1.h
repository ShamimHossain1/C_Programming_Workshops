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


// ----------------------------------------------------------------------------
#define PRODUCT_MAX 3
#define GRAM_MAX 64

// structures
struct CatFoodInfo
{
    int skuNum;
    double prodPrice;
    int calories;
    double prodLbs;
};



// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptrInt);

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

// 7. Logic entry point
void start(void);
