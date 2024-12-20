#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double price_small, price_medium, price_large;
    int quantity_small, quantity_medium, quantity_large;
    double tax_small = 14.0100, tax_medium = 14.0200, tax_large = 14.0300;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &price_small);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &price_medium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &price_large);
    
    printf("Shirt Store Price\n");
    printf("=================\n");
    scanf("SMALL  :%lf", &price_small);
    scanf("MEDIUM :%lf", &price_medium);
    scanf("LARGE  :%lf", &price_large);

    printf("\nPetty's Shirt Size Is 'S'\n");
    printf("Number of Shirts CUSTOMER Is Buying: ");
    scanf("%d", &quantity_small);

    printf("\nTommy's Shirt Size Is 'L'\n");
    printf("Number of Shirts CUSTOMER Is Buying: ");
    scanf("%d", &quantity_medium);

    printf("\nSally's Shirt Size Is 'M'\n");
    printf("Number of Shirts CUSTOMER Is Buying: ");
    scanf("%d", &quantity_large);

    double subtotal_small = price_small * quantity_small;
    double subtotal_medium = price_medium * quantity_medium;
    double subtotal_large = price_large * quantity_large;
    double total = subtotal_small + subtotal_medium + subtotal_large;
    double total_tax = (quantity_small * tax_small) + (quantity_medium * tax_medium) + (quantity_large * tax_large);

    printf("\nCustomer Size Price Qty Sub-Total     Tax    Total\n");
    printf("  -------- ---- ----- --- --------- --------- ---------\n");
    printf("  Petty    S    %.2lf %d  %.4lf     %.4lf     %.4lf\n",
        price_small, quantity_small, subtotal_small, (quantity_small * tax_small), (subtotal_small + (quantity_small * tax_small)));

    printf("  Tommy    M    %.2lf %d  %.4lf     %.4lf     %.4lf\n",
        price_medium, quantity_medium, subtotal_medium, (quantity_medium * tax_medium), (subtotal_medium + (quantity_medium * tax_medium)));

    printf("  Sally    L    %.2lf %d  %.4lf     %.4lf     %.4lf\n",
        price_large, quantity_large, subtotal_large, (quantity_large * tax_large), (subtotal_large + (quantity_large * tax_large)));

    printf(" -------- ---- ----- --- --------- --------- ---------\n");
    printf("                         %.4lf     %.4lf     %.4lf\n", total, total_tax, (total + total_tax));

    printf("\nDaily Retail Sales Represented By Coins\n");
    printf("  =======================================\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4lf\n", total);

    int toonies = (int)(total / 2.0);
    double balance = total - toonies * 2.0;
    int loonies = (int)(balance);
    balance -= loonies;
    int quarters = (int)(balance / 0.25);
    balance -= quarters * 0.25;
    int dimes = (int)(balance / 0.1);
    balance -= dimes * 0.1;
    int nickels = (int)(balance / 0.05);
    balance -= nickels * 0.05;
    int pennies = (int)(balance * 100);

    printf("Toonies  %d   %.4lf\n", toonies, balance);
    printf("Loonies  %d   %.4lf\n", loonies, balance);
    printf("Quarters %d   %.4lf\n", quarters, balance);
    printf("Dimes    %d   %.4lf\n", dimes, balance);
    printf("Nickels  %d   %.4lf\n", nickels, balance);
    printf("Pennies  %d   %.4lf\n", pennies, balance);

    printf("\nAverage cost/shirt: %.4lf\n", total / (quantity_small + quantity_medium + quantity_large));

    printf("\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4lf\n", (total + total_tax));

    toonies = (int)((total + total_tax) / 2.0);
    balance = (total + total_tax) - toonies * 2.0;
    loonies = (int)(balance);
    balance -= loonies;
    quarters = (int)(balance / 0.25);
    balance -= quarters * 0.25;
    dimes = (int)(balance / 0.1);
    balance -= dimes * 0.1;
    nickels = (int)(balance / 0.05);
    balance -= nickels * 0.05;
    pennies = (int)(balance * 100);

    printf("Toonies  %d   %.4lf\n", toonies, balance);
    printf("Loonies  %d   %.4lf\n", loonies, balance);
    printf("Quarters %d   %.4lf\n", quarters, balance);
    printf("Dimes    %d   %.4lf\n", dimes, balance);
    printf("Nickels  %d   %.4lf\n", nickels, balance);
    printf("Pennies  %d   %.4lf\n", pennies, balance);

    printf("\nAverage cost/shirt: %.4lf\n", (total + total_tax) / (quantity_small + quantity_medium + quantity_large));

    return 0;
}
