#include "SudokuBoard.hpp"
#include "SudokuGenerator.hpp"
#include "SudokuGame.hpp"
#include <iostream>
int main () {
    SudokuBoard board;
    SudokuGenerator generator;
    SudokuGame game(board, generator);
    game.start();
}