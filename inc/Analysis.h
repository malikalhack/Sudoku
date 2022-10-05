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
    bool IsSolved();
private:
    struct data_t {
        struct options_t {
            uint16_t one    : 1;
            uint16_t two    : 1;
            uint16_t three  : 1;
            uint16_t four   : 1;
            uint16_t five   : 1;
            uint16_t six    : 1;
            uint16_t seven  : 1;
            uint16_t eight  : 1;
            uint16_t nine   : 1;
            uint16_t reserv : 7;
        } options;
        uint8_t fixed;
    } _data[9][9] = {};

    struct elements_t {
        uint8_t one;
        uint8_t two;
        uint8_t three;
        uint8_t four;
        uint8_t five;
        uint8_t six;
        uint8_t seven;
        uint8_t eight;
        uint8_t nine;
    } _elements;

    bool _solved;
    bool _filled;

    void GeneratePuzzle_(complexity);
    void FillingFields_();
    void CheckingFields_();
    void CleaningFields_();
    void Algorithm_();
};

#endif // !ANALYSIS_H_
