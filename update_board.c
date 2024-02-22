/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>
#include "headers.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: update_board
 DESCRIPTION: Function updates current situation of the board
	Input: Board
	Output: Updated board situation
  Used global variables: HEIGHT, WIDTH, ALIVE, DEAD
*********************************************************************/

/**
 * @brief Function updates current situation of the boardd
 * @param board The board of cells
 * @return Updated board situation
 */

void update_board(struct cell board[HEIGHT][WIDTH]) {

    for (int i=0; i<HEIGHT; i++) { //Loop through board
        for (int j=0; j<WIDTH; j++) {
            int neighbor_count = count_cell_neighbors(board, i, j); //Create a variable to store the amount of neighbors a cell has from previous function

            if (neighbor_count <= 1 || neighbor_count >= 4) { //Cell with one or no neighbors' dies from loneliness. Cell with four or more neighbors' dies from overpopulation
                board[i][j].future = DEAD;
            } 
            else if (neighbor_count == 2) { //Cell with two neighbors stays alive
                board[i][j].future = board[i][j].current;
            }
            else if (neighbor_count == 3) { //Cell with three neighbors stays alive, or becomes populated if "empty"
                board[i][j].future = ALIVE;
            }
            
        }
    }

    for (int i=0; i<HEIGHT; i++) { //Loop through board
        for (int j=0; j<WIDTH; j++) {
            board[i][j].current = board[i][j].future; //Update board with the new situation
        }
    }
}
