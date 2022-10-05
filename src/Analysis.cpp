#include "Analysis.h"
#include <stdio.h>
#include <locale>

#define VERTICAL_SIZE   (9)
#define HORIZONTAL_SIZE (9)
/*
╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗
║ 6 │ 4 │   ║ 8 │ 3 │ 1 ║ 5 │ 2 │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║   │   │ 1 ║ 6 │ 7 │ 2 ║ 8 │ 9 │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ 8 │   │ 7 ║ 5 │ 4 │   ║ 1 │ 6 │   ║
╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣
║   │   │   ║ 1 │ 5 │   ║   │ 8 │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║   │   │   ║   │   │ 6 ║   │   │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ 7 │ 5 │   ║   │   │   ║   │   │ 6 ║
╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣
║   │ 6 │ 2 ║ 4 │ 1 │   ║   │   │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║   │   │ 4 ║ 9 │ 2 │   ║   │   │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║   │ 8 │ 5 ║   │   │ 3 ║   │ 4 │ 9 ║
╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝
*/

Sudoku::Sudoku(complexity level) {
    _solved         = false;
    _elements.one   = 9;
    _elements.two   = 9;
    _elements.three = 9;
    _elements.four  = 9;
    _elements.five  = 9;
    _elements.six   = 9;
    _elements.seven = 9;
    _elements.eight = 9;
    _elements.nine  = 9;

    GeneratePuzzle_(level);
}

Sudoku::~Sudoku() {}

void Sudoku::Calculate() {
    printf("\nCalculation started...\t");
    //Algorithm
    printf("Completed\n\n");
}

void Sudoku::Print() {
    setlocale(LC_ALL, "Russian_Russia.20866");
    wprintf(L"╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
    for (size_t vert = 0; vert < VERTICAL_SIZE; vert++) {
        for (size_t horiz = 0; horiz < HORIZONTAL_SIZE; horiz++) {
            if (horiz % 3) {
                wprintf(L"│");
            }
            else {
                wprintf(L"║");
            }
            if (_data[vert][horiz].fixed) {
                printf(" %u ", _data[vert][horiz].fixed);
            }
            else {
                printf("   ");
            }
        }
        if ((vert + 1) % 3) {
            wprintf(L"║\n╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        }
        else if (vert != VERTICAL_SIZE - 1){
            wprintf(L"║\n╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        }
    }
    wprintf(L"║\n╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
}

/**
 * @todo
 */
void Sudoku::GeneratePuzzle_(complexity level) {
    (void)level;
    _data[0][0].fixed = 6;
    _data[0][1].fixed = 4;
    _data[0][3].fixed = 8;
    _data[0][4].fixed = 3;
    _data[0][5].fixed = 1;
    _data[0][6].fixed = 5;
    _data[0][7].fixed = 2;

    _data[1][2].fixed = 1;
    _data[1][3].fixed = 6;
    _data[1][4].fixed = 7;
    _data[1][5].fixed = 2;
    _data[1][6].fixed = 8;
    _data[1][7].fixed = 9;

    _data[2][0].fixed = 8;
    _data[2][2].fixed = 7;
    _data[2][3].fixed = 5;
    _data[2][4].fixed = 4;
    _data[2][6].fixed = 1;
    _data[2][7].fixed = 6;

    _data[3][3].fixed = 1;
    _data[3][4].fixed = 5;
    _data[3][7].fixed = 8;

    _data[4][5].fixed = 6;

    _data[5][0].fixed = 7;
    _data[5][1].fixed = 5;
    _data[5][8].fixed = 6;

    _data[6][1].fixed = 6;
    _data[6][2].fixed = 2;
    _data[6][3].fixed = 4;
    _data[6][4].fixed = 1;

    _data[7][2].fixed = 4;
    _data[7][3].fixed = 9;
    _data[7][4].fixed = 2;

    _data[8][1].fixed = 8;
    _data[8][2].fixed = 5;
    _data[8][5].fixed = 3;
    _data[8][7].fixed = 4;
    _data[8][8].fixed = 9;
}
void Sudoku::FillingFields_() {

}

void Sudoku::CleaningFields_() {

}

void Sudoku::Algorithm_() {

}

bool Sudoku::IsSolved() {
    return _solved;
}
