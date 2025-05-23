/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Shamim Hossain Srabon
Student ID#: 135646230
Email      : shsrabon@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);

int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lowerBound, int upperBound);
char inputCharOption(const char *validChars);
void inputCString(char *str, int minLength, int maxLength);
void displayFormattedPhone(const char *phoneNumber);