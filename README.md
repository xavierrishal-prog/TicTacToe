Mini Game Project — Tic Tac Toe (C++)

A console-based Tic Tac Toe game built in C++, demonstrating core programming concepts including loops, arrays, conditional logic, and replay functionality.

Overview

An interactive two-player Tic Tac Toe game with a dynamically updated board display, complete win/draw detection, input validation, and a replay option after each game.

Features


Dynamic Board Display — Board updates and re-renders after every move
Win Detection — Checks all rows, columns, and diagonals using loops
Draw Detection — Detects when all 9 cells are filled with no winner
Input Validation — Rejects invalid input and already-taken cells
Replay Option — Players can choose to play again after each game
Clean OOP Design — Game logic encapsulated in a TicTacToe class


Tech Stack


Language: C++ (C++11)
Concepts Used: Arrays (std::array), Loops, Conditional Logic, Classes, Input Validation


How to Compile & Run

bashg++ -std=c++11 TicTacToe.cpp -o tictactoe
./tictactoe

On Windows:

bashtictactoe.exe

Sample Board

     1   2   3
   ┌───┬───┬───┐
 1 │ X │ 2 │ O │
   ├───┼───┼───┤
 2 │ 4 │ X │ 6 │
   ├───┼───┼───┤
 3 │ 7 │ 8 │ X │
   └───┴───┴───┘

  ╔══════════════════════════════╗
  ║  Player X WINS! Congrats! ║
  ╚══════════════════════════════╝

Expected Outcome

An interactive game with dynamic board display, win/loss detection, and replay functionality, showcasing effective implementation of game logic.

Author

Developed as part of the Thiranex Internship Program.
