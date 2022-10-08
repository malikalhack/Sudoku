/**
 * @file    main.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    02/10/2022
 * @date    08/10/2022
 */
#define ALLOW_TEST_WITH_EASY_PUZZLE     (true)
#define ALLOW_TEST_WITH_NORMAL_PUZZLE   (false)
#define ALLOW_TEST_WITH_HARD_PUZZLE     (false)
#define ALLOW_TEST_WITH_EXPERT_PUZZLE   (false)
/****************************** Included files ********************************/
#include "Analysis.h"
#include <stdio.h>
/****************************** Private  functions ****************************/
void CheckPuzzle(Sudoku * puzzle) {
    if (puzzle->IsSolved()) {
        printf("Puzzle is solved\nThe number of cycles is: %u\n", puzzle->cycles);
        puzzle->Print();
    }
    else {
        printf("Oops! You'll be lucky next time\n");
    }
}
/********************************* Entry point ********************************/
int main(int argc, char *argv[]) {
#if ALLOW_TEST_WITH_EASY_PUZZLE
    Sudoku easy_puzzle(EASY);
    easy_puzzle.Print();
    easy_puzzle.Calculate();
    CheckPuzzle(&easy_puzzle);
#endif // ALLOW_TEST_WITH_EASY_PUZZLE

#if ALLOW_TEST_WITH_NORMAL_PUZZLE
    Sudoku normal_puzzle(NORMAL);
    normal_puzzle.Print();
    normal_puzzle.Calculate();
    CheckPuzzle(&normal_puzzle);
#endif // ALLOW_TEST_WITH_NORMAL_PUZZLE

#if ALLOW_TEST_WITH_HARD_PUZZLE
    Sudoku hard_puzzle(HARD);
    hard_puzzle.Print();
    hard_puzzle.Calculate();
    CheckPuzzle(&hard_puzzle);
#endif // ALLOW_TEST_WITH_HARD_PUZZLE

#if ALLOW_TEST_WITH_EXPERT_PUZZLE
    Sudoku expert_puzzle(EXPERT);
    expert_puzzle.Print();
    expert_puzzle.Calculate();
    CheckPuzzle(&expert_puzzle);
#endif // ALLOW_TEST_WITH_EXPERT_PUZZLE

    getchar();
    return 0;
}
/******************************************************************************/
