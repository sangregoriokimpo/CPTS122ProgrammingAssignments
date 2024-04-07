//
// Created by Gregory Jabido on 3/5/24.
//

#include "PA5Header.h"
/*************************************************************
* Function: clearScreen()
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Detects OS. Clears the screen depending on
* OS.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: The screen is cleared.
*************************************************************/

void clearScreen() {//clear screen
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
