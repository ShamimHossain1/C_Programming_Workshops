/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double sShirt, mShirt, lShirt;
    int sPrice, mPrice, lPrice;
    int patCount, salCount, tomCount;
    int patSub, patTax, patTtl;
    int salSub, salTax, salTtl;
    int tomSub, tomTax, tomTtl;
    int allSub, allTax, allTtl;
    int toonies, loonies, quarters, dimes, nickels, pennies;
    int bal1, bal2, bal3, bal4, bal5, bal6;
    int averageCost, averageTtlCost;
    int balTtl1, balTtl2, balTtl3, balTtl4, balTtl5, balTtl6;
    int tooniesTtl, looniesTtl, quartersTtl, dimesTtl, nickelsTtl, penniesTtl;


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
    scanf("%d", &patCount);

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomCount);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salCount);

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    patSub = sPrice * patCount; //10776
    patTax = (int)((patSub * TAX) + 0.5);//1401
    patTtl = patSub + patTax;
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, sPrice / 100.0, patCount, patSub / 100.0, patTax / 100.0, patTtl / 100.0);
    salSub = mPrice * salCount; 
    salTax = (int)((salSub * TAX) + 0.5);
    salTtl = salSub + salTax;
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mPrice / 100.0, salCount, salSub / 100.0, salTax / 100.0, salTtl / 100.0);
    tomSub = lPrice * tomCount;
    tomTax = (int)((tomSub * TAX) + 0.5);
    tomTtl = tomSub + tomTax;
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, lPrice / 100.0, tomCount, tomSub / 100.0, tomTax / 100.0, tomTtl / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    allSub = patSub + salSub + tomSub;
    allTax = patTax + salTax + tomTax;
    allTtl = patTtl + salTtl + tomTtl;
    printf("                         %.4lf   %.4lf  %.4lf\n\n", allSub / 100.0, allTax / 100.0, allTtl / 100.0);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (allSub / 100.0));
    toonies = allSub / 200;
    bal1 = allSub % 200;
    printf("Toonies  %3d %9.4lf\n", toonies, bal1 / 100.0);
    loonies = bal1 / 100;
    bal2 = bal1 % 100;
    printf("Loonies  %3d %9.4lf\n", loonies, bal2 / 100.0);
    quarters = bal2 / 25;
    bal3 = bal2 % 25;
    printf("Quarters %3d %9.4lf\n", quarters, bal3 / 100.0);
    dimes = bal3 / 20;
    bal4 = bal3 % 20;
    printf("Dimes    %3d %9.4lf\n", dimes, bal4 / 100.0);
    nickels = bal4 / 5;
    bal5 = bal4 % 5;
    printf("Nickels  %3d %9.4lf\n", nickels, bal5 / 100.0);
    pennies = bal5 / 1;
    bal6 = bal5 % 1;
    printf("Pennies  %3d %9.4lf\n\n", pennies, bal6 / 100.0);

    averageCost = ((allSub * 1000) / (patCount + salCount + tomCount) + 5);
    printf("Average cost/shirt: $%.4lf\n\n", ((averageCost / 100.0) + 0.005) / 1000.0);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (allTtl / 100.0));
    tooniesTtl = allTtl / 200;
    balTtl1 = allTtl % 200;
    printf("Toonies  %3d %9.4lf\n", tooniesTtl, balTtl1 / 100.0);
    looniesTtl = balTtl1 / 100;
    balTtl2 = balTtl1 % 100;
    printf("Loonies  %3d %9.4lf\n", looniesTtl, balTtl2 / 100.0);
    quartersTtl = balTtl2 / 25;
    balTtl3 = balTtl2 % 25;
    printf("Quarters %3d %9.4lf\n", quartersTtl, balTtl3 / 100.0);
    dimesTtl = balTtl3 / 20;
    balTtl4 = balTtl3 % 20;
    printf("Dimes    %3d %9.4lf\n", dimesTtl, balTtl4 / 100.0);
    nickelsTtl = balTtl4 / 5;
    balTtl5 = balTtl4 % 5;
    printf("Nickels  %3d %9.4lf\n", nickelsTtl, balTtl5 / (double)100);
    penniesTtl = balTtl5 / 1;
    balTtl6 = balTtl5 % 1;
    printf("Pennies  %3d %9.4lf\n\n", penniesTtl, (double)balTtl6 / 100.0);

    averageTtlCost = ((allTtl * 1000) / (patCount + salCount + tomCount) + 5);
    printf("Average cost/shirt: $%.4lf\n\n", ((averageTtlCost / 100.0) + 0.005) / 1000.0);

    return 0;
}