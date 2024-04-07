//
// Created by Gregory Jabido on 4/5/24.
//

#include "PA7Header.h"

/*************************************************************
* Function: run_system ()
* Date Created:
* Date Last Modified:
* Description:
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/

/*************************************************************
* Function: clearScreen()
* Date Created: 3/17/24
* Date Last Modified: 3/17/24
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

