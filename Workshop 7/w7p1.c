/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Shamim Hossain Srabon
Student ID#: 135646230
Email      : shsrabon@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXIMUM_PATH 70

// <-------------------- Define Struct ---------------------->

struct PlayerInfo
{
    int lifeNum;
    char char_symbol;
    int treasureNum;
};

struct GameInfo
{
    int maxMoveNum;
    int pathLength;
    int bomb[MAXIMUM_PATH];
    int treasure[MAXIMUM_PATH];
};

int main()
{
    struct PlayerInfo player;
    struct GameInfo game;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    // <------------------- PLAYER Configuration ------------------->

    printf("PLAYER Configuration\n");

    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.char_symbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lifeNum);

        if (player.lifeNum < 1 || player.lifeNum > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lifeNum < 1 || player.lifeNum > 10);

    printf("Player configuration set-up is complete\n\n");

    // <-------------------- GAME Configuration -------------------------->

    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);

        if (game.pathLength < 10 || game.pathLength > 70 || game.pathLength % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game.pathLength < 10 || game.pathLength > 70 || game.pathLength % 5 != 0);

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxMoveNum);

        if (game.maxMoveNum < 3 || game.maxMoveNum > 26)
        {
            printf("    Value must be between 3 and 26\n");
        }
    } while (game.maxMoveNum < 3 || game.maxMoveNum > 26);

    // <-------------------- BOMB Placement ------------------------->

    printf("\nBOMB Placement");
    printf("\n--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    int i;
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

        int j;
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &game.bomb[j]);
        }
    }
    printf("BOMB placement set\n");

    // <------------------- TREASURE Placement ------------------------->

    printf("\nTREASURE Placement");
    printf("\n------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

        int j;
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &game.treasure[j]);
        }
    }

    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");

    // <-------------- TREASURE HUNT Configuration Settings ------------------>

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.char_symbol);
    printf("   Lives      : %d\n", player.lifeNum);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    printf("\nGame:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");

    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bomb[i]);
    }

    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasure[i]);
    }

    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}