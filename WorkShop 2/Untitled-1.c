



#include <stdio.h>

int main() {
    // Step 3: Create variables for shirt prices
    int Ssize = 1796;
    int Msize = 2696;
    int Lsize = 3597;

    // Step 4: Display the shirt price list

    printf("Enter the price for a SMALL shirt: $%.2lf\n", Ssize / 100.0);
    printf("Enter the price for a MEDIUM shirt: $%.2lf\n", Msize / 100.0);
    printf("Enter the price for a LARGE shirt: $%.2lf\n", Lsize / 100.0);

    printf("\n\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", Ssize / 100.0);
    printf("MEDIUM : $%.2lf\n", Msize / 100.0);
    printf("LARGE  : $%.2lf\n\n", Lsize / 100.0);

    // Step 5: Manual rounding for integral types
    // Patty's shirt size and number of shirts
    char patSize = 'S';
    int numShirts = 8;

    // Step 6: Calculate sub-total
    int subTotal = 0;
    switch (patSize) {
        case 'S':
            subTotal = Ssize * numShirts;
            break;
        case 'M':
            subTotal = Msize * numShirts;
            break;
        case 'L':
            subTotal = Lsize * numShirts;
            break;
        default:
            printf("Invalid shirt size.\n");
            return 1;
    }

    // Step 7: Calculate taxes
    double TAX = 0.13;
    int taxes = (int)(subTotal * TAX);

    // Step 8: Calculate total
    int total = subTotal + taxes;

    // Step 9: Display shopping cart details
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: %d\n", numShirts);
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numShirts);
    printf("Sub-total: $%8.4lf\n", subTotal / 100.0);
    printf("Taxes    : $%8.4lf\n", taxes / 100.0);
    printf("Total    : $%8.4lf\n", total / 100.0);

    return 0;
}
