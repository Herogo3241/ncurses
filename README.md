Certainly! Below is a README template you can use for your GitHub repository. You can customize it further if necessary.

---

# Maze of Time (NCurses-based)

Welcome to the Maze of Time! This is a terminal-based maze game built using the NCurses library, where players must navigate through a randomly generated maze and escape on reaching the goal('X'). The game provides difficulty levels and a visually rich experience with the use of colors and maze rendering. It also includes a menu system with options for difficulty selection and a game over screen.

## Table of Contents

1. [Demo Video](#demo-video)
2. [Technologies Used](#technologies-used)
3. [Installation Guide](#installation-guide)
4. [How It Works: Random Maze Generation](#how-it-works-random-maze-generation)


## Demo Video

Check out the demo video to get a quick overview of how the game works:

[Demo Video Link](https://youtu.be/8jnGIHbzm8g)

## Technologies Used

This project uses the following technologies:

- **NCurses**: A library for creating terminal-based applications with user interfaces.
- **C Programming Language**: The game logic and maze generation are implemented using C.


## Installation Guide

To set up the Maze Game on your local machine, follow these steps:

### Prerequisites

Make sure you have the following installed:

- A C compiler (e.g., GCC)
- NCurses library (on most Linux distributions, it can be installed using `sudo apt-get install libncurses5-dev` or similar package manager commands)

### Steps to Install

1. **Clone the repository**:

   ```bash
   https://github.com/Herogo3241/terminal-maze.git
   cd terminal-maze
   ```

2. **Install dependencies** (if necessary, ensure that you have the NCurses library):

   ```bash
   sudo apt-get install libncurses5-dev
   ```

3. **Compile and run the code** :

   ```bash
   chmod u+x run.sh
   ./run.sh
   ```

4. **Installing the program**:
   ```bash
   chmod u+x install.sh
   ./install.sh
   ```
   Now run just call 'mazeoftime' to run it from anywhere



   This will start the game in your terminal.

## How It Works: Random Maze Generation

The maze is generated randomly using a depth-first search (DFS) algorithm. Here’s how the random maze generation works:

1. **Initialization**: The maze grid is initialized with walls (`#`) and empty spaces (`.`). The dimensions of the maze are chosen based on the difficulty level selected by the player.
   
2. **Maze Generation Algorithm**:
   - The algorithm starts at a random position in the grid and explores neighboring cells.
   - It marks cells as visited and creates paths (empty spaces) between cells.
   - The DFS backtracking approach ensures that the maze is randomly generated and each path is reachable.
   - It ensures there is exactly one path between the start and the exit (ensuring solvability).

3. **Rendering**: Once the maze is generated, the player is placed at the start position and the maze is rendered on the terminal screen. The player can move through the maze using the wasd keys, and the game checks for valid movements.

4. **Winning Condition**: The player must reach the goal ('X'). The game displays the time taken to escape the maze.

