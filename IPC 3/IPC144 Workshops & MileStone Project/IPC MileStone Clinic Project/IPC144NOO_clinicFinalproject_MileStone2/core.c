/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Soni Dev Alpeshbhai
Student ID#: 130759210
Email      : dasoni4@myseneca.ca
Section    : NOO
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

// This function guarantees that an integer value is entered and returned. If an invalid value is entered, an error message would be displayed.
int inputInt(void) {
    char charac = ' ';
    int Value;

    do {
        scanf("%d%c", &Value, &charac);

        if (charac != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    while (charac != '\n');

    // If the character after the integer is a new line character that means an appropriate value was entered
    return Value;
}

// This function guarantees a positive integer value is entered and returned. If a zero or a negative value in entered, an error message would be displayed.
int inputIntPositive(void) {
    char charac = ' ';
    int Value;

    do {
        scanf("%d%c", &Value, &charac);

        if (charac != '\n') {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }

        if (Value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    }
    while (Value <= 0);

    // After checks are completed we can return the value
    return Value;
}

// This function guarantees that an integer value is entered within the range (inclusive) and returned. If a value from outside the range is entered, display an error message and continue to prompt until a value in the given range is entered.
int inputIntRange(int lowerBound, int upperBound) {
    char charac = ' ';
    int Value;

    do {
        scanf("%d%c", &Value, &charac);

        if (charac != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (!(Value <= upperBound && Value >= lowerBound)) {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
        else{
            printf("INVALID");
        }
    }
    while (!(Value <= upperBound && Value >= lowerBound));

    // After checks are completed we can return the value
    return Value;
}

// This function guarantees a single character value is entered within the list of valid characters and returned. If an entered character is not in the list of valid characters, display an error message and prompt again.
char inputCharOption(char str[]) {
    int ind, count = 0;
    char input;

    do {
        scanf(" %c", &input);

        for (ind = 0; str[ind] != '\0'; ind++) {
            if (input == str[ind]) {
                count++;
            }
        }

        if (count == 0) {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (count == 0);

    // After all checks are passed we will return the input value
    clearInputBuffer();
    return input;
}

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments.
void inputCString(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int length = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && length <= maxChar) {
            ch = getchar();
            str[length] = ch;
            length++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && length <= (maxChar + 1)) {
            length--;
            str[length] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && length != minChar) {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
            ch = 'a';
        }
        else if (length < minChar || length > maxChar) {
            if (length > maxChar) {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
                ch = 'a';
            }
            else if (length < minChar) {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
                ch = 'a';
            }
        }
        else {
            flag = 0;
        }
    }
}

// The purpose of this function is to display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char* str) {
    int length = 0, ind;

    length = strlen(str);

    if (length == 10) {
        ind = 0;
        printf("(");
        while (ind < 3) {
            printf("%c", str[ind]);
            ind++;
        }
        printf(")");
        while (ind < 6) {
            printf("%c", str[ind]);
            ind++;
        }
        printf("-");
        while (ind < 10) {
            printf("%c", str[ind]);
            ind++;
        }
    }
    else {
        printf("(___)___-____");
    }
    if (str != 0) {
        for (ind = 0;str[ind] != '\0';ind++)
            length++;
    }
}