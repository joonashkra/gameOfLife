/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>
#include "headers.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_board
 DESCRIPTION: Prints current situation of the board
	Input: Board
	Output: Current situation of the board
  Used global variables: HEIGHT, WIDTH, ALIVE, DEAD
*********************************************************************/

/**
 * @brief Prints current situation of the board
 * @param board The board of cells
 * @return Current situation of the board
 */

void print_board(struct cell board[HEIGHT][WIDTH]) {
    clear();
    for (int i = 0; i < HEIGHT; i++) { //Loop through the board
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j].current == ALIVE) { //If cell is alive, print '#' with proper color
                attron(COLOR_PAIR(ALIVE));
                mvprintw(i, j*2, "#");
                attroff(COLOR_PAIR(ALIVE));
            } else {
                attron(COLOR_PAIR(DEAD)); //If cell is dead, print ' ' with proper color
                mvprintw(i, j*2, " ");
                attroff(COLOR_PAIR(DEAD));
            }
        }
    }
}
