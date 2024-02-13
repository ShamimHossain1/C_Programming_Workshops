/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name : Shamim Hossain Srabon
Student ID#: 135646230
Email : shsrabon@myseneca.ca
Section : NHH

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    printf("Set Shirt Prices\n================\n");
    double smallPrice, mediumPrice, largePrice;
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largePrice);

    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", mediumPrice);
    printf("LARGE  : $%.2lf\n\n", largePrice);

    int patBuy, tomBuy, salBuy;

    printf("Patty's shirt size is '%c'\nNumber of shirts Patty is buying: ", patSize);
    scanf("%d", &patBuy);
    printf("\nTommy's shirt size is '%c'\nNumber of shirts Tommy is buying: ", tomSize);
    scanf("%d", &tomBuy);
    printf("\nSally's shirt size is '%c'\nNumber of shirts Sally is buying: ", salSize);
    scanf("%d", &salBuy);

    //---------------- Sales Calculations-------------

    printf("\n\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    //--------- Patty----------
    double patTax = (TAX * patBuy * smallPrice) + 0.005;
    double PatroundedTax = ((int)(patTax * 100)) / 100.0;
    double patTotal = (patBuy * smallPrice + TAX * patBuy * smallPrice) + 0.005;
    double PatroundedTotal = ((int)(patTotal * 100)) / 100.0;

    //--------- Sally-----------
    double salTax = (TAX * salBuy * mediumPrice) + 0.005;
    double salroundedTax = ((int)(salTax * 100)) / 100.0;
    double salTotal = (salBuy * mediumPrice + TAX * salBuy * mediumPrice) + 0.005;
    double salroundedTotal = ((int)(salTotal * 100)) / 100.0;

    //---------- Tom-------------
    double tomTax = (TAX * tomBuy * largePrice) + 0.005;
    double tomroundedTax = ((int)(tomTax * 100)) / 100.0;
    double tomTotal = (tomBuy * largePrice + TAX * tomBuy * largePrice) + 0.005;
    double tomroundedTotal = ((int)(tomTotal * 100)) / 100.0;

    // ----------Subtotal------------
    double subTotal = (patBuy * smallPrice + tomBuy * largePrice + salBuy * mediumPrice);

    // ------------Tax------------
    double taxTotal = (tomroundedTax + salroundedTax + PatroundedTax);

    // ------------Total---------
    double Total = (tomroundedTotal + PatroundedTotal + salroundedTotal);

    printf("Patty %4c %8.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallPrice, patBuy, patBuy * smallPrice, PatroundedTax, PatroundedTotal);
    printf("Sally %4c %8.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumPrice, salBuy, salBuy * mediumPrice, salroundedTax, salroundedTotal);
    printf("Tommy %4c %8.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largePrice, tomBuy, tomBuy * largePrice, tomroundedTax, tomroundedTotal);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotal, taxTotal, Total);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    // ------------------cent calculation without tax----------------------------------

    printf("Sales EXCLUDING tax\n");
    double balanceExcludingTax = patBuy * smallPrice + salBuy * mediumPrice + tomBuy * largePrice;
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    // Calculate coins
    int toonies = balanceExcludingTax / 2;
    balanceExcludingTax -= toonies * 2;
    printf("%22.4lf\n", subTotal);
    printf("Toonies %4d %9.4lf\n", toonies, balanceExcludingTax);

    int loonies = balanceExcludingTax / 1;
    balanceExcludingTax -= loonies * 1;
    printf("Loonies %4d %9.4lf\n", loonies, balanceExcludingTax);

    int quarters = balanceExcludingTax / 0.25;
    balanceExcludingTax -= quarters * 0.25;
    printf("Quarters %3d %9.4lf\n", quarters, balanceExcludingTax);

    int dimes = balanceExcludingTax / 0.1;
    balanceExcludingTax -= dimes * 0.1;
    printf("Dimes %6d %9.4lf\n", dimes, balanceExcludingTax);

    int nickels = balanceExcludingTax / 0.05;
    balanceExcludingTax -= nickels * 0.05;
    printf("Nickels %4d %9.4lf\n", nickels, balanceExcludingTax);

    double pennies = balanceExcludingTax / 0.01;
    balanceExcludingTax = (pennies * 0.01) - balanceExcludingTax;
    printf("Pennies %4.0lf %9.4lf\n", pennies, balanceExcludingTax);

    int totalShirtQty = (patBuy + salBuy + tomBuy);

    double averageCostExcludingTax = (patBuy * smallPrice + salBuy * mediumPrice + tomBuy * largePrice) / totalShirtQty;
    printf("\nAverage cost/shirt: $%.4lf\n\n", averageCostExcludingTax);

    // -----------------cent calculation with tax--------------------------

    printf("Sales EXCLUDING tax\n");
    double balanceIncludingTax = (patBuy * smallPrice + salBuy * mediumPrice + tomBuy * largePrice) + taxTotal;
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    // Calculate coins
    toonies = balanceIncludingTax / 2;
    balanceIncludingTax -= toonies * 2;
    printf("%22.4lf\n", Total);
    printf("Toonies %4d %9.4lf\n", toonies, balanceIncludingTax);

    loonies = balanceIncludingTax / 1;
    balanceIncludingTax -= loonies * 1;
    printf("Loonies %4d %9.4lf\n", loonies, balanceIncludingTax);

    quarters = balanceIncludingTax / 0.25;
    balanceIncludingTax -= quarters * 0.25;
    printf("Quarters %3d %9.4lf\n", quarters, balanceIncludingTax);

    dimes = balanceIncludingTax / 0.1;
    balanceIncludingTax -= dimes * 0.1;
    printf("Dimes %6d %9.4lf\n", dimes, balanceIncludingTax);

    nickels = balanceIncludingTax / 0.05;
    balanceIncludingTax -= nickels * 0.05;
    printf("Nickels %4d %9.4lf\n", nickels, balanceIncludingTax);

    pennies = balanceIncludingTax / 0.01;
    balanceIncludingTax = (pennies * 0.01) - balanceIncludingTax;
    printf("Pennies %4.0lf %9.4lf\n", pennies, balanceIncludingTax);

    double averageCostIncludingTax = ((patBuy * smallPrice + salBuy * mediumPrice + tomBuy * largePrice) + taxTotal) / totalShirtQty;
    printf("\nAverage cost/shirt: $%.4lf\n", averageCostIncludingTax);
    return 0;
}