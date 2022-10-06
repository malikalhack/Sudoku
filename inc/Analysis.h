#ifndef ANALYSIS_H_
#define ANALYSIS_H_

#include <cstdint>
#define MAX_NUM         (9)
#define VERTICAL_SIZE   MAX_NUM
#define HORIZONTAL_SIZE MAX_NUM

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
    } _data[VERTICAL_SIZE][HORIZONTAL_SIZE] = {};

    uint8_t _elements[MAX_NUM];

    bool _solved;

    void GeneratePuzzle_(complexity);
    bool CheckingCell_(
        uint8_t const * const,
        uint8_t const * const,
        uint8_t const * const
    );
    void FillingOptionalValues_();
    void FindTheOnlyOption_();
    void CleaningField_();
    void Algorithm_();
};

#endif // !ANALYSIS_H_
