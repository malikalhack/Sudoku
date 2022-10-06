#include "Analysis.h"
#include "Logger.h"
#include <stdio.h>
#include <locale>
#include <stdlib.h>


#define BIT(offset)     (1 << (offset))

static inline void FindSquareLimits_(
    uint8_t * const start_x,
    uint8_t * const start_y,
    uint8_t const * const cx,
    uint8_t const * const cy
) {
    uint8_t reg_y = *cy / 3; //Integer division
    uint8_t reg_x = *cx / 3; //Integer division
    *start_y = reg_y * 3;
    *start_x = reg_x * 3;
}

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
    _solved = false;
    for (size_t i = 0; i < MAX_NUM; i++) _elements[i] = MAX_NUM;
    GeneratePuzzle_(level);
}

Sudoku::~Sudoku() {}

void Sudoku::Calculate() {
    info_print("Calculation started...");
    FillingOptionalValues_();
    Algorithm_();
    info_print("Calculation completed.\n");
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
    wprintf(L"║\n╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n\n");
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

    _elements[0] -= 5; //1
    _elements[1] -= 4; //2
    _elements[2] -= 2; //3
    _elements[3] -= 5; //4
    _elements[4] -= 5; //5
    _elements[5] -= 6; //6
    _elements[6] -= 3; //7
    _elements[7] -= 5; //8
    _elements[8] -= 3; //9
}

void Sudoku::FillingOptionalValues_() {
    for (uint8_t i = 0; i < VERTICAL_SIZE; i++) {
        for (uint8_t j = 0; j < HORIZONTAL_SIZE; j++) {
            for (uint8_t el = 0; el < MAX_NUM; el++) {
                if (_data[i][j].fixed) break;
                if (!CheckingCell_(&el, &j, &i)) {
                    void *temp = &_data[i][j].options;
                    *((uint16_t*)temp) |= (1 << el);
                }
            }
        }
    }
}


bool Sudoku::CheckingCell_(
    uint8_t const * const num,
    uint8_t const * const cx,
    uint8_t const * const cy
) {
    const uint8_t kNum = *num + 1;
    bool result = false;

    for (uint8_t i = 0; i < VERTICAL_SIZE; i++) {
            if (_data[i][*cx].fixed == kNum) {
            result = true;
            break;
        }
    }
    if (!result) {
        for (uint8_t i = 0; i < HORIZONTAL_SIZE; i++) {
            if (_data[*cy][i].fixed == kNum) {
                result = true;
                break;
            }
        }
        if (!result) {
            uint8_t start_x, start_y;
            FindSquareLimits_(&start_x, &start_y, cx, cy);
            for (uint8_t i = start_y; i < start_y + 3; i++) {
                if (result) break;
                for (uint8_t j = start_x; j < start_x + 3; j++) {
                    if (_data[i][j].fixed == kNum) {
                        result = true;
                        break;
                    }
                }
            }
        }
    }
    return result;
}

void Sudoku::CleaningField_() {

}

void Sudoku::FindTheOnlyOption_() {
    for (uint8_t i = 0; i < VERTICAL_SIZE; i++) {
        for (uint8_t j = 0; j < HORIZONTAL_SIZE; j++) {
            if (_data[i][j].fixed) continue;
            void *temp = &_data[i][j].options;
            if (!(*((uint16_t*)temp) & (*((uint16_t*)temp)-1))) {
                uint8_t result = 0;
                uint16_t value = *(uint16_t*)temp;
                while (value > 1u) {
                    value >>= 1u;
                    result++;
                }
                if (_elements[result]) {
                    _elements[result]--;
                    _data[i][j].fixed = result + 1;
                }
                else {
                    error_print("The program attempted to use the extra number %d", result + 1);
                    getchar();
                    exit(EXIT_FAILURE);

                }
                
            }
        }
    }
}

void Sudoku::Algorithm_() {
    FindTheOnlyOption_();
    /* ... */
    _solved = true;
}

bool Sudoku::IsSolved() {
    return _solved;
}
