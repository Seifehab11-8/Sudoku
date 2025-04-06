#include "SudokuGenerator.hpp"
#include "SudokuSolver.hpp"
#include <algorithm> // Required for std::shuffle
#include <vector>
#include <random>
#include <iostream>

bool SudokuGenerator::back_track_generate(SudokuBoard &sudokuBoard, int row, int col)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    /*
        shuffle a vector from 1 to 9 to have a unique generated board each time
    */
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    if(col  == COL) {
        return back_track_generate(sudokuBoard, row+1);
    }
    if(row == ROW) {
        return true;
    }

    for(auto element: vec) {
        if(sudokuBoard.setCell(row, col, element)) {
            solved_board.at(row).at(col) = element; // save the solved board in the generator
            if(back_track_generate(sudokuBoard, row, col +1)) {
                return true;
            }
        }
        else {
            sudokuBoard.undoCell(row, col);
        }
    }
    return false;
}

SudokuGenerator::SudokuGenerator():solved_board(ROW, std::vector<int>(COL))
{
    for(auto&vec: solved_board) {
        for(auto&cell: vec) {
            cell = 0;
        }
    }
}

int SudokuGenerator::getCell(int row, int col) const
{
    if(row < 0 || row > 9 || col < 0 || col > 9) return -1;
    return solved_board.at(row).at(col);
}

bool SudokuGenerator::generate(SudokuBoard &sudokuBoard, std::string level)
{
    sudokuBoard.erase_all();
    back_track_generate(sudokuBoard);
    std::transform(level.begin(), level.end(), level.begin(), ::tolower);
    if(level.compare("easy") == 0) {
        remove_to_level(sudokuBoard, EASY);
    }
    else if (level.compare("medium") == 0) {
        remove_to_level(sudokuBoard, MEDIUM);
    }
    else if(level.compare("hard") == 0) {
        remove_to_level(sudokuBoard, HARD);
    }
    else {
        std::cout<<"ERROR in Generation"<<std::endl;
    }
    return true;
}

void SudokuGenerator::print_soln() const
{
    for(auto row: solved_board) {
        for(auto cell: row) {
            std::cout<<cell;
        }
        std::cout<<std::endl;
    }
}

void SudokuGenerator::erase_all()
{
    for(auto &row: solved_board) {
        for(auto &cell: row) {
            cell = 0;
        }
    }
}

bool SudokuGenerator::remove_to_level(SudokuBoard &sudokuBoard, int numOfRemoves)
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dist(0, vec.size()-1);
    int temp = 0;
    int row = 0;
    int col = 0;
    while(numOfRemoves != 0) {
        row = dist(g);
        col = dist(g);
        SudokuBoard temp = sudokuBoard;
        if(sudokuBoard.getCell(row, col) == 0) continue;
        temp.undoCell(row, col);
        if(SudokuSolver::solve(temp)) {
            if(temp.getCell(row, col) == solved_board.at(row).at(col)) {
                sudokuBoard.undoCell(row, col);
                numOfRemoves--;
            }
        }
    }
    return true;
}
