#pragma once
#include "PA4Header.h"

/*************************************************************
* Function: clearScreen()
* Date Created: 2/24/24
* Date Last Modified: 2/24/24
* Description: Clears the console screen based on the operating 
* system.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: The console screen is cleared.
*************************************************************/

void clearScreen() {//Clear Screen
#ifdef _WIN32
    // For Windows
    system("cls");
#elif __APPLE__
    // For macOS
    system("clear");
#else
    // ANSI escape codes to clear the screen
    printf("\033[H\033[J");
#endif
}