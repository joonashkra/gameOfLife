/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include "headers.h"
#include <time.h>
#include <stdlib.h>

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: initialize_board
 DESCRIPTION: Places random alive entries on board on start of the game
	Input: Board
	Output: Random alive entries on board
  Used global variables: HEIGHT, WIDTH
*********************************************************************/

/**
 * @brief Places random alive entries on board on start of the game
 * @param board The board of cells
 * @return Random alive entries on board
 */

void initialize_board(struct cell board[HEIGHT][WIDTH]) {
    srand(time(NULL)); //Random number generator
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int random_number = rand() % 2; //Generate a random number between 0 and 1 (dead or alive)
            board[i][j].current = random_number; //Set that number to a cell
            board[i][j].future = 0;
        }
    }
}