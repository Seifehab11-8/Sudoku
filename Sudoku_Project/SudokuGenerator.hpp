#ifndef SUDOKU_GENERATOR
#define SUDOKU_GENERATOR

#include "SudokuBoard.hpp"
constexpr int EASY = 32;
constexpr int MEDIUM = 46;
constexpr int HARD = 52;

class SudokuGenerator {
    private:
    std::vector<std::vector<int>> solved_board;
    bool back_track_generate(SudokuBoard &sudokuBoard, int row = 0, int col = 0);
    bool remove_to_level(SudokuBoard &sudokuBoard, int numOfRemoves);
    public:
    SudokuGenerator();
    int getCell(int row , int col)const;
    bool generate(SudokuBoard &sudokuBoard, std::string level);
};

#endif // !SUDOKU_GENERATOR