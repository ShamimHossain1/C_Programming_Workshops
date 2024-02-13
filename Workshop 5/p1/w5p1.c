/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{

    // Variables
    int Year, Month;
    int JAN = 1, DEC = 12;

    printf("General Well-being Log\n======================\n");

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

    printf("Log starting date: %d-%s-01\n\n", Year, (Month == 1) ? "JAN" : (Month == 2) ? "FEB"
                                                                   : (Month == 3)   ? "MAR"
                                                                   : (Month == 4)   ? "APR"
                                                                   : (Month == 5)   ? "MAY"
                                                                   : (Month == 6)   ? "JUN"
                                                                   : (Month == 7)   ? "JUL"
                                                                   : (Month == 8)   ? "AUG"
                                                                   : (Month == 9)   ? "SEP"
                                                                   : (Month == 10)  ? "OCT"
                                                                   : (Month == 11)  ? "NOV"
                                                                                    : "DEC");

    return 0;
}
