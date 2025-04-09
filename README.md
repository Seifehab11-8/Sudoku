# Sudoku Game

A C++ implementation of a Sudoku game that allows users to play, solve, and manage Sudoku puzzles. The project includes features for generating puzzles, solving them automatically, and saving/loading puzzles from files.

## Features

- **Start Menu**:
  - Retrieve a game from a file.
  - Generate a new Sudoku puzzle with difficulty levels: `easy`, `medium`, or `hard`.

- **Game Menu**:
  - Enter a move manually.
  - Solve the puzzle automatically using a Sudoku solver.
  - Load a puzzle from a file.
  - Save the current puzzle to a file.
  - Exit the game.

- **Persistence**:
  - Save and load puzzles to/from files for later use.

## How to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/<your-username>/Sudoku.git
   cd Sudoku/Sudoku_Project
   g++ -o SudokuGame SudokuGame.cpp SudokuBoard.cpp SudokuGenerator.cpp SudokuSolver.cpp
   ./SudokuGame
   Sudoku_Project/
├── [SudokuGame.cpp](http://_vscodecontentref_/0)        # Main game logic
├── [SudokuBoard.cpp](http://_vscodecontentref_/1)       # Handles the Sudoku board
├── [SudokuGenerator.cpp](http://_vscodecontentref_/2)   # Generates Sudoku puzzles
├── [SudokuSolver.cpp](http://_vscodecontentref_/3)      # Solves Sudoku puzzles
├── [SudokuGame.hpp](http://_vscodecontentref_/4)        # Header for game logic
├── [SudokuBoard.hpp](http://_vscodecontentref_/5)       # Header for board logic
├── [SudokuGenerator.hpp](http://_vscodecontentref_/6)   # Header for puzzle generation
├── [SudokuSolver.hpp](http://_vscodecontentref_/7)      # Header for puzzle solving
1) Retrieve game from file
2) Generate a game automatically
Choice: 2
Enter Game Difficulty 'easy', 'medium', 'hard': easy
==============================================
1) Enter a move
2) Solve automatically
3) Load puzzle from file
4) Save current puzzle to file
5) Exit
Choice: 1
Enter row (1-9), column (1-9), and value (1-9): 4 5 7
Move accepted!
