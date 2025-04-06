#ifndef SUDOKU_SOLVER
#define SUDOKU_SOLVER
#include "SudokuBoard.hpp"
class SudokuSolver {
    public:
    virtual void doSomething() = 0; // makes the class abstract as it doesn't contain any members
    static bool solve(SudokuBoard &sudokuBoard, int row = 0, int col = 0);
};
#endif // !SUDOKU_SOLVER
