/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Shamim Hossain Srabon
Student ID#: 135646230
Email      : shsrabon@myseneca.ca
Section    : NHH

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int Ssize = 1796;
    int Msize = 2696;
    int Lsize = 3597;
    int shirtNumber = 8;
    const double TAX = 0.13;
    const char patSize = 'S';
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $%.2lf\n", Ssize / 100.0);
    printf("Enter the price for a MEDIUM shirt: $%.2lf\n", Msize / 100.0);
    printf("Enter the price for a LARGE shirt: $%.2lf\n", Lsize / 100.0);
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", Ssize / 100.0);
    printf("MEDIUM : $%.2lf\n", Msize / 100.0);
    printf("LARGE  : $%.2lf\n\n", Lsize / 100.0);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: %d", shirtNumber);

    // Calculations

    int SubTotal = (Ssize * shirtNumber);
    int taxes = (int)(SubTotal * TAX);
    int total = (SubTotal + taxes);

    printf("\n\nPatty's shopping cart...");
    printf("\nContains : %d shirts", shirtNumber);
    printf("\nSub-total: $%8.4lf ", SubTotal / 100.0);
    printf("\nTaxes    : $%8.4lf ", (taxes+1) / 100.0);
    printf("\nTotal    : $%8.4lf ", (total+1) /100.0);

   

    return 0;
}