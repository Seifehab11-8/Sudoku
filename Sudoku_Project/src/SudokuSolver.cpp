#include "SudokuSolver.hpp"
#include <random>

bool SudokuSolver::solve(SudokuBoard &sudokuBoard, int row, int col)
{
    if(col == COL) {
        return solve(sudokuBoard, row + 1);
    }
    if(row == ROW) return true;
    if(sudokuBoard.getCell(row, col) != 0) {
        return solve(sudokuBoard, row, col+1);
    }
    for(int i = 1; i <= 9 ; i++) {

        if(sudokuBoard.setCell(row, col, i)) {
            if(solve(sudokuBoard, row, col+1)) {
                return true;
            }
            else {
                sudokuBoard.undoCell(row, col);
            }
        }
    }
    return false;
}