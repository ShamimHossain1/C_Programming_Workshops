#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char loopType;
    int numIterations;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &numIterations);

        int i;

        // Use switch statement for loopType
        switch (loopType) {
        case 'D':

            // Use do-while loop for printing the pattern
           
            if (numIterations == 0)
            {
                printf("ERROR: Invalid entered value(s)!\n");
            }
             else if (numIterations < 3 || numIterations > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");

            }
            else {
                printf("DO-WHILE: ");


                for (i = 0; i < numIterations; ++i) {
                    printf("D");

                }
                printf("\n");
            }
            break;


        case 'W':
            if (numIterations == 0)
            {
                printf("ERROR: Invalid entered value(s)!\n");
            }
            else if (numIterations < 3 || numIterations > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");

            }
            
            else {
                printf("WHILE   : ");
                // Use while loop for printing the pattern
                for (i = 0; i < numIterations; ++i) {

                    printf("W");


                }
                printf("\n");
            }

            break;

        case 'F':
             if (numIterations == 0)
              {
                  printf("ERROR: Invalid entered value(s)!\n");
            }
             else if (numIterations < 3 || numIterations > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");

            }
          
            else {
                printf("FOR     : ");
                // Use for loop for printing the pattern
                for ( i = 0; i < numIterations; ++i) {

                    printf("F");

                }
                printf("\n");
            }
            break;

        case 'Q':
            if (numIterations == 0) {
              printf("\n+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");
                return 0; // Exit the program
            }
            else {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
            break;

        default:
            printf("ERROR: Invalid entered value(s)!\n");

        }

        printf("\n");

    } while (1);

    return 0;
}
