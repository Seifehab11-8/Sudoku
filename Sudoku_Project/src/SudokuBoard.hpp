#ifndef SUDOKU_BOARD
#define SUDOKU_BOARD

#include <vector>
#include <string>

constexpr int ROW = 9;
constexpr int COL = 9;

class SudokuBoard {
    private:
    std::vector<std::vector<int>> board;
    public:
    SudokuBoard ();
    SudokuBoard (const std::string path);
    SudokuBoard (const SudokuBoard& other);
    bool setCell(int row, int col, int value);
    int getCell(int row, int col)const;
    void undoCell(int row, int col);
    void erase_all();
    bool loadPuzzle(const std::string path);
    bool savePuzzle(const std::string path)const;
    bool validateBoard();
    bool is_solved();
    void print() const;
};
#endif // !SUDOKU_BOARD