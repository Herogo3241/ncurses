#ifndef MAZE_H
#define MAZE_H

#define DEFAULT_MAZE_WIDTH  60
#define DEFAULT_MAZE_HEIGHT 60




void initMaze(int height, int width);
void generateMaze(int y, int x, int height, int width);
void initPlayer();
int playerMovement(char ch, int goalX, int goalY);
void drawMaze(int height, int width);

#endif
