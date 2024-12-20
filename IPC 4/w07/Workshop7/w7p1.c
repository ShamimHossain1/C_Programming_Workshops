/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : ilhyun cho
Student ID#: 116342221
Email      : icho8@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LIVES 10
#define LENGTH_MIN 10
#define LENGTH_MAX 70
#define MULTIPLE 5

struct PlayerInfo
{
    int lives;
    char symbol;
    int treasureCount;
    int length[LENGTH_MAX];
};

struct GameInfo
{
    int moves;
    int pathLength;
    int bombs[LENGTH_MAX];
    int treasure[LENGTH_MAX];
};

int main(void)
{
    int i, j;
    int repeat;

    struct PlayerInfo player1 = { 0, 0, 0, {0} };
    struct GameInfo game = { 0, 0, {0}, {0} };

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player1.symbol);

    do
    {
        repeat = 0;
        printf("Set the number of lives: ");
        scanf("%d", &player1.lives);
        if (player1.lives < 1 || player1.lives > MAX_LIVES)
        {
            printf("     Must be between 1 and %d!\n", MAX_LIVES);
            repeat = 1;
        }
        else
        {
            printf("Player configuration set-up is complete\n\n");
        }
    } while (repeat);

    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        repeat = 0;
        printf("Set the path length (a multiple of %d between %2d-%2d): ", MULTIPLE, LENGTH_MIN, LENGTH_MAX);
        scanf("%d", &game.pathLength);
        if (game.pathLength < LENGTH_MIN || game.pathLength > LENGTH_MAX || game.pathLength % MULTIPLE != 0)
        {
            printf("     Must be a multiple of %d and between %2d-%2d!!!\n", MULTIPLE, LENGTH_MIN, LENGTH_MAX);
            repeat = 1;
        }
    } while (repeat);

    do
    {
        repeat = 0;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        if (game.moves < player1.lives || game.moves >(int)(game.pathLength * 0.75))
        {
            printf("    Value must be between %d and %d\n", player1.lives, (int)(game.pathLength * 0.75));
            repeat = 1;
        }
    } while (repeat);
    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"); //35
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i++)
    {
        if (i % MULTIPLE == 0)// 5 10 15 20 25 30 35
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);

            for (j = 0; j < MULTIPLE; j++)
            {
                scanf("%d", &game.bombs[i+j]);
            }
        }
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");      //35
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i++)
    {
        if (i % MULTIPLE == 0)// 5 10 15 20 25 30 35
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);

            for (j = 0; j < MULTIPLE; j++)
            {
                scanf("%d", &game.treasure[i+j]);
            }
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player1.symbol);
    printf("   Lives      : %d\n", player1.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");

    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    return 0;
}
