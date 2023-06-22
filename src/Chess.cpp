//
// Created by Carlos Salas Flores on 6/16/23.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Chess.h"

Chess::Chess(int rows, int cols) : white('w'), black('b'), currentState(1), board(rows, cols), result(0) {
    std::cout << "Chess Constructor Called" << std::endl;
    currentPlayer = &white;
    std::cout << "Chess Constructor Done!" << std::endl;
}

/* restart the game */
void Chess::restart() {
    std::cout << "Called restart" << std::endl;
    board.setInitialSetup();
    currentPlayer = &white;
    std::cout << "Done with restart" << std::endl;
}

/* read next move */
bool Chess::readMove(int xFromPos, int yFromPos, int xToPos, int yToPos) {
    std::cout << "Called move" << std::endl;

    // Find piece for right player
    int found = board.findPieceAt(xFromPos, yFromPos);
    char currPlayer = currentPlayer->id;
    std::cout << found << " " << currPlayer << std::endl;
    if((found==1 & currPlayer=='w') | (found==-1 & currPlayer=='b')) {
        std::cout << "Piece Found (from)" << std::endl;
    } else {
        std::cout << "Piece Not Found (from)" << std::endl;
        return false;
    }

    // if not a valid move then return false
    if(!board.moveFromTo(xFromPos, yFromPos, xToPos, yToPos)){
        std::cout << "Space Not Found (to)" << std::endl;
        return false;
    } else {
        std::cout << "Space Found (to)" << std::endl;
    }

    // Update the state of the board
    this->updateState();

    // Saving checkpoint
    checkpoint();

    std::cout << "Done with move" << std::endl;

    return true;
}

/* Switch player */
void Chess::switchPlayer() {
    std::cout << "Called switchPlayer" << std::endl;
    currentPlayer = &white == currentPlayer ? &black : &white;
    std::cout << "Done with switchPlayer" << std::endl;
}

/* update the current state of the game */
void Chess::updateState() {
    /*
     0: Ongoing
     1: White Won
     -1: Black Won
     11: Draw
     12: Dead Position
     * */

    // Check if white won

    // Check if black won

    // Check if Draw

    // Check if Dead Position

    result=0;
}


/* Check if the game is over*/
bool Chess::gameOver() {
    /* check the result depending on the current state */

    std::cout << "Game Over" << std::endl;
    return false;
}

void Chess::checkpoint() {
    return;
}

void Chess::showInConsole() {
    board.showBoardInConsole();
}