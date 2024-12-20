#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define macros for easy modification of rules
#define MAX_LIVES 10
#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define MIN_MOVES 3

// Define structures for PlayerInfo and GameInfo
struct PlayerInfo {
    int lives;
    char symbol;
    int treasureCount;
    int history[MAX_PATH_LENGTH]; // Assuming a maximum path length
};

struct GameInfo {
    int pathLength;
    int maxMoves;
    int bombs[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
};

int main() {
    struct PlayerInfo player;
    struct GameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    // Player Configuration
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    do {
    printf("Set the number of lives: ");
    scanf("%d", &player.lives);
        if (player.lives < 1 || player.lives > MAX_LIVES) 
        {
    printf("     Must be between 1 and %d!\n", MAX_LIVES);
        }
    } while (player.lives < 1 || player.lives > MAX_LIVES);

    // Initialize player's history
    int i,j;
    for ( i = 0; i < MAX_PATH_LENGTH; i++) 
    {
        player.history[i] = 0;
    }

    printf("Player configuration set-up is complete\n\n");

    // Game Configuration
    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
    printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
    scanf("%d", &game.pathLength);
        if (game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH || game.pathLength % 5 != 0) 
        {
    printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    } while (game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH || game.pathLength % 5 != 0);

    do {
    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &game.maxMoves);
        if (game.maxMoves < MIN_MOVES || game.maxMoves >(game.pathLength * 0.75)) 
        {
    printf("    Value must be between %d and %d\n", MIN_MOVES, (int)(game.pathLength * 0.75));
        }
    } while (game.maxMoves < MIN_MOVES || game.maxMoves >(game.pathLength * 0.75));

    // BOMB Placement
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for ( i = 0; i < game.pathLength; i += 5) 
    {
    printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for ( j = 0; j < 5; j++) 
        {
    scanf("%d", &game.bombs[i + j]);
        }
    }
    printf("BOMB placement set\n\n");

    // TREASURE Placement
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for ( i = 0; i < game.pathLength; i += 5) 
    {
    printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for ( j = 0; j < 5; j++) 
        {
    scanf("%d", &game.treasure[i + j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    // Display configuration settings
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for ( i = 0; i < game.pathLength; i++) 
    {
    printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for ( i = 0; i < game.pathLength; i++) 
    {
    printf("%d", game.treasure[i]);
    }
   printf("\n\n====================================\n");
     printf("~ Get ready to play TREASURE HUNT! ~\n");
     printf("====================================\n");

    return 0;
}
