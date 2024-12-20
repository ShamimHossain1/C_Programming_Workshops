#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main() {
    int year, month,day;
    const int JAN = 1;
    const int DEC = 12;
    int logDateSet = 0; 

    printf("General Well-being Log\n");
    printf("======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year < MIN_YEAR || year > MAX_YEAR) && (month < JAN || month > DEC)) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        else if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        else if (month < JAN || month > DEC) {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        else {
            logDateSet = 1; // Set the flag to 1 when log date is successfully set
        }

    } while (!logDateSet);

    // Display log date once, outside the loop
    printf("\n*** Log date set! ***\n");

    /*switch (month) {
    case 1: printf("JAN"); break;
    case 2: printf("FEB"); break;
    case 3: printf("MAR"); break;
    case 4: printf("APR"); break;
    case 5: printf("MAY"); break;
    case 6: printf("JUN"); break;
    case 7: printf("JUL"); break;
    case 8: printf("AUG"); break;
    case 9: printf("SEP"); break;
    case 10: printf("OCT"); break;
    case 11: printf("NOV"); break;
    case 12: printf("DEC"); break;
    }

    printf("-01\n");*/

    // Rest of your code
    double morningTotal = 0.0, eveningTotal = 0.0;

    for ( day = 1; day <= LOG_DAYS; ++day) {
        printf("\n%d-%s-%02d\n", year, (month == 1) ? "JAN" : (month == 2) ? "FEB" : "DEC", day);

        double morningRating;
        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);

            if (morningRating < 0.0 || morningRating > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }

        } while (morningRating < 0.0 || morningRating > 5.0);

        double eveningRating;
        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);

            if (eveningRating < 0.0 || eveningRating > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }

        } while (eveningRating < 0.0 || eveningRating > 5.0);

        morningTotal += morningRating;
        eveningTotal += eveningRating;
    }
    
    

    // Part-3: Display Summary
    printf("\nSummary\n");
      printf("=======\n");
    printf("Morning total rating: %.3lf\n", morningTotal);
    printf("Evening total rating:  %.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morningTotal + eveningTotal);
    printf("Average morning rating:  %.1lf\n", morningTotal / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", eveningTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", (morningTotal + eveningTotal) / (2 * LOG_DAYS));

    return 0;
}
