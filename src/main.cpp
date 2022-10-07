/**
 * @file    main.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    02/10/2022
 * @date    07/10/2022
 */

/****************************** Included files ********************************/
#include "Analysis.h"
#include <stdio.h>
/********************************* Entry point ********************************/
int main(int argc, char *argv[]) {
    Sudoku puzzle(EASY);
    puzzle.Print();
    puzzle.Calculate();
    if (puzzle.IsSolved()) {
        printf("Puzzle is solved\nThe number of cycles is: %u\n", puzzle.cycles);
        puzzle.Print();
    }
    else {
        printf("Oops! You'll be lucky next time\n");
    }
    getchar();
    return 0;
}
/******************************************************************************/
