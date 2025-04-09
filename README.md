# Sudoku Game

A C++ implementation of a Sudoku game with puzzle generation, solving, and interactive gameplay features.

## Features

- Interactive command-line interface
- Multiple difficulty levels (Easy, Medium, Hard)
- Puzzle generation with unique solutions
- Automatic puzzle solver
- Save/Load game progress
- Manual move entry with validation
- Board state validation

## Game Modes

1. **Load from File**: Load an existing Sudoku puzzle from a file
2. **Auto Generation**: Generate a new puzzle with selected difficulty
   - Easy: 32 empty cells
   - Medium: 46 empty cells
   - Hard: 52 empty cells

## Gameplay Options

- Enter moves manually
- Auto-solve the current puzzle
- Save current game state
- Load saved game
- Exit game

## Class Structure

- **SudokuBoard**: Handles the game board state and operations
- **SudokuGenerator**: Generates new valid Sudoku puzzles
- **SudokuSolver**: Implements solving algorithm
- **SudokuGame**: Manages game flow and user interaction

## Building the Project

To compile the project:

```bash
g++ -std=c++11      -o sudoku
