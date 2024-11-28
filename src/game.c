#include <ncurses.h>
#include <stdlib.h>
#include "game.h"

struct Entity
{
    int x;
    int y;
} player;

// Direction vectors for moving: Up, Down, Left, Right
int directions[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};

// Maze array (1: wall, 0: path)
int maze[DEFAULT_MAZE_HEIGHT][DEFAULT_MAZE_WIDTH];

// Function to initialize the maze with walls
void initMaze(int height, int width)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            maze[y][x] = 1; // Initially, all walls
        }
    }
}

// Function to check if a position is within bounds
int isInBounds(int y, int x, int height, int width)
{
    return (y > 0 && y < height - 1 && x > 0 && x < width - 1);
}

// Recursive backtracking function to generate the maze
void generateMaze(int y, int x, int height, int width)
{
    maze[y][x] = 0; // Mark current position as a path

    // Shuffle directions to randomize the path generation
    for (int i = 0; i < 4; i++)
    {
        int dir = rand() % 4;
        int temp[2] = {directions[i][0], directions[i][1]};
        directions[i][0] = directions[dir][0];
        directions[i][1] = directions[dir][1];
        directions[dir][0] = temp[0];
        directions[dir][1] = temp[1];
    }

    // Try all four directions
    for (int i = 0; i < 4; i++)
    {
        int newY = y + directions[i][0];
        int newX = x + directions[i][1];

        if (isInBounds(newY, newX, height, width) && maze[newY][newX] == 1)
        {
            // If the neighboring cell is a wall, make a path
            if (maze[newY - directions[i][0] / 2][newX - directions[i][1] / 2] == 1)
            {
                maze[newY - directions[i][0] / 2][newX - directions[i][1] / 2] = 0;
                generateMaze(newY, newX, height, width);
            }
        }
    }
}

void initPlayer()
{
    player.x = 1;
    player.y = 1;
}

int playerMovement(char ch, int goalX, int goalY)
{

    keypad(stdscr, TRUE);
    if ((ch == 'w' || ch == KEY_UP) && maze[player.y - 1][player.x] != 1)
    {
        // Move up
        maze[player.y][player.x] = 0;
        player.y--;
    }
    else if ((ch == 's' || ch == KEY_DOWN) && maze[player.y + 1][player.x] != 1)
    {
        // Move down
        maze[player.y][player.x] = 0;
        player.y++;
    }
    else if ((ch == 'a' || ch == KEY_LEFT ) && maze[player.y][player.x - 1] != 1)
    {
        // Move left
        maze[player.y][player.x] = 0;
        player.x--;
    }
    else if ((ch == 'd' || ch == KEY_RIGHT) && maze[player.y][player.x + 1] != 1)
    {
        // Move right
        maze[player.y][player.x] = 0;
        player.x++;
    }

    return player.x == goalX && player.y == goalY;
}

// Function to draw the maze on the screen using ncurses
void drawMaze(int height, int width)
{



    int originX = (COLS - width) / 2;   
    int originY = (LINES - height) / 2; 

    maze[player.y][player.x] = 2;

    maze[height - 2][width - 2] = 3;


    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (maze[y][x] == 1)
                mvaddch(originY + y, originX + x, '#'); // Wall
            else if (maze[y][x] == 2)
            {
                attron(COLOR_PAIR(2));
                mvaddch(originY + y, originX + x, '@'); // Player
                attroff(COLOR_PAIR(2));
            }
            else if (maze[y][x] == 3)
            {
                attron(COLOR_PAIR(1));
                mvaddch(originY + y, originX + x, 'X'); // Goal
                attroff(COLOR_PAIR(1));
            }
            else
                mvaddch(originY + y, originX + x, ' '); // Path
        }
    }

    refresh();
}
