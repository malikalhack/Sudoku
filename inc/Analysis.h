/**
 * @file    Analysis.h
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    02/10/2022
 * @date    08/10/2022
 */
#ifndef ANALYSIS_H_
#define ANALYSIS_H_
 /****************************** Included files ********************************/
#include <cstdint>
/******************************** Definition **********************************/
#define MAX_NUM         (9u)
#define VERTICAL_SIZE   MAX_NUM
#define HORIZONTAL_SIZE MAX_NUM

typedef enum {
    EASY = 0,
    NORMAL,
    HARD,
    EXPERT
} complexity;
/******************************* Class definition *****************************/
class Sudoku {
public:
    uint8_t cycles; ///< The number of passed cycles

    Sudoku(complexity);
    ~Sudoku();

    /** */
    void Calculate();

    /** */
    void Print();

    /** */
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

    /** */
    void GeneratePuzzle_(complexity);
    
    /** */
    void CheckingSolved_();

    /** */
    bool CheckingCell_(
        uint8_t const * const,
        uint8_t const * const,
        uint8_t const * const
    );

    /** */
    void CleaningSelectedValue_(
        uint8_t const * const,
        uint8_t const * const,
        uint8_t const * const
    );

    /** */
    void FillingOptionalValues_();

    /** */
    void FindTheOnlyOption_();

    /** */
    void OptimizeBoard_();

    /** */
    void Algorithm_();
};
/******************************************************************************/
#endif // !ANALYSIS_H_
