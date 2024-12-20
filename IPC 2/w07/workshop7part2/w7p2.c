/*/////////////////////////////////////////////////////////////////////////
 Workshop - #7 (P2)
Full Name  :   URVISH DINESHBHAI CHAUDHARI
Student ID#:   153158225
Email      :   udchauhari1@myseneca.ca/urvishchaudhari292@gmail.com
Section    :   NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SYMBOL '#'
#define MAX_LIVES 10
#define MULTIPLE_OF 5
#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70

struct PlayerInfo
{
    char symbol;
    int lives;
    int treasures;
    int positions[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int num_moves;
    int path_length;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];
};

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;

    int lives = 0, treasures = 0, moves = 0;
    int position_now = 0, previous_position = 0;

    int is_done = 0;
    int is_flagged = 0;
    int temporary;
    int min_move_count;
    int max_move_count;
    int i,j;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    while (!is_done)
    {
        printf("Set the number of lives: ");
        scanf("%d", &temporary);
        if (temporary > 0 && temporary <= MAX_LIVES)
        {
            player.lives = temporary;
            is_done = 1;
        }
        else
        {
            printf("     Must be between 1 and %d!\n", MAX_LIVES);
        }
    }

    for ( i = 0; i < MAX_PATH_LENGTH; i++)
    {
        player.positions[i] = 0;
    }

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    is_done = 0;
    while (!is_done)
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE_OF, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &temporary);

        if (temporary % MULTIPLE_OF == 0)
        {
            if (temporary >= MIN_PATH_LENGTH && temporary <= MAX_PATH_LENGTH)
            {
                game.path_length = temporary;
                is_done = 1;
            }
            else
            {
                printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE_OF, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
            }
        }
        else
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE_OF, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    }

    min_move_count = player.lives;
    max_move_count = (game.path_length * 75) / 100;

    is_done = 0;
    while (!is_done)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &temporary);

        if (temporary >= min_move_count && temporary <= max_move_count)
        {
            game.num_moves = temporary;
            is_done = 1;
        }
        else
        {
            printf("    Value must be between %d and %d\n", min_move_count, max_move_count);
        }
    }

    for ( i = 0; i < MAX_PATH_LENGTH; i++)
    {
        game.bombs[i] = 0;
    }

    for ( i = 0; i < MAX_PATH_LENGTH; i++)
    {
        game.treasures[i] = 0;
    }

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE_OF);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

    for ( i = 0; i < (game.path_length) / MULTIPLE_OF; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * MULTIPLE_OF) + 1, ((i + 1) * MULTIPLE_OF));
        for ( j = (i * 5); j < ((i * 5) + MULTIPLE_OF); j++)
        {
            scanf("%d", &game.bombs[j]);
        }
    }
    printf("BOMB placement set\n");
    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULTIPLE_OF, game.path_length);

    for ( i = 0; i < (game.path_length) / MULTIPLE_OF; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * MULTIPLE_OF) + 1, ((i + 1) * MULTIPLE_OF));
        for ( j = (i * 5); j < ((i * 5) + MULTIPLE_OF); j++)
        {
            scanf("%d", &game.treasures[j]);
        }
    }
    printf("TREASURE placement set\n");
    printf("\nGAME configuration set-up is complete...\n");
    printf("\n------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.path_length);
    printf("   Bombs      : ");
    for ( i = 0; i < game.path_length; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for ( i = 0; i < game.path_length; i++)
    {
        printf("%d", game.treasures[i]);
    }
    printf("\n");

    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    lives = player.lives;
    player.treasures = treasures;
    moves = game.num_moves;

    is_done = 0;
    while (!is_done)
    {
        printf("\n");
        if (previous_position > 0)
        {
            printf("  ");
            for ( i = 1; i < previous_position; i++)
            {
                printf(" ");
            }
            printf("%c\n", player.symbol);
        }

        printf("  ");
        for ( i = 0; i < game.path_length; i++)
        {
            if (player.positions[i] == 0)
            {
                printf("-");
            }
            else
            {
                if ((game.bombs[i] == 1) && (game.treasures[i] == 1))
                {
                    printf("&");
                }
                else
                {
                    if (game.bombs[i] == 1)
                    {
                        printf("!");
                    }
                    else
                    {
                        if (game.treasures[i] == 1)
                        {
                            printf("$");
                        }
                        else
                        {
                            printf(".");
                        }
                    }
                }
            }
        }
        printf("\n");

        printf("  ");
        for ( i = 1; i <= game.path_length; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n  ");
        for ( i = 1; i <= game.path_length; i++)
        {
            printf("%d", i % 10);
        }
        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", lives, treasures, moves);
        printf("+---------------------------------------------------+\n");

        is_flagged = 0;
        while (is_flagged != 1)
        {
            printf("Next Move [1-%2d]: ", game.path_length);
            scanf("%d", &position_now);
            if (position_now > 0 && position_now <= game.path_length)
            {
                if (player.positions[position_now - 1] == 1)
                {
                    printf("\n===============> Dope! You've been here before!\n");
                    previous_position = position_now;
                }
                else
                {
                    if ((game.bombs[position_now - 1] == 1) && (game.treasures[position_now - 1] == 1))
                    {
                        lives--;
                        treasures++;
                        printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                        printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                    }
                    else
                    {
                        if (game.bombs[position_now - 1] == 1)
                        {
                            lives--;
                            printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
                        }
                        else
                        {
                            if (game.treasures[position_now - 1] == 1)
                            {
                                treasures++;
                                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
                            }
                            else
                            {
                                printf("\n===============> [.] ...Nothing found here... [.]\n");
                            }
                        }
                    }
                    player.positions[position_now - 1] = 1;
                    previous_position = position_now;
                    moves--;
                }
                is_flagged = 1;
                previous_position = position_now;
            }
            else
            {
                printf("  Out of Range!!!\n");
            }
        }

        if (lives == 0)
        {
            printf("\nNo more LIVES remaining!\n");
            player.treasures = treasures;
            is_done = 1;
        }
    }

    printf("\n  ");
    if (previous_position > 0)
    {
        for ( i = 1; i < previous_position; i++)
        {
            printf(" ");
        }
        printf("%c\n", player.symbol);
    }

    printf("  ");
    for ( i = 0; i < game.path_length; i++)
    {
        if (player.positions[i] == 0)
        {
            printf("-");
        }
        else
        {
            if ((game.bombs[i] == 1) && (game.treasures[i] == 1))
            {
                printf("&");
            }
            else
            {
                if (game.bombs[i] == 1)
                {
                    printf("!");
                }
                else
                {
                    if (game.treasures[i] == 1)
                    {
                        printf("$");
                    }
                    else
                    {
                        printf(".");
                    }
                }
            }
        }
    }
    printf("\n");

    printf("  ");
    for ( i = 1; i <= game.path_length; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", i / 10);
        }
        else
        {
            printf("|");
        }
    }
    printf("\n  ");
    for ( i = 1; i <= game.path_length; i++)
    {
        printf("%d", i % 10);
    }
    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", lives, treasures, moves);
    printf("+---------------------------------------------------+\n");
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");

    printf("\nYou should play again and try to beat your score!\n");
    return 0;
}
