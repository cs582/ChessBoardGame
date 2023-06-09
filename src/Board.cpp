//
// Created by Carlos Salas Flores on 6/8/23.
//

#include "../include/Board.h"
#include <iostream>

//Constructor
Board::Board() : board() {
    boardString = "8/8/8/8/8/8/8/8";

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = 0;
        }
    }

    currPiece = -1;
    prevPiece = -1;
}

// Print board prints the current state of the board
void Board::printBoard() {
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
