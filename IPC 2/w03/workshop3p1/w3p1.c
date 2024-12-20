///////////////////////////////////////////////////////////////////////////

                              Reflection
                             Workshop - #3
Full Name  : URVISH CHAUDHARI
Student ID#: 153158225
Email      : urvishchaudhari292@gmail.com/udchaudhari1@myseneca.ca
Section    : NCC

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
///////////////////////////////////////////////////////////////////////////







#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

    int product1ID = 111, product2ID = 222, product3ID = 111;
    double product1Price = 111.49, product2Price = 222.99, product3Price = 334.49;
    char product1Taxed = 'Y', product2Taxed = 'N', product3Taxed = 'N';
    double averagePrice = (product1Price + product2Price + product3Price) / 3.0;
    float testValue = 330.99;


    printf("Product Information\n===================\n");
    printf("Product-1 (ID:%d)\n  Taxed: %c\n  Price: $%.4lf\n\n", product1ID, product1Taxed, product1Price);
    printf("Product-2 (ID:%d)\n  Taxed: %c\n  Price: $%.4lf\n\n", product2ID, product2Taxed, product2Price);
    printf("Product-3 (ID:%d)\n  Taxed: %c\n  Price: $%.4lf\n\n", product3ID, product3Taxed, product3Price);

    printf("The average of all prices is: $%.4lf\n\n", averagePrice);

    printf("About Relational and Logical Expressions!\n========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", product1Taxed == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", product2Taxed == 'N' && product3Taxed == 'N');
    printf("3. Is product 3 less than testValue ($%.2f)? -> %d\n\n", (double)testValue, product3Price < (double)testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", product3Price > (product1Price + product2Price));
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", product1Price >= (product3Price - product2Price), product3Price - product2Price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", product2Price >= averagePrice);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", product1ID != product2ID && product1ID != product3ID);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", product2ID != product1ID && product2ID != product3ID);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", product3ID != product1ID && product3ID != product2ID);

    return 0;
}