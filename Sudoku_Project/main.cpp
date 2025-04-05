#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include "SudokuGenerator.hpp"
#include <iostream>
int main () {
    SudokuBoard game;
    game.print();
    SudokuGenerator::generate(game);
    // SudokuSolver::solve(game);
    std::cout<<"================================================"<<std::endl;
    game.print();
    SudokuGenerator::generate(game);
    // SudokuSolver::solve(game);
    std::cout<<"================================================"<<std::endl;
    game.print();
}