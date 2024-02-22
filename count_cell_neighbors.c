/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include "headers.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_cell_neighbors
 DESCRIPTION: Function checks current situation of the board and counts the amount of neighbors a cell has
	Input: Board, Rows, Columns
	Output: Amount of Neighbors 
  Used global variables: HEIGHT, WIDTH
*********************************************************************/

/**
 * @brief Function checks current situation of the board and counts the amount of neighbors a cell has
 * @param board The board of cells where alive/dead entries are placed
 * @param row The row of the cell
 * @param column The column index of the cell
 * @return Amount of Neighbors
 */

int count_cell_neighbors(struct cell board[HEIGHT][WIDTH], int row, int column) {
    int neighbor_count = 0; //Create a variable to store the amount of neighbors

    for (int i=row-1; i<=row+1; i++) { //Loop through cell's neighbors 
        for (int j=column-1; j<=column+1; j++) {
            if (i == row && j == column) { //Don't count in the cell itself
                continue;
            }
            if (board[(i+HEIGHT)%HEIGHT][(j+WIDTH)%WIDTH].current == 1) { //If a neighbor is alive, increment neighbor count
                neighbor_count++;
            }
        }
    }

    return neighbor_count; //Return the amount of neighbors
}