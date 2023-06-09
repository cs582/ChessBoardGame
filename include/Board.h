//
// Created by Carlos Salas Flores on 6/8/23.
//

#ifndef CHESSGAME_BOARD_H
#define CHESSGAME_BOARD_H

#include <string>

class Board {
private:
    static const int ROWS = 8; //Standard Chess Board Size
    static const int COLS = 8; //Standard Chess Board Size

    //Board array representation
    int board[ROWS][COLS];

    //Board string representation
    std::string boardString;

    //Keep track of the previous moves
    int prevPiece;
    int currPiece;

public:
    Board();
    void printBoard();
};

#endif //CHESSGAME_BOARD_H
