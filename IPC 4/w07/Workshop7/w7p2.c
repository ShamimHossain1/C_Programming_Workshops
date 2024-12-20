/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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
    int repeat, moveRepeat, rangeRepeat;
    int position;

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

    for (i = 0; i < game.pathLength; i++)
    {
        player1.length[i] = '-';
    }

    do
    {
        repeat = 0;
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%c", player1.length[i]);
        }
        printf("\n");

        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10 == 0)
            {
                printf("%d", (i + 1) / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10 != 0)
            {
                printf("%d", (i + 1) % 10);
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");

        do
        {
            moveRepeat = 0;
            printf("+---------------------------------------------------+\n");
            printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player1.lives, player1.treasureCount, game.moves);
            printf("+---------------------------------------------------+\n");

            if (player1.lives != 0 && game.moves != 0)
            {
                do
                {
                    rangeRepeat = 0;
                    printf("Next Move [1-%2d]: ", game.pathLength);
                    scanf("%d", &position);
                    if (position < 1 || position > game.pathLength)
                    {
                        printf("  Out of Range!!!\n");
                        rangeRepeat = 1;
                    }
                } while (rangeRepeat);
                printf("\n");

                if ((player1.length[position - 1] == '.') || (player1.length[position - 1] == '&') ||
                    (player1.length[position - 1] == '$') || (player1.length[position - 1] == '!'))
                {
                    printf("===============> Dope! You've been here before!\n\n");
                }
                else if ((game.bombs[position - 1] == 0) && (game.treasure[position - 1] == 0))
                {
                    printf("===============> [.] ...Nothing found here... [.]\n\n");
                    game.moves--;
                    player1.length[position - 1] = '.';
                }
                else if ((game.bombs[position - 1] == 1) && (game.treasure[position - 1] == 1))
                {
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                    player1.lives--;
                    game.moves--;
                    player1.treasureCount++;
                    player1.length[position - 1] = '&';
                }
                else if (game.bombs[position - 1] == 1)
                {
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                    player1.lives--;
                    game.moves--;
                    player1.length[position - 1] = '!';
                }
                else if (game.treasure[position - 1] == 1)
                {
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                    game.moves--;
                    player1.treasureCount++;
                    player1.length[position - 1] = '$';
                }


                if (player1.lives == 0)
                {
                    printf("No more LIVES remaining!\n\n");
                }
                else if (game.moves == 0)
                {
                    printf("No more MOVES remaining!\n\n");
                }

                printf("  ");
                for (i = 0; i < position - 1; i++)  ///////////////////VÀ§Ä¡
                {
                    printf(" ");
                }
                printf("%c\n", player1.symbol);
                repeat = 1;
            }
        } while (moveRepeat);
    } while (repeat);

    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n\n");


    return 0;
}
