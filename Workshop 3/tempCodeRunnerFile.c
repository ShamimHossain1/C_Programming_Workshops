/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Shamim Hossain Srabon
Student ID#: 135646230
Email      : shsrabon@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // Variables

    int productId1 = 111, productId2 = 222, productId3 = 111;
    float productPrice1 = 111.49, productPrice2 = 222.99, productPrice3 = 334.49;
    char productTaxed1 = 'Y', productTaxed2 = 'N', productTaxed3 = 'N';

    float averagePrice = (productPrice1 + productPrice2 + productPrice3) / 3;

    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    //Output

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n Taxed: %c\n Price: $%.4f\n\n", productId1, productTaxed1, productPrice1);
    printf("Product-2 (ID:%d)\n Taxed: %c\n Price: $%.4f\n\n", productId2, productTaxed2, productPrice2);
    printf("Product-3 (ID:%d)\n Taxed: %c\n Price: $%.4f\n\n", productId3, productTaxed3, productPrice3);
