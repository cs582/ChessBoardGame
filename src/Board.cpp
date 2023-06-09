//
// Created by Carlos Salas Flores on 6/8/23.
//
#include "../include/Board.h"
#include <iostream>

//Constructor
Board::Board() : board(), white() {
    boardString = "8/8/8/8/8/8/8/8";

    // White board for human visualization
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if ( (i*ROWS + j) % 2 != (i%2) ){
                white[i][j] = '#';
            } else {
                white[i][j] = '_';
            }
        }
    }

    // Actual board
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = ' ';
        }
    }

    prevMove = '#';
}

// Print board prints the current state of the board
void Board::printHumanVisualBoard() {
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if (board[i][j] == ' ') {
                std::cout << white[i][j] << ' ';
            } else {
                std::cout << board[i][j] << ' ';
            }

        }
        std::cout << std::endl;
    }
}

// Read string to chess board
void Board::readString(std::string boardRepresentation) {

    int j = 0;
    int i = 0;

    for(int p = 0; p < boardRepresentation.length(); p++){
        char curr = boardRepresentation[p];
        std::cout << "curr:" << curr << std::endl;

        if (curr == '/') {
            j++;
            i=0;
        } else if (curr >= '1' && curr <= '8') {
            i += int(curr - '0');
        } else {
            board[j][i++] = curr;
        }
    }

}

// Set the initial state of the board
void Board::newGame() {
    // Board string state
    boardString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    readString(boardString);
    prevMove = '#';
}

// Update board current state
//void Board::update() {
//    for(int i = 0; i < boardString.length(); i++){
//    }
//}