/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : ilhyun cho
Student ID#: 116342221
Email      : icho8@myseneca.ca 
Section    : ZCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double sShirt, mShirt, lShirt;
    int sPrice, mPrice, lPrice, ttPrice, tax, total;
    int count;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &sShirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mShirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &lShirt);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    sPrice = (int)((sShirt + 0.005) * 100);
    printf("SMALL  : $%.2lf\n", sPrice / 100.0);
    mPrice = (int)((mShirt + 0.005) * 100);
    printf("MEDIUM : $%.2lf\n", mPrice / 100.0);
    lPrice = (int)((lShirt + 0.005) * 100);
    printf("LARGE  : $%.2lf\n\n", lPrice / 100.0);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &count);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", count);
    ttPrice = (sPrice * count);
    printf("Sub-total: $%8.4lf\n", ttPrice / 100.0);
    tax = (int)((ttPrice * TAX) + 0.5);
    printf("Taxes    : $%8.4lf\n", tax / 100.0);
    total = ttPrice + tax;
    printf("Total    : $%8.4lf\n\n", total / 100.0);

    return 0;
}