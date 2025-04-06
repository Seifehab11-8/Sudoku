#include "SudokuGame.hpp"
#include <iostream>

bool SudokuGame::startMenu()
{
    int option = 0;
    std::cout<<"1) Retrive game from file"<<std::endl;
    std::cout<<"2) Generate a game automatically"<<std::endl;
    std::cout<<"Choice: ";
    std::cin>>option;
    std::cout<<"=============================================="<<std::endl;

    std::string diffculty;
    switch(option) {
        case 1:
            if(load()) {
                std::cout<<"Board is loaded successfully."<<std::endl;
            }
            else {
                std::cout<<"Board failed to load."<<std::endl;
            }
            break;
        case 2:
            std::cout<<"Enter Game Diffculty 'easy', 'medium', 'hard': "<<std::flush;
            getchar();
            getline(std::cin, diffculty);
            sudokuGenerator.generate(sudokuBoard, diffculty);
            break;
        default:
            return false;
    }
    return true;
}

bool SudokuGame::gameMenu()
{
    int option = 0;
    while(true){
        sudokuBoard.print();
        std::cout<<"1) Enter a move"<<std::endl;
        std::cout<<"2) Solve automatically"<<std::endl;
        std::cout<<"3) Load puzzle from file"<<std::endl;
        std::cout<<"4) Save current puzzle to file"<<std::endl;
        std::cout<<"5) Exit"<<std::endl;
        std::cout<<"Choice: ";
        std::cin>>option;
        switch (option) {
            case 1:
                if(enterMove()) {
                    std::cout<<"Move accepted!"<<std::endl;
                }
                else {
                    std::cout<<"Invalid move. That cell might be occupied or the placement breaks Sudoku rules."<<std::endl;
                }
                break;
            case 2:
                SudokuSolver::solve(sudokuBoard);
                sudokuBoard.print();
                std::cout<<"Great job! The Sudoku is solved!"<<std::endl;
                return true;
            case 3:
                if(load()) {
                    std::cout<<"Board is loaded successfully."<<std::endl;
                }
                else {
                    std::cout<<"Board failed to load."<<std::endl;
                }
                break;
            case 4:
                if(save()) {
                    std::cout<<"Board is saved successfully."<<std::endl;
                }
                else {
                    std::cout<<"Save failed try again."<<std::endl;
                }
                break;
            case 5:
                std::cout<<"Thanks For Playing . . ."<<std::endl;
                return true;
            default:
                return false;
        }
    }
    return true;
}

bool SudokuGame::enterMove()
{
    int row = 0, col = 0, value = 0;
    std::cout<<"Enter row (1-9), column (1-9), and value (1-9): ";
    std::cin>>row>>col>>value;
    return sudokuBoard.setCell(row, col, value);
}

bool SudokuGame::load()
{
    std::string path;
    std::cout<<"Enter File Path: ";
    getline(std::cin, path);
    return sudokuBoard.loadPuzzle(path);
}

bool SudokuGame::save()
{
    std::string path;
    std::cout<<"Enter File Path: ";
    getline(std::cin, path);
    return sudokuBoard.savePuzzle(path);
}

SudokuGame::SudokuGame(SudokuBoard &sudoku, SudokuGenerator &generator):sudokuBoard(sudoku), sudokuGenerator(generator){}

void SudokuGame::start()
{
    char option = 0;
    while(true) {
        while(startMenu() == 0) {
            std::cout<<"No Option Choosen try again"<<std::endl;
        }
        while(gameMenu() == 0) {
            std::cout<<"No Option Choosen try again"<<std::endl;
        }
        std::cout<<"Do you want to Play Again (yes(y) / no(n)): ";
        std::cin>>option;
        if(option == 'n') {
            break;
        }
    }
}

