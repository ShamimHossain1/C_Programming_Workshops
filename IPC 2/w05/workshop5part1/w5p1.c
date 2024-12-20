#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022


int main() {
    int year, month;
    const int JAN = 1;
    const int DEC = 12;
    printf("General Well-being Log\n");
    printf("======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year < MIN_YEAR || year > MAX_YEAR) && (month < JAN || month > DEC))
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        else if (year < MIN_YEAR || year > MAX_YEAR) 
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        else if (month < JAN || month > DEC) 
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        else
        {

            printf("\n*** Log date set! ***\n");

            printf("\nLog starting date: %04d-", year);


            switch (month)
            {
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

            printf("-01\n");
        }

    } while (year < MIN_YEAR || year > MAX_YEAR || month < JAN || month > DEC);

    return 0;
}