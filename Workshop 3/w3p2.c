/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    // Variables

    char Cfe1_Type, Cfe2_Type, Cfe3_Type, Cfe1_Cream, Cfe2_Cream, Cfe3_Cream;
    int Cfe1_Weight, Cfe2_Weight, Cfe3_Weight;

    // Customer preference
    char coffeeStrength, coffeeCream;
    int dailyServing;

    // Output

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Cfe1_Type);
    printf("Bag weight (g): ");
    scanf(" %d", &Cfe1_Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cfe1_Cream);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Cfe2_Type);
    printf("Bag weight (g): ");
    scanf(" %d", &Cfe2_Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cfe2_Cream);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Cfe3_Type);
    printf("Bag weight (g): ");
    scanf(" %d", &Cfe3_Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cfe3_Cream);

    // Product data records Table
    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G)  | Lbs   | Cream |\n");
    printf("---+---------------+---------------+----------------|\n");

    // Product 1

    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (Cfe1_Type == 'L' || Cfe1_Type == 'l'), (Cfe1_Type == 'M' || Cfe1_Type == 'm'), (Cfe1_Type == 'R' || Cfe1_Type == 'r'), Cfe1_Weight, Cfe1_Weight / GRAMS_IN_LBS, (Cfe1_Cream == 'Y' || Cfe1_Cream == 'y'));

    // Product 2

    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (Cfe2_Type == 'L' || Cfe2_Type == 'l'), (Cfe2_Type == 'M' || Cfe1_Type == 'm'), (Cfe2_Type == 'R' || Cfe2_Type == 'r'), Cfe2_Weight, Cfe2_Weight / GRAMS_IN_LBS, (Cfe2_Cream == 'Y' || Cfe2_Cream == 'y'));

    // Product 3

    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (Cfe3_Type == 'L' || Cfe3_Type == 'l'), (Cfe3_Type == 'M' || Cfe3_Type == 'm'), (Cfe3_Type == 'R' || Cfe3_Type == 'r'), Cfe3_Weight, Cfe3_Weight / GRAMS_IN_LBS, (Cfe3_Cream == 'Y' || Cfe3_Cream == 'y'));

    // 1st Customer preferences
    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServing);

    // 1st Cutomer Table

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeeStrength == 'l' || coffeeStrength == 'L') && (Cfe1_Type == 'l' || Cfe1_Type == 'L')) || ((coffeeStrength == 'm' || coffeeStrength == 'M') && (Cfe1_Type == 'm' || Cfe1_Type == 'M')) || ((coffeeStrength == 'r' || coffeeStrength == 'R') && (Cfe1_Type == 'r' || Cfe1_Type == 'R')),
           ((1 <= dailyServing && dailyServing <= 4) && (0 <= Cfe1_Weight && Cfe1_Weight <= 250)) || ((5 <= dailyServing && dailyServing <= 9) && (250 < Cfe1_Weight && Cfe1_Weight <= 500)) || ((dailyServing >= 10) && (500 < Cfe1_Weight && Cfe1_Weight <= 1000)),
           ((coffeeCream == 'y' || coffeeCream == 'Y') && (Cfe1_Cream == 'y' || Cfe1_Cream == 'Y')) || ((coffeeCream == 'n' || coffeeCream == 'N') && (Cfe1_Cream == 'n' || Cfe1_Cream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeeStrength == 'l' || coffeeStrength == 'L') && (Cfe2_Type == 'l' || Cfe2_Type == 'L')) || ((coffeeStrength == 'm' || coffeeStrength == 'M') && (Cfe2_Type == 'm' || Cfe2_Type == 'M')) || ((coffeeStrength == 'r' || coffeeStrength == 'R') && (Cfe1_Type == 'r' || Cfe1_Type == 'R')),
           ((1 <= dailyServing && dailyServing <= 4) && (0 <= Cfe2_Weight && Cfe2_Weight <= 250)) || ((5 <= dailyServing && dailyServing <= 9) && (250 < Cfe2_Weight && Cfe2_Weight <= 500)) || ((dailyServing >= 10) && (500 < Cfe2_Weight && Cfe2_Weight <= 1000)),
           ((coffeeCream == 'y' || coffeeCream == 'Y') && (Cfe2_Cream == 'y' || Cfe2_Cream == 'Y')) || ((coffeeCream == 'n' || coffeeCream == 'N') && (Cfe2_Cream == 'n' || Cfe2_Cream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((coffeeStrength == 'l' || coffeeStrength == 'L') && (Cfe3_Type == 'l' || Cfe3_Type == 'L')) || ((coffeeStrength == 'm' || coffeeStrength == 'M') && (Cfe3_Type == 'm' || Cfe3_Type == 'M')) || ((coffeeStrength == 'r' || coffeeStrength == 'R') && (Cfe1_Type == 'r' || Cfe1_Type == 'R')),
           ((1 <= dailyServing && dailyServing <= 4) && (0 <= Cfe3_Weight && Cfe3_Weight <= 250)) || ((5 <= dailyServing && dailyServing <= 9) && (250 < Cfe3_Weight && Cfe3_Weight <= 500)) || ((dailyServing >= 10) && (500 < Cfe3_Weight && Cfe3_Weight <= 1000)),
           ((coffeeCream == 'y' || coffeeCream == 'Y') && (Cfe3_Cream == 'y' || Cfe3_Cream == 'Y')) || ((coffeeCream == 'n' || coffeeCream == 'N') && (Cfe3_Cream == 'n' || Cfe3_Cream == 'N')));

    // Second Customer

    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServing);

    // 2nd Cutomer Table

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeeStrength == 'l' || coffeeStrength == 'L') && (Cfe1_Type == 'l' || Cfe1_Type == 'L')) || ((coffeeStrength == 'm' || coffeeStrength == 'M') && (Cfe1_Type == 'm' || Cfe1_Type == 'M')) || ((coffeeStrength == 'r' || coffeeStrength == 'R') && (Cfe1_Type == 'r' || Cfe1_Type == 'R')),
           ((1 <= dailyServing && dailyServing <= 4) && (0 <= Cfe1_Weight && Cfe1_Weight <= 250)) || ((5 <= dailyServing && dailyServing <= 9) && (250 < Cfe1_Weight && Cfe1_Weight <= 500)) || ((dailyServing >= 10) && (500 < Cfe1_Weight && Cfe1_Weight <= 1000)),
           ((coffeeCream == 'y' || coffeeCream == 'Y') && (Cfe1_Cream == 'y' || Cfe1_Cream == 'Y')) || ((coffeeCream == 'n' || coffeeCream == 'N') && (Cfe1_Cream == 'n' || Cfe1_Cream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeeStrength == 'l' || coffeeStrength == 'L') && (Cfe2_Type == 'l' || Cfe2_Type == 'L')) || ((coffeeStrength == 'm' || coffeeStrength == 'M') && (Cfe2_Type == 'm' || Cfe2_Type == 'M')) || ((coffeeStrength == 'r' || coffeeStrength == 'R') && (Cfe1_Type == 'r' || Cfe1_Type == 'R')),
           ((1 <= dailyServing && dailyServing <= 4) && (0 <= Cfe2_Weight && Cfe2_Weight <= 250)) || ((5 <= dailyServing && dailyServing <= 9) && (250 < Cfe2_Weight && Cfe2_Weight <= 500)) || ((dailyServing >= 10) && (500 < Cfe2_Weight && Cfe2_Weight <= 1000)),
           ((coffeeCream == 'y' || coffeeCream == 'Y') && (Cfe2_Cream == 'y' || Cfe2_Cream == 'Y')) || ((coffeeCream == 'n' || coffeeCream == 'N') && (Cfe2_Cream == 'n' || Cfe2_Cream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((coffeeStrength == 'l' || coffeeStrength == 'L') && (Cfe3_Type == 'l' || Cfe3_Type == 'L')) || ((coffeeStrength == 'm' || coffeeStrength == 'M') && (Cfe3_Type == 'm' || Cfe3_Type == 'M')) || ((coffeeStrength == 'r' || coffeeStrength == 'R') && (Cfe1_Type == 'r' || Cfe1_Type == 'R')),
           ((1 <= dailyServing && dailyServing <= 4) && (0 <= Cfe3_Weight && Cfe3_Weight <= 250)) || ((5 <= dailyServing && dailyServing <= 9) && (250 < Cfe3_Weight && Cfe3_Weight <= 500)) || ((dailyServing >= 10) && (500 < Cfe3_Weight && Cfe3_Weight <= 1000)),
           ((coffeeCream == 'y' || coffeeCream == 'Y') && (Cfe3_Cream == 'y' || Cfe3_Cream == 'Y')) || ((coffeeCream == 'n' || coffeeCream == 'N') && (Cfe3_Cream == 'n' || Cfe3_Cream == 'N')));

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