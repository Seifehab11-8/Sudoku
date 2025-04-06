#ifndef SUDOKU_GAME
#define SUDOKU_GAME
#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include "SudokuGenerator.hpp"
class SudokuGame {
    private:
    SudokuBoard &sudokuBoard;
    SudokuGenerator &sudokuGenerator;
    bool startMenu();
    bool gameMenu();
    bool enterMove();
    bool load();
    bool save();
    public:
    SudokuGame(SudokuBoard &sudoku, SudokuGenerator &generator);
    void start();
};

#endif
