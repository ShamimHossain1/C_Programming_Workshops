/*//////////////////////////////////////////////////////////////////////////
***************************************************************************
Reflection
<assesment name example : Assignment 1 MS - 2 >

Full Name : URVISH DINESHBHAI CHAUDHARI
Student ID# : 153158225
Email : udchaudhari1@myseneca.ca
Section : NCC

Authenticity Declaration :

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
***************************************************************************
////////////////////////////////////////////////////////////////////////// */
// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);
int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int low, int up);
char inputCharOption(const char* validch);
void inputCString(char* k, int lower, int upper);
void displayFormattedPhone(const char* phone);

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);






//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////














// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H