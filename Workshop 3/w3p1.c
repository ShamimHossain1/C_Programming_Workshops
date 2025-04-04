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

    printf("The average of all prices is: $%.4f\n\n", averagePrice);


    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");

    //Relational and Logical Expressions

    printf("1. Is product 1 taxable? -> %d\n\n", productTaxed1 == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", productTaxed2 == 'N' && productTaxed3 == 'N');
    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n", productPrice3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", productPrice3 > productPrice1 + productPrice2);
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? -> %d (price difference: $%.2f)\n\n", productPrice1 >= (productPrice3 - productPrice2), productPrice3 - productPrice2);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", productPrice2 >= averagePrice);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", productId1 != productId2 && productId1 != productId3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", productId2 != productId1 && productId2 != productId3);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", productId3 != productId1 && productId3 != productId2);

    return 0;
}