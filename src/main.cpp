#include "Analysis.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Sudoku puzzle(EASY);
    puzzle.Print();
    puzzle.Calculate();
    if (puzzle.IsSolved()) {
        printf("Puzzle is solved\n");
        puzzle.Print();
    }
    else {
        printf("Oops! You'll be lucky next time\n");
    }
    getchar();
    return 0;
}
