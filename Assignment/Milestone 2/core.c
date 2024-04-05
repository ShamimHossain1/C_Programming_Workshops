/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Shamim Hossain Srabon
Student ID#: 135646230
Email      : shsrabon@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <stdio.h>
#include "core.h"

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    int input;
    char newline;

    do
    {

        if (scanf("%d%c", &input, &newline) != 2 || newline != '\n')
        {
            clearInputBuffer(); // Clear invalid input
            printf("Error! Input a whole number: ");
        }
    } while (newline != '\n');

    return input;
}
int inputIntPositive(void)
{
    int input;

    do
    {
        scanf("%d", &input);
        clearInputBuffer();

        if (input <= 0)
        {

            printf("ERROR! Value must be > 0: ");
        }
    } while (input <= 0);

    return input;
}

int inputIntRange(int lowerBound, int upperBound)
{
    int input;
    char newline;

    do
    {

        if (scanf("%d%c", &input, &newline) != 2 || newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (input < lowerBound || input > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (input < lowerBound || input > upperBound || newline != '\n');

    return input;
}

char inputCharOption(const char *validChars)
{
    char input;
    int isValid = 0;

    do
    {

        scanf(" %c", &input);

        const char *ptr = validChars;
        while (*ptr != '\0')
        {
            if (*ptr == input)
            {
                isValid = 1;
                break;
            }
            ptr++;
        }

        if (!isValid)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }

    } while (!isValid);

    return input;
}

void inputCString(char *str, int minLength, int maxLength)
{
    int length;
    do
    {

        scanf(" %[^\n]", str);
        clearInputBuffer();

        // Calculate length
        length = 0;
        while (str[length] != '\0')
        {
            length++;
        }

        if (minLength == maxLength && (length < minLength || length > maxLength))
        {

            printf("ERROR: String length must be exactly %d chars: ", minLength);
        }
        else if (length > maxLength)
        {

            printf("ERROR: String length must be no more than %d chars: ", maxLength);
        }
        else if (length < minLength)
        {
            printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
        }
    } while (length < minLength || length > maxLength);
}

void displayFormattedPhone(const char *phoneNumber)
{
    if (phoneNumber == NULL)
    {
        printf("(___)___-____");
        return;
    }

    int length = 0;
    while (phoneNumber[length] != '\0')
    {
        length++;
    }

    if (length != 10)
    {
        printf("(___)___-____");
        return;
    }
    int i;
    for (i = 0; i < length; i++)
    {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
        {
            printf("(___)___-____");
            return;
        }
    }

    printf("(%c%c%c)%c%c%c-%c%c%c%c", phoneNumber[0], phoneNumber[1], phoneNumber[2],
           phoneNumber[3], phoneNumber[4], phoneNumber[5], phoneNumber[6],
           phoneNumber[7], phoneNumber[8], phoneNumber[9]);
}

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

