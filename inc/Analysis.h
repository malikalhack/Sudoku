#ifndef ANALYSIS_H_
#define ANALYSIS_H_

#include <cstdint>

typedef enum {
    EASY = 0,
    NORMAL,
    HARD,
    COMPLEXITY_LIMIT
} complexity;

class Sudoku {
public:
    Sudoku(complexity);
    ~Sudoku();
    void Calculate();
    void Print();
    bool Is_solved();
private:
    bool solved;
    struct data_t {
        uint8_t options[9];
        uint8_t fixed;
    } data[9][9] = {};
    void Generate(complexity);
};

#endif // !ANALYSIS_H_

