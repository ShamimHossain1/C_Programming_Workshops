#ifndef CORE_H
#define CORE_H

int inputInt();
int inputIntPositive();
int inputIntRange(int min, int max);
char inputCharOption(const char* options);
void inputCString(char* str, int minLen, int maxLen);
void displayFormattedPhone(const char* phone);

#endif