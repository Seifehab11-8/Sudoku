#include "SudokuBoard.hpp"
#include <fstream>
#include <iostream>
#include <set>

SudokuBoard::SudokuBoard():board(ROW, std::vector<int>(COL))
{
    for(auto &row: board) {
        std::fill(row.begin(), row.end(), 0);
    }
    // initially fills the whole board with zeroes
}

SudokuBoard::SudokuBoard(const std::string path):SudokuBoard()
{
    // Constructor delegates to default constructor first, then tries to load
    if (!loadPuzzle(path)) {
        std::cerr << "Failed to load puzzle from file '" << path << "'. Using empty board.\n";
    }
}

SudokuBoard::SudokuBoard(const SudokuBoard &other)
{
    board = other.board;
}

bool SudokuBoard::setCell(int row, int col, int value)
{
    if(!((row >= 0 && row < ROW) && (col >= 0 && col < COL))) return false;
    else if(board.at(row).at(col) != 0) return false;
    
    /*
        sub grid check
    */
    for(int i = (row/3)*3; i < ((row/3)*3)+3; i++) {
        for(int j = (col/3)*3; j < ((col/3)*3)+3; j++) {
            if(i == row && j == col) continue;
            if(value == board.at(i).at(j)) {
                return false;
            }
        }
    }
    /*
        row check
    */
    for(int i = 0; i < COL; i++) {
        if(i == col) continue;
        if(value == board.at(row).at(i)) return false;
    }
    /*
        col check
    */
    for(int i = 0; i < ROW; i++) {
        if(i == row) continue;
        if(value == board.at(i).at(col)) return false;
    }

    board.at(row).at(col) = value;
    return true;
}

int SudokuBoard::getCell(int row, int col) const
{
    return ((row >= 0 && row < ROW) && (col >= 0 && col < COL)) ? board.at(row).at(col) : -1;
}

void SudokuBoard::undoCell(int row, int col)
{
    if((row >= 0 && row < ROW) && (col >= 0 && col < COL)) {
        board.at(row).at(col) = 0;
    }
}

void SudokuBoard::erase_all()
{
    for(auto &row: board) {
        std::fill(row.begin(), row.end(), 0);
    }
}

bool SudokuBoard::loadPuzzle(const std::string path)
{
    std::ifstream ifs;
    bool successFlag = false;
    try {
        ifs.open(path);
        /*
        Check for non existing files
        */
        if (!ifs.is_open()) {
            std::cerr << "Error: Unable to open file '" << path << "'.\n";
            return false;
        }
        ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        std::string temp_str;
        /*
            sudoku board should be stored as a 81 char line containing the cells in row by row order
        */
        std::getline(ifs, temp_str);
        /*
            Copy process of the string to the board
        */
        int temp_str_index = 0;
        for(auto &board_row: board) {
            if(temp_str_index >= temp_str.length()) break;
            for(auto &cell: board_row) {
                if(temp_str[temp_str_index] >= '0' && temp_str[temp_str_index] <= '9') {
                    cell = temp_str[temp_str_index] - '0';
                }
                temp_str_index++;
            }
        }
        successFlag = true;
    }catch (const std::ios_base::failure &e) {
        std::cerr << e.what();
    } 
    ifs.close();
    return successFlag;
}

bool SudokuBoard::savePuzzle(const std::string path) const
{
    std::ofstream ofs;
    bool successFlag = false;
    try {
        ofs.open(path);
        if (!ofs.is_open()) {
            std::cerr << "Error: Unable to create/open file '" << path << "' for writing.\n";
            return false;
        }
        ofs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        std::string temp_str;
        /*
            sudoku board should be stored as a 81 char line containing the cells in row by row order
        */
        for(auto board_row : board) {
            for(auto cell : board_row) {
                temp_str += (cell + 48);
            }
        }
        ofs << temp_str; // puzzle is saved to file to track progress
        successFlag = true;
    }catch (const std::ios_base::failure &e) {
        std::cerr << e.what();
    } 
    ofs.close();
    return successFlag;
}

bool SudokuBoard::validateBoard()
{
    /*
        Check the board for any violations
        !but it doesn't check if it is solvable or not
    */
    for(int k = 0; k < ROW; k++) {
        for(int h = 0; h < COL; h++) {
                /*
                    sub grid check
                */
                if(board.at(k).at(h) == 0) continue;
                for(int i = (k/3)*3; i < ((k/3)*3)+3; i++) {
                    for(int j = (h/3)*3; j < ((h/3)*3)+3; j++) {
                        if(i == k && j == h) continue;
                        if(board.at(k).at(h) == board.at(i).at(j)) {
                            return false;
                        }
                    }
                }
                /*
                    row check
                */
                for(int i = 0; i < COL; i++) {
                    if(i == h) continue;
                    if(board.at(k).at(h) == board.at(k).at(i)) return false;
                }
                /*
                    col check
                */
                for(int i = 0; i < ROW; i++) {
                    if(i == k) continue;
                    if(board.at(k).at(h) == board.at(i).at(h)) return false;
                }
        }
    }
    return true;
}

bool SudokuBoard::is_solved()
{
    for(auto vec: board) {
        for(auto cell: vec) {
            if(cell == 0) return false;
        }
    }
    return true;
}

void SudokuBoard::print() const
{
    int col_separator = 0;
    std::cout << std::endl;
    std::cout << "---------------------";
    std::cout << std::endl;
    for(const auto &board_row : board) {
        int row_separator = 0;
        for(const auto &cell : board_row) {
            if((row_separator) % 3 == 0 && row_separator != 0) {
                std::cout << "| ";
            }

            if(cell == 0) {
                std::cout << ". ";
            }
            else {
                std::cout << cell <<" ";
            }
            row_separator++;
        }
        std::cout << std::endl;
        col_separator++;
        if((col_separator) % 3 == 0 && col_separator != COL) {
            std::cout << "------+-------+------";
            std::cout << std::endl;
        }
    }
    std::cout << "---------------------";
    std::cout << std::endl;
    std::cout << std::endl;
}
