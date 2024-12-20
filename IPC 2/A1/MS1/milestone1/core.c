/*///////////////////////////////////////////////////////////////////////////
***************************************************************************
Reflection
<assesment name example : Assignment 1 MS - 1 >

Full Name : URVISH DINESHBHAI CHAUDHARI
Student ID# : 153158225
Email : udchaudhari1@myseneca.ca
Section : NCC

Authenticity Declaration :

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
***************************************************************************
///////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "core.h"

void clearInputbuffer(void)
{
    //display all remaining chrs from the standerd input buffer:
    while (getchar() != '\n')
    {
        ; //do nothing
    }
}
void clearInputBuffer2()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputbuffer();
    putchar('\n');
}
int inputInt(void)
{
    char newline = 'x'; 
    int value;
    while (newline != '\n')
    {



        // read an integer value as user input 
        scanf(" %d%c", &value, &newline);
            // if newline is found break out of the loop 
            if (newline == '\n')
            {

                break;
            }
            else
            {
                // if newline is not found, clear the buffer
                 // and display the error message else

                clearInputbuffer();
                printf("Error! Input a whole number: ");


            }

        
    }
    // return the valid integer inputted by the user 
    return value;

}

   

int inputIntPositive(void)
{
    int value;

    do
    {
        value = inputInt();
        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0);

    return value;
}

int inputIntRange(int min, int max)
{
    int value;
   
    do
    {
        value = inputInt();

        if (value < min || value > max)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
        }
    } while (value < min || value > max);

    return value;
}

char inputCharOption(const char *valid_characters)
{
      int len = strlen(valid_characters);
        int i;
        char option;
        while (1)
        {
            scanf(" %c", &option);
            int flag = 0;
            // search the inputted character in the search string 
            for (i = 0; i < len; i++)
            {
                if (option == valid_characters[i])
                {
                    flag = 1;
                    break;
                }
            }
            // if character is found, break out of the loop 
            if (flag == 1)
            {
                break;
            }
            // if character is not found, display error message
            else
            {
                printf("ERROR: Character must be one of [%s]: ", valid_characters);
            }
        }
        // return the valid character inputted by the user 
        return option;
    

}

void inputCString(char* str, int minLen, int maxLen)
{
    char tempString[100];

    while (1) {
        clearInputBuffer2();
        scanf("%[^\n]", tempString);

        if (minLen == maxLen) {
            if (strlen(tempString) != minLen) {
                printf("ERROR: String length must be exactly %d chars: ", minLen);
            }
            else {
                break;
            }
        }
        else {
            if (strlen(tempString) > maxLen) {
                printf("ERROR: String length must be no more than %d chars: ", maxLen);
            }
            else if (strlen(tempString) < minLen) {
                printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
            }
            else {
                break;
            }
        }
    }

    strcpy(str, tempString);
}


void displayFormattedPhone(const char* phone_number)
{
    // if phone number is NULL, display the required string and exit the function
    if (phone_number == NULL) {
        printf("(___)___-____");
        return;
    }

    int i;
    int count = 0;
    int len = strlen(phone_number);

    for (i = 0; i < len; i++) {
        if (phone_number[i] >= '0' && phone_number[i] <= '9') {
            count++;
        }
    }

    // if phone number length is not equal to 10 or has non-digit characters,
    // display the required string and exit the function
    if (len != 10 || len != count) {
        printf("(___)___-____");
    }
    else {
        // display the formatted phone number
        printf("(%c%c%c)%c%c%c-%c%c%c%c",
            phone_number[0], phone_number[1], phone_number[2],
            phone_number[3], phone_number[4], phone_number[5],
            phone_number[6], phone_number[7], phone_number[8], phone_number[9]);
    }
}