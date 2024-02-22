/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/

/**
 * @brief Header-file for the program: defines global variables and structs and declares functions
 */

/* Global constants */
#define WIDTH 40 ///Width of the game board
#define HEIGHT 20 ///Height of the game board
#define ALIVE 1 ///Alive cell = 1
#define DEAD 0 ///Dead cell = 0

/* Global structures */
struct cell {
    int current; //Current situation, which is visible on screen
    int future;  //Temporary calculation area for next round calculation
};


/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/
int count_cell_neighbors(struct cell board[HEIGHT][WIDTH], int row, int column);
void update_board(struct cell board[HEIGHT][WIDTH]);
void initialize_board(struct cell board[HEIGHT][WIDTH]);
void print_board(struct cell board[HEIGHT][WIDTH]);
void print_menu();