/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

#define MAXIMUM_PATH_LENGTH 70
#define MINIMUM_PATH_LENGTH 10
#define MAXIMUM_LIVES 10
#define MINIMUM_LIVES 1
#define MULTIPLE 5

#include <stdio.h>

// <-------------------- Define Struct ---------------------->

struct PlayerInfo
{
    int lives;
    char char_symbol;
    int treasureCount;
    int positionHistory[MAXIMUM_PATH_LENGTH];
};

struct GameInfo
{
    int moves;
    int pathLength;
    int bombLocations[MAXIMUM_PATH_LENGTH];
    int treasureLocations[MAXIMUM_PATH_LENGTH];
};

int main(void)
{
    int i, j, k;
    int remainingMoves, remainingLives, movePosition = MAXIMUM_PATH_LENGTH + 1;

    struct PlayerInfo player;
    struct GameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    // <------------------- PLAYER Configuration ------------------->

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.char_symbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES);

    printf("Player configuration set-up is complete\n");
    printf("\n");

    // <-------------------- GAME Configuration -------------------------->

    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);

        if ((game.pathLength < MINIMUM_PATH_LENGTH || game.pathLength > MAXIMUM_PATH_LENGTH) || (game.pathLength % MULTIPLE != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while ((game.pathLength < MINIMUM_PATH_LENGTH || game.pathLength > MAXIMUM_PATH_LENGTH) || (game.pathLength % MULTIPLE != 0));

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);

        if (game.moves < player.lives || game.moves > (int)(0.75 * game.pathLength))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int)(0.75 * game.pathLength));
        }
    } while (game.moves < player.lives || game.moves > (int)(0.75 * game.pathLength));
    printf("\n");

    // <-------------------- BOMB Placement ------------------------->

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombLocations[i], &game.bombLocations[i + 1], &game.bombLocations[i + 2], &game.bombLocations[i + 3], &game.bombLocations[i + 4]);
    }

    printf("BOMB placement set\n");
    printf("\n");

    // <------------------- TREASURE Placement ------------------------->

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasureLocations[i], &game.treasureLocations[i + 1], &game.treasureLocations[i + 2], &game.treasureLocations[i + 3], &game.treasureLocations[i + 4]);
    }

    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");

        // <-------------- TREASURE HUNT Configuration Settings ------------------>


    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.char_symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);

    printf("   Bombs      : ");

    for (j = 0; j < game.pathLength; j++)
    {
        printf("%d", game.bombLocations[j]);
    }
    printf("\n");

    printf("   Treasure   : ");

    for (k = 0; k < game.pathLength; k++)
    {
        printf("%d", game.treasureLocations[k]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    //<----------------  Play TREASURE HUNT ------------------------------->

    remainingMoves = game.moves;
    remainingLives = player.lives;
    player.treasureCount = 0;
    int Count = 0;

    char currentPosition[MAXIMUM_PATH_LENGTH];
    char positionItem[MAXIMUM_PATH_LENGTH];

    for (j = 0; j < game.pathLength; j++)
    {
        player.positionHistory[j] = 0;
    }

    for (k = 0; k < game.pathLength; k++)
    {
        positionItem[k] = '-';
    }

    for (k = 0; k < game.pathLength; k++)
    {
        currentPosition[k] = ' ';
    }

    do
    {
        for (k = 0; k < game.pathLength; k++)
        {
            if (currentPosition[k] == player.char_symbol)
            {
                Count++;
            }
        }
        if (Count == 0)
        {
            printf("\n");
        }
        else
        {
            printf("  ");
            for (k = 0; k < game.pathLength; k++)
            {
                if (currentPosition[k] == player.char_symbol)
                {
                    printf("%c\n", currentPosition[k]);
                    break;
                }
                else
                {
                    printf("%c", currentPosition[k]);
                }
            }
        }

        for (k = 0; k < game.pathLength; k++)
        {
            currentPosition[k] = ' ';
        }

        printf("  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%c", positionItem[k]);
        }
        printf("\n");

        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (int)i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        printf("  ");
        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", remainingLives, player.treasureCount, remainingMoves);
        printf("+---------------------------------------------------+\n");

        if (remainingLives == 0)
        {
            break;
        }

        if (remainingMoves == 0)
        {
            break;
        }

        do
        {
            printf("Next Move [1-20]: ");
            scanf("%d", &movePosition);

            if (movePosition < 1 || movePosition > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }

        } while (movePosition < 1 || movePosition > game.pathLength);
        printf("\n");

        if (player.positionHistory[movePosition - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n\n");
            currentPosition[movePosition - 1] = player.char_symbol;
            remainingMoves++;
        }

        else if (game.bombLocations[movePosition - 1] == 1 && game.treasureLocations[movePosition - 1] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            positionItem[movePosition - 1] = '&';
            currentPosition[movePosition - 1] = player.char_symbol;
            remainingLives--;
            player.treasureCount++;
        }

        else if (game.bombLocations[movePosition - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            positionItem[movePosition - 1] = '!';
            currentPosition[movePosition - 1] = player.char_symbol;
            remainingLives--;
        }

        else if (game.treasureLocations[movePosition - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            positionItem[movePosition - 1] = '$';
            currentPosition[movePosition - 1] = player.char_symbol;
            player.treasureCount++;
        }

        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            positionItem[movePosition - 1] = '.';
            currentPosition[movePosition - 1] = player.char_symbol;
        }

        player.positionHistory[movePosition - 1] = 1;

        remainingMoves--;

        if (remainingLives == 0)
        {
            printf("No more LIVES remaining!\n\n");
        }
        if (remainingMoves == 0)
        {
            printf("No more MOVES remaining!\n\n");
        }

    } while (remainingMoves >= 0 && remainingLives >= 0);

    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    printf("\n");

    return 0;
}