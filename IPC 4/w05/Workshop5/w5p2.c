/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int repeat = 0;

    int i;
    int year, month;
    double morningRate, eveningRate;

    double morningCalculate = 0.0, eveningCalculate = 0.0;


    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%4d %2d", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            repeat = 1;
        }

        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
            repeat = 1;
        }

        if (!(year < MIN_YEAR || year > MAX_YEAR) && !(month < JAN || month > DEC))
        {
            repeat = 0;
        }

    } while (repeat);
    repeat = 0;

    printf("\n*** Log date set! ***\n\n");

    for (i = 0; i < LOG_DAYS; i++)
    {
        printf("%4d-", year);
        switch (month)
        {
        case 1:
            printf("JAN");
            break;
        case 2:
            printf("FEB");
            break;
        case 3:
            printf("MAR");
            break;
        case 4:
            printf("APL");
            break;
        case 5:
            printf("MAY");
            break;
        case 6:
            printf("JUN");
            break;
        case 7:
            printf("JUL");
            break;
        case 8:
            printf("AUG");
            break;
        case 9:
            printf("SEP");
            break;
        case 10:
            printf("OCT");
            break;
        case 11:
            printf("NOV");
            break;
        case 12:
            printf("DEC");
            break;
        }
        printf("-%02d", i + 1);
        printf("\n");

        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRate);
            if (morningRate < 0.0 || morningRate > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                repeat = 1;
            }
            else
            {
                morningCalculate += morningRate;
                repeat = 0;
            }
        } while (repeat);
        repeat = 0;

        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRate);
            if (eveningRate < 0.0 || eveningRate > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                repeat = 1;
            }
            else
            {
                eveningCalculate += eveningRate;
                repeat = 0;
            }
        } while (repeat);
        repeat = 0;
        printf("\n");
    }


    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating:%7.3lf\n", morningCalculate);
    printf("Evening total rating:%7.3lf\n", eveningCalculate);
    printf("----------------------------\n");
    printf("Overall total rating:%7.3lf\n\n", morningCalculate + eveningCalculate);

    printf("Average morning rating:%5.1lf\n", morningCalculate / LOG_DAYS);
    printf("Average evening rating:%5.1lf\n", eveningCalculate / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:%5.1lf\n", (morningCalculate + eveningCalculate) / (LOG_DAYS * 2));

    return 0;
}