#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "src/game.c"




void displayMenu(int highlight) {
    clear(); 

    

  
    
    mvprintw(LINES/2 - 11, COLS / 2 - 25," __  __                  ___   __   _____ _");
    mvprintw(LINES/2 - 10,  COLS / 2 - 25, "|  \\/  | __ _ _______   / _ \\ / _| |_   _(_)_ __ ___   ___");
    mvprintw(LINES/2 - 9,  COLS / 2 - 25, "| |\\/| |/ _` |_  / _ \\ | | | | |_    | | | | '_ ` _ \\ / _ \\");
    mvprintw(LINES/2 - 8,  COLS / 2 - 25, "| |  | | (_| |/ /  __/ | |_| |  _|   | | | | | | | | |  __/");
    mvprintw(LINES/2 - 7,  COLS / 2 - 25, "|_|  |_|\\__,_/___\\___|  \\___/|_|     |_| |_|_| |_| |_|\\___|");
    
   


   char *choices[] = {
        "Easy",
        "Medium",
        "Hard",
        "How to Play",
        "Quit [press Q]"
    };
    
    
    // Display the menu with highlighting
    for (int i = 0; i < 5; i++) {
        if (i == highlight) {
            attron(A_REVERSE);  // Highlight the selected option
        }
        mvprintw(LINES/2 - 2 + i, COLS / 2 - 2, "%s", choices[i]);
        if (i == highlight) {
            attroff(A_REVERSE);  // Turn off the highlight
        }
    }

    refresh(); // Refresh to show the updated screen
}

// Function to handle user input and menu navigation
int navigateMenu() {
    int ch;
    int highlight = 0;
    int choice = -1;
    
    // Menu loop
    while (choice == -1) {
        displayMenu(highlight);
        ch = getch();
        
        switch (ch) {
            case KEY_UP:
                highlight = (highlight == 0) ? 4 : highlight - 1;  // Loop to last option
                break;
            case KEY_DOWN:
                highlight = (highlight == 4) ? 0 : highlight + 1;  // Loop to first option
                break;
            case 'w':
                highlight = (highlight == 0) ? 4 : highlight - 1;  // Loop to last option
                break;
            case 's':
                highlight = (highlight == 4) ? 4 : highlight + 1;  // Loop to last option
                break;
            case 'q':
                choice = 4;  // Quit game
                break;
            case 10:  // Enter key
                choice = highlight;
                break;
        }
    }
    
    return choice;
}


void howToPlayScreen() {
    int ch;
    int highlight = 0;
    int choice = -1;
    
    // Loop for the "How to Play" screen
    while (choice == -1) {
        clear();

        // Display instructions in the center
        mvprintw(LINES / 2 - 7, COLS / 2 - 15, "How to Play:");
        mvprintw(LINES / 2 - 5, COLS / 2 - 15, "1. Use WASD to move.");
        mvprintw(LINES / 2 - 4, COLS / 2 - 15, "2. Reach the goal to win.");
        mvprintw(LINES / 2 - 3, COLS / 2 - 15, "3. Overall time is calculated.");

        // Back button
        char *choices[] = {
            "Back to Main Menu [press Q]"
        };

        // Display the "Back" option
        for (int i = 0; i < 1; i++) {
            if (i == highlight) {
                attron(A_REVERSE);  // Highlight the selected option
            }
            mvprintw(LINES / 2 + i + 1, COLS / 2 - 5, "%s", choices[i]);
            if (i == highlight) {
                attroff(A_REVERSE);  // Turn off the highlight
            }
        }

        refresh();

        // Handle user input
        ch = getch();
        switch (ch) {
            case KEY_UP:
                highlight = (highlight == 0) ? 0 : highlight - 1;  // Loop to last option
                break;
            case KEY_DOWN:
                highlight = (highlight == 0) ? 0 : highlight + 1;  // Loop to first option
                break;
            case 'q':
                choice = 0;
            case 10:  // Enter key
                choice = highlight;
                break;
        }
    }

    if (choice == 0) {
        return;  // Return to the main menu
    }
}


void gameOverScreen(double time_taken) {
    int highlight = 0;
    int choice = -1;
    int ch;

    // Loop for the game over menu
    while (choice == -1) {
        clear();

        // Display Game Over Message
        mvprintw(LINES / 2 - 7, COLS / 2 - 23, "  ____                         ___");
        mvprintw(LINES / 2 - 6, COLS / 2 - 23, " / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __");
        mvprintw(LINES / 2 - 5, COLS / 2 - 23, "| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|");
        mvprintw(LINES / 2 - 4, COLS / 2 - 23, "| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |");
        mvprintw(LINES / 2 - 3, COLS / 2 - 23, " \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|\n");
 

        attron(COLOR_PAIR(2));
        mvprintw(LINES / 2 - 1, COLS / 2 - 15, "You escaped the maze in %.2f seconds!", time_taken);
        attroff(COLOR_PAIR(2));

        // Menu options
        char *choices[] = {
            "Main Menu",
            "Exit [press Q]"
        };

        // Display menu with highlighting
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                attron(A_REVERSE);  // Highlight the selected option
            }
            mvprintw(LINES / 2 + i + 1, COLS / 2 - 5, "%s", choices[i]);
            if (i == highlight) {
                attroff(A_REVERSE);  // Turn off the highlight
            }
        }

        refresh();

        // Handle user input
        ch = getch();
        switch (ch) {
            case KEY_UP:
                highlight = (highlight == 0) ? 1 : highlight - 1;  // Loop to last option
                break;
            case KEY_DOWN:
                highlight = (highlight == 1) ? 0 : highlight + 1;  // Loop to first option
                break;
            case 'q':
                choice = 1;
                break;
            case 10:  // Enter key
                choice = highlight;
                break;
        }
    }

    // Handle the selected choice
    if (choice == 0) {
        navigateMenu();  // Go back to the main menu
    } else if (choice == 1) {
        endwin();
        exit(0);  // Exit the game
    }
}


// Function to handle the gameplay and maze generation
void playGame(int difficulty) {
    int mazeHeight, mazeWidth;

    // Set maze size based on difficulty choice
    switch (difficulty) {
        case 0:  // Easy
            mazeHeight = 15;
            mazeWidth = 25;
            break;
        case 1:  // Medium
            mazeHeight = 21;
            mazeWidth = 35;
            break;
        case 2:  // Hard
            mazeHeight = 31;
            mazeWidth = 51;
            break;
        default:
            mazeHeight = 15;
            mazeWidth = 15;
    }

    // Generate and display the maze
    initMaze(mazeHeight, mazeWidth);
    generateMaze(1, 1, mazeHeight, mazeWidth);
    initPlayer();
    drawMaze(mazeHeight, mazeWidth);

    time_t start_time, current_time;
    time(&start_time);

    nodelay(stdscr, TRUE);  // Enable non-blocking input
    int ch;
    while (1) {
        // Calculate elapsed time
        time(&current_time);
        double elapsed_time = difftime(current_time, start_time);

        // Display the elapsed time at the top-right corner
        attron(COLOR_PAIR(1));  // Use a color for emphasis (red on black)
        mvprintw((LINES - mazeHeight) / 2 - 2, (COLS - mazeWidth) / 2 + 5, "Time: %.2f sec", elapsed_time);
        attroff(COLOR_PAIR(1));

        refresh();

        ch = getch();
        if (ch != ERR) {  // Process input only if a key is pressed
            if (ch == 27) {  // ESC key to return to the menu
                nodelay(stdscr, FALSE);  // Restore blocking input before returning
                return;
            }
            if (ch == 'q') {
                break;  // Quit the game
            }
            int win = playerMovement(ch, mazeWidth - 2, mazeHeight - 2);
            drawMaze(mazeHeight, mazeWidth);

            if (win) {
                double total_time = difftime(current_time, start_time);
                nodelay(stdscr, FALSE);  // Restore blocking input before calling gameOverScreen
                gameOverScreen(total_time);
                return;
            }
        }
    }

    nodelay(stdscr, FALSE);  // Restore blocking input before exiting
}


int main() {
    srand(time(NULL));

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);  // Enable arrow key detection

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);  // Goal color: Red on Black
        init_pair(2, COLOR_GREEN, COLOR_BLACK); // Player Color: Green on Black
    } else {
        endwin();
        fprintf(stderr, "Your terminal does not support color\n");
        exit(1);
    }

    // Game loop
    while (1) {
        // Display the menu and get user input for difficulty
        int choice = navigateMenu();

         // Exit if user selects "Quit"
        if (choice == 4) {
            endwin();
            exit(0);
        }

        // Show how to play screen if the user selects "How to Play"
        if (choice == 3) {
            howToPlayScreen();
            continue;
        }

        // Play the game based on selected difficulty
        if(choice < 3){
            clear();
            playGame(choice);
        }
        
    }

    // Clean up and exit
    endwin();
    return 0;
}
