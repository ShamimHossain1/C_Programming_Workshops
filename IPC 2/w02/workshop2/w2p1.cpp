#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() 
{
    char size;
    double smallPrice, mediumPrice, largePrice;
    int numShirts;

    printf("Set Shirt Price\n");
    printf("===============\n");

    printf("Enter the price for SMALL shirt   :    $ ");
    scanf(" %lf", &smallPrice);

    printf("Enter the price for MEDIUM shirt  :    $ ");
    scanf(" %lf", &mediumPrice);

    printf("Enter the price for LARGE shirt   :    $ ");
    scanf(" %lf", &largePrice);

    printf("\nShirt Store Price List\n");
    printf("========================\n");

    printf("SMALL    :  $ %.2lf\n", smallPrice);
    printf("MEDIUM   :  $ %.2lf\n", mediumPrice);
    printf("LARGE    :  $ %.2lf\n", largePrice);

    printf("\nCUSTOMER's  Shirt  Size  Is  'S'\n");
    printf("Number of Shirts CUSTOMER Is Buying : ");
    scanf(" %d", &numShirts);

    printf("\nCUSTOMER's Shopping Cart\n");
    printf("Contains  :  %d  shirts\n", numShirts);
    printf("Sub-total :  $ %.2lf\n", numShirts * smallPrice);
    printf("Taxes     :  $ 0.0\n");
    printf("Total     :  $ %.2lf\n", numShirts * smallPrice);

    return 0;
}
