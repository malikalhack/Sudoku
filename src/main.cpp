#include "Analysis.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Sudoku puzzle(EASY);
    puzzle.Print();
    puzzle.Calculate();
    puzzle.Print();
    getchar();
    return 0;
}
