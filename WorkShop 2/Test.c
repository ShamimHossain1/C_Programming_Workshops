#include <stdio.h>

int main() {
    // Set Shirt Prices
    double smallPrice, mediumPrice, largePrice;
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largePrice);

    // Shirt Store Price List
    printf("\nShirt Store Price List\n======================\n");
    printf(" SMALL : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", mediumPrice);
    printf(" LARGE : $%.2lf\n\n", largePrice);

    // Customer Details
    printf("Patty's shirt size is 'S'\nNumber of shirts Patty is buying: 6\n");
    printf("Tommy's shirt size is 'L'\nNumber of shirts Tommy is buying: 3\n");
    printf("Sally's shirt size is 'M'\nNumber of shirts Sally is buying: 4\n\n");

    // Sales Data
    printf("Customer  Size  Price  Qty  Sub-Total               Tax            Total\n");
    printf("------------ ----- -------- ---   ------------ ------------  -----------\n");
    printf("Patty            S       %.2lf       6      %.4lf       %.4lf    %.4lf\n", smallPrice, 6 * smallPrice, 0.13 * 6 * smallPrice, 6 * smallPrice + 0.13 * 6 * smallPrice);
    printf("Sally             M      %.2lf     4       %.4lf      %.4lf   %.4lf\n", mediumPrice, 4 * mediumPrice, 0.13 * 4 * mediumPrice, 4 * mediumPrice + 0.13 * 4 * mediumPrice);
    printf("Tommy        L       %.2lf     3       %.4lf        %.4lf  %.4lf\n", largePrice, 3 * largePrice, 0.13 * 3 * largePrice, 3 * largePrice + 0.13 * 3 * largePrice);
    printf("----------- ------  -------- ---    ------------- ------------ ------------\n");
    printf("%49.4lf %12.4lf %12.4lf\n\n", 6 * smallPrice + 4 * mediumPrice + 3 * largePrice, 0.13 * (6 * smallPrice + 4 * mediumPrice + 3 * largePrice), 6 * smallPrice + 4 * mediumPrice + 3 * largePrice + 0.13 * (6 * smallPrice + 4 * mediumPrice + 3 * largePrice));

    // Daily retail sales represented by coins (EXCLUDING tax)
    printf("Daily retail sales represented by coins\n=======================================\n");
    double balanceExcludingTax = 6 * smallPrice + 4 * mediumPrice + 3 * largePrice;
    printf("%-10s %-4s %-12s\n", "Coin", "Qty", "Balance");
    printf("%-10s %-4s %-12.4lf\n", "------", "----", balanceExcludingTax);
    
    // Calculate coins
    int toonies = balanceExcludingTax / 2;
    balanceExcludingTax -= toonies * 2;
    int loonies = balanceExcludingTax / 1;
    balanceExcludingTax -= loonies * 1;
    int quarters = balanceExcludingTax / 0.25;
    balanceExcludingTax -= quarters * 0.25;
    int dimes = balanceExcludingTax / 0.1;
    balanceExcludingTax -= dimes * 0.1;
    int nickels = balanceExcludingTax / 0.05;
    balanceExcludingTax -= nickels * 0.05;
    int pennies = balanceExcludingTax / 0.01;

    // Display coin quantities and balances
    printf("%-10s %-4d %-12.4lf\n", "Toonies", toonies, balanceExcludingTax);
    printf("%-10s %-4d %-12.4lf\n", "Loonies", loonies, balanceExcludingTax);
    printf("%-10s %-4d %-12.4lf\n", "Quarters", quarters, balanceExcludingTax);
    printf("%-10s %-4d %-12.4lf\n", "Dimes", dimes, balanceExcludingTax);
    printf("%-10s %-4d %-12.4lf\n", "Nickels", nickels, balanceExcludingTax);
    printf("%-10s %-4d %-12.4lf\n", "Pennies", pennies, balanceExcludingTax);

    // Average cost per shirt (EXCLUDING tax)
    double averageCostExcludingTax = (6 * smallPrice + 4 * mediumPrice + 3 * largePrice) / 13.0;
    printf("\nAverage cost/shirt: $%.4lf\n\n", averageCostExcludingTax);

      // Daily retail sales represented by coins (INCLUDING tax)
    printf("Daily retail sales represented by coins (INCLUDING tax)\n=====================================================\n");
    double IncludingTax = 6 * smallPrice + 4 * mediumPrice + 3 * largePrice + 0.13 * (6 * smallPrice + 4 * mediumPrice + 3 * largePrice);
    printf("%-10s %-4s %-12s\n", "Coin", "Qty", "Balance");
    printf("%-10s %-4s %-12.4lf\n", "------", "----", IncludingTax);

    // Calculate coins
    toonies = IncludingTax / 2;
    IncludingTax -= toonies * 2;
    loonies = IncludingTax / 1;
    IncludingTax -= loonies * 1;
    quarters = IncludingTax / 0.25;
    IncludingTax -= quarters * 0.25;
    dimes = IncludingTax / 0.1;
    IncludingTax -= dimes * 0.1;
    nickels = IncludingTax / 0.05;
    IncludingTax -= nickels * 0.05;
    pennies = IncludingTax / 0.01;

    // Display coin quantities and balances (INCLUDING tax)
    printf("%-10s %-4d %-12.4lf\n", "Toonies", toonies, toonies * 2.0);
    printf("%-10s %-4d %-12.4lf\n", "Loonies", loonies, loonies * 1.0);
    printf("%-10s %-4d %-12.4lf\n", "Quarters", quarters, quarters * 0.25);
    printf("%-10s %-4d %-12.4lf\n", "Dimes", dimes, dimes * 0.1);
    printf("%-10s %-4d %-12.4lf\n", "Nickels", nickels, nickels * 0.05);
    printf("%-10s %-4d %-12.4lf\n", "Pennies", pennies, pennies * 0.01);

    // Average cost per shirt (INCLUDING tax)
    double averageCostIncludingTax = (6 * smallPrice + 4 * mediumPrice + 3 * largePrice + 0.13 * (6 * smallPrice + 4 * mediumPrice + 3 * largePrice)) / 13.0;
    printf("\nAverage cost/shirt (INCLUDING tax): $%.4lf\n\n", averageCostIncludingTax);

    return 0;
}
