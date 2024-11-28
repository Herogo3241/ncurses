#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "header/entity.h"


// Function to generate a random position
int random_position(int limit)
{
    return rand() % limit;
}

// Function to spawn food at random positions
void spawn_food()
{
    for (int i = 0; i < MAX_FOOD; i++)
    {
        food[i].x = random_position(COLS - 1);  // Random x position (avoid last column)
        food[i].y = random_position(LINES - 1); // Random y position (avoid last row)
        food[i].model = '*'; // Food model
    }
}

// Display all food items
void display_food()
{
    for (int i = 0; i < MAX_FOOD; i++)
    {
        move(food[i].y, food[i].x);
        addch(food[i].model);
    }
}

// Initialize the game
void init_game()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    srand(time(NULL)); // Seed the random number generator

    player.x = COLS / 2;
    player.y = LINES / 2;
    player.model = '>';

    spawn_food(); 
    display_food();

    move(player.y, player.x);
    addch(player.model);
    noecho();
}

// Handle player movement
void player_movement(char ch)
{
    if (ch == 'w')
    {
        player.model = '^';
        if (player.y > 0)
            player.y--;
    }
    if (ch == 's')
    {
        player.model = 'v';
        if (player.y < LINES - 1)
            player.y++;
    }
    if (ch == 'a')
    {
        player.model = '<';
        if (player.x > 0)
            player.x--;
    }
    if (ch == 'd')
    {
        player.model = '>';
        if (player.x < COLS - 1)
            player.x++;
    }
}



int main()
{
    init_game();

    while (1)
    {
        int ch = getch();

        player_movement(ch);

        clear(); // Clear the screen before drawing the new player and food

        display_food(); // Draw the food items

        move(player.y, player.x);
        addch(player.model);

        if (ch == 'q')
        {
            endwin();
            return 0;
        }

        refresh();
    }

    endwin();
    return 0;
}
