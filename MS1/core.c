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
            printf("Error! Please input a valid whole number: ");
        }
    } while (newline != '\n');

    return input;
}
int inputIntPositive(void)
{
    int input;
    char nextChar;

    do
    {

        if (scanf("%d%c", &input, &nextChar) != 2 || nextChar != '\n' || input <= 0)
        {
            clearInputBuffer();
            printf("ERROR! Value must be > 0: ");
        }
    } while (input <= 0);

    return input;
}

int inputIntRange(int lowerBound, int upperBound)
{
    int input;
    char nextChar;

    do
    {

        if (scanf("%d%c", &input, &nextChar) != 2 || nextChar != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (input < lowerBound || input > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (input < lowerBound || input > upperBound || nextChar != '\n');

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