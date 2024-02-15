/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    //----------- Variables-----------------------
    int Year, Month;
    int JAN = 1, DEC = 12;
    double morningRating, eveningRating;
    double morningTotal = 0.0, eveningTotal = 0.0, overallTotal = 0.0;

    printf("General Well-being Log\n======================\n");

    //------------------- Input Log Year and Month-------------------------------
    do

    {

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &Year, &Month);
        if (Year < MIN_YEAR || Year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (Month < JAN || Month > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }

    } while (Year < MIN_YEAR || Year > MAX_YEAR || Month < JAN || Month > DEC);

    printf("\n*** Log date set! ***\n\n");

    for (int i = 1; i <= LOG_DAYS; i++)
    {
        printf("%d-%s-%02d\n", Year, (Month == 1) ? "JAN" : (Month == 2) ? "FEB"
                                                          : (Month == 3)   ? "MAR"
                                                          : (Month == 4)   ? "APR"
                                                          : (Month == 5)   ? "MAY"
                                                          : (Month == 6)   ? "JUN"
                                                          : (Month == 7)   ? "JUL"
                                                          : (Month == 8)   ? "AUG"
                                                          : (Month == 9)   ? "SEP"
                                                          : (Month == 10)  ? "OCT"
                                                          : (Month == 11)  ? "NOV"
                                                                           : "DEC",
               i);

        //----------------- Morning Rating -------------------------
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);

            if (morningRating < 0.0 || morningRating > 5.0)
            {
                printf("     ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morningRating < 0.0 || morningRating > 5.0);

        //--------------- Evening Rating ------------------------------
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);

            if (eveningRating < 0.0 || eveningRating > 5.0)
            {
                printf("     ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eveningRating < 0.0 || eveningRating > 5.0);

        //---------Update totals------------------

        morningTotal += morningRating;
        eveningTotal += eveningRating;
        overallTotal += morningRating + eveningRating;
    }

    //--------------- Calculate averages--------------------

    double avgMorning = morningTotal / LOG_DAYS;
    double avgEvening = eveningTotal / LOG_DAYS;
    double avgOverall = overallTotal / (LOG_DAYS * 2);

    //----------------- Display summary-------------------

    printf("\nSummary\n=======\n");
    printf("Morning total rating: %6.3lf\n", morningTotal);
    printf("Evening total rating: %6.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", overallTotal);
    printf("Average morning rating: %.1lf\n", avgMorning);
    printf("Average evening rating: %.1lf\n", avgEvening);
    printf("----------------------------\n");
    printf("Average overall rating: %.1lf\n", avgOverall);

    return 0;
}