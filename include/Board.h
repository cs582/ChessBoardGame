//
// Created by Carlos Salas Flores on 6/16/23.
//

#ifndef CHESSBOARDGAME_BOARD_H
#define CHESSBOARDGAME_BOARD_H

#include <string>
#include <vector>
#include "../include/Piece.h"

class Board {
private:
    char** grid;
    int ROWS;
    int COLS;

    std::vector<Piece> blackPieces;
    std::vector<Piece> whitePieces;

    int totalBlack;
    int totalWhite;

    std::string str;
    void boardToString();
    void stringToBoard();
    void createNewPiece(char, int, int);
    void deletePiece(Piece);
    void update();
public:
    Board(int, int);
    void setInitialSetup();
    void showBoardInConsole();
    int findPieceAt(int, int);
    bool moveFromTo(int, int, int, int);
};

#endif //CHESSBOARDGAME_BOARD_H
