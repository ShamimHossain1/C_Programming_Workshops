// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);


int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lowerBound, int upperBound);
char inputCharOption(const char *validChars);
void inputCString(char *str, int minLength, int maxLength);