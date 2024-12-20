/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char cof1Type, cof2Type, cof3Type;
    int cof1Weight, cof2Weight, cof3Weight;
    char cof1Cream, cof2Cream, cof3Cream;

    char cofStrength1, cofStrength2, cofWithCream1, cofWithCream2;
    int dailySer1, dailySer2;



    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    
    printf("Enter the coffee product information being sold today...\n\n");
    
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &cof1Type);
    printf("Bag weight (g): ");
    scanf("%d", &cof1Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cof1Cream);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &cof2Type);
    printf("Bag weight (g): ");
    scanf("%d", &cof2Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cof2Cream);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &cof3Type);
    printf("Bag weight (g): ");
    scanf("%d", &cof3Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cof3Cream);
    printf("\n");

    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (cof1Type == 'L' || 'l'), !(cof1Type == 'M' || 'm'), !(cof1Type == 'R' || 'r'), 
        cof1Weight, cof1Weight / GRAMS_IN_LBS, (cof1Cream == 'Y' || cof1Cream == 'y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", !(cof2Type == 'L' || 'l'), !(cof2Type == 'M' || 'm'), (cof2Type == 'R' || 'r'),
        cof2Weight, cof2Weight / GRAMS_IN_LBS, (cof2Cream == 'Y' || cof2Cream == 'y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", !(cof3Type == 'L' || 'l'), (cof3Type == 'M' || 'm'), !(cof3Type == 'R' || 'r'),
        cof3Weight, cof3Weight / GRAMS_IN_LBS, (cof3Cream == 'Y' || cof3Cream == 'y'));

    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &cofStrength1);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cofWithCream1);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailySer1);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((cofStrength1 == 'l' || cofStrength1 == 'L') && (cof1Type == 'l' || cof1Type == 'L')) || ((cofStrength1 == 'm' || cofStrength1 == 'M') && (cof1Type == 'm' || cof1Type == 'M')) || ((cofStrength1 == 'r' || cofStrength1 == 'R') && (cof1Type == 'r' || cof1Type == 'R')),
        ((1 <= dailySer1 && dailySer1 <= 4) && (0 <= cof1Weight && cof1Weight <= 250)) || ((5 <= dailySer1 && dailySer1 <= 9) && (250 < cof1Weight && cof1Weight <= 500)) || ((dailySer1 >= 10) && (500 < cof1Weight && cof1Weight <= 1000)),
        ((cofWithCream1 == 'y' || cofWithCream1 == 'Y') && (cof1Cream == 'y' || cof1Cream == 'Y')) || ((cofWithCream1 == 'n' || cofWithCream1 == 'N') && (cof1Cream == 'n' || cof1Cream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((cofStrength1 == 'l' || cofStrength1 == 'L') && (cof2Type == 'l' || cof2Type == 'L')) || ((cofStrength1 == 'm' || cofStrength1 == 'M') && (cof2Type == 'm' || cof2Type == 'M')) || ((cofStrength1 == 'r' || cofStrength1 == 'R') && (cof1Type == 'r' || cof1Type == 'R')),
        ((1 <= dailySer1 && dailySer1 <= 4) && (0 <= cof2Weight && cof2Weight <= 250)) || ((5 <= dailySer1 && dailySer1 <= 9) && (250 < cof2Weight && cof2Weight <= 500)) || ((dailySer1 >= 10) && (500 < cof2Weight && cof2Weight <= 1000)),
        ((cofWithCream1 == 'y' || cofWithCream1 == 'Y') && (cof2Cream == 'y' || cof2Cream == 'Y')) || ((cofWithCream1 == 'n' || cofWithCream1 == 'N') && (cof2Cream == 'n' || cof2Cream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((cofStrength1 == 'l' || cofStrength1 == 'L') && (cof3Type == 'l' || cof3Type == 'L')) || ((cofStrength1 == 'm' || cofStrength1 == 'M') && (cof3Type == 'm' || cof3Type == 'M')) || ((cofStrength1 == 'r' || cofStrength1 == 'R') && (cof1Type == 'r' || cof1Type == 'R')),
        ((1 <= dailySer1 && dailySer1 <= 4) && (0 <= cof3Weight && cof3Weight <= 250)) || ((5 <= dailySer1 && dailySer1 <= 9) && (250 < cof3Weight && cof3Weight <= 500)) || ((dailySer1 >= 10) && (500 < cof3Weight && cof3Weight <= 1000)),
        ((cofWithCream1 == 'y' || cofWithCream1 == 'Y') && (cof3Cream == 'y' || cof3Cream == 'Y'))|| ((cofWithCream1 == 'n' || cofWithCream1 == 'N') && (cof3Cream == 'n' || cof3Cream == 'N')));

    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &cofStrength2);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cofWithCream2);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailySer2);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((cofStrength2 == 'l' || cofStrength2 == 'L') && (cof1Type == 'l' || cof1Type == 'L')) || ((cofStrength2 == 'm' || cofStrength2 == 'M') && (cof1Type == 'm' || cof1Type == 'M')) || ((cofStrength2 == 'r' || cofStrength2 == 'R') && (cof1Type == 'r' || cof1Type == 'R')),
        ((1 <= dailySer2 && dailySer2 <= 4) && (0 <= cof1Weight && cof1Weight <= 250)) || ((5 <= dailySer2 && dailySer2 <= 9) && (250 < cof1Weight && cof1Weight <= 500)) || ((dailySer2 >= 10) && (500 < cof1Weight && cof1Weight <= 1000)),
        ((cofWithCream2 == 'y' || cofWithCream2 == 'Y') && (cof1Cream == 'y' || cof1Cream == 'Y')) || ((cofWithCream2 == 'n' || cofWithCream2 == 'N') && (cof1Cream == 'n' || cof1Cream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((cofStrength2 == 'l' || cofStrength2 == 'L') && (cof2Type == 'l' || cof2Type == 'L')) || ((cofStrength2 == 'm' || cofStrength2 == 'M') && (cof2Type == 'm' || cof2Type == 'M')) || ((cofStrength2 == 'r' || cofStrength2 == 'R') && (cof1Type == 'r' || cof1Type == 'R')),
        ((1 <= dailySer2 && dailySer2 <= 4) && (0 <= cof2Weight && cof2Weight <= 250)) || ((5 <= dailySer2 && dailySer2 <= 9) && (250 < cof2Weight && cof2Weight <= 500)) || ((dailySer2 >= 10) && (500 < cof2Weight && cof2Weight <= 1000)),
        ((cofWithCream2 == 'y' || cofWithCream2 == 'Y') && (cof2Cream == 'y' || cof2Cream == 'Y')) || ((cofWithCream2 == 'n' || cofWithCream2 == 'N') && (cof2Cream == 'n' || cof2Cream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((cofStrength2 == 'l' || cofStrength2 == 'L') && (cof3Type == 'l' || cof3Type == 'L')) || ((cofStrength2 == 'm' || cofStrength2 == 'M') && (cof3Type == 'm' || cof3Type == 'M')) || ((cofStrength2 == 'r' || cofStrength2 == 'R') && (cof1Type == 'r' || cof1Type == 'R')),
        ((1 <= dailySer2 && dailySer2 <= 4) && (0 <= cof3Weight && cof3Weight <= 250)) || ((5 <= dailySer2 && dailySer2 <= 9) && (250 < cof3Weight && cof3Weight <= 500)) || ((dailySer2 >= 10) && (500 < cof3Weight && cof3Weight <= 1000)),
        ((cofWithCream2 == 'y' || cofWithCream2 == 'Y') && (cof3Cream == 'y' || cof3Cream == 'Y')) || ((cofWithCream2 == 'n' || cofWithCream2 == 'N') && (cof3Cream == 'n' || cof3Cream == 'N')));

    printf("Hope you found a product that suits your likes!\n\n");


    return 0;
}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",
*/