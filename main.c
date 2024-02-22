/***************************************************************************
 *   Copyright (C) $2023$ by $Joonas Heikura$   *
 *   $e2101191@edu.vamk.fi$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  Joonas Heikura / e2101191


 2.  Game Of Life


 3.  VERSIONS
       Version history:
            Final version with Ncurses: 27.4.2023

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>
#include "headers.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

/**
 * @brief The main function: initializes game-board, initializes ncurses and sets colors, executes game
 */

int main() {
    //Create a two-dimensional array and initializing all elements to zero (No one is alive)
    struct cell board[HEIGHT][WIDTH] = {0, 0};

    //Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);

    // Set the colors
    start_color();
    init_pair(ALIVE, COLOR_RED, COLOR_BLACK);
    init_pair(DEAD, COLOR_BLACK, COLOR_BLACK);
    refresh();

    //Initialize board with random alive cells
    initialize_board(board);

    //Print game and continue until user presses 'q'
    timeout(50);
    int end_game; //Create a variable for checking if user wants to end game
    do {
        print_board(board);
        update_board(board);
        refresh();
        end_game = getch(); //Check value of end_game
    } while (end_game != 'q'); //If user pressed 'q', end game

    endwin();
    return 0;
}