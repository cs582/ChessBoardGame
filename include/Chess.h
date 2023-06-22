//
// Created by Carlos Salas Flores on 6/16/23.
//

#ifndef CHESSBOARDGAME_CHESS_H
#define CHESSBOARDGAME_CHESS_H

#include "../include/Board.h"
#include "../include/Piece.h"
#include "../include/Player.h"
#include <SFML/Graphics.hpp>
#include <string>

class Chess {
private:
    int ROWS;
    int COLS;

    Board board;

    Player white;
    Player black;
    Player* currentPlayer;

    char currentState;
    std::string gameState;

    void checkpoint();
    void updateState();
public:
    Chess(int, int);

    int result;

    void restart();
    void switchPlayer();
    void showInConsole();
    bool readMove(int, int, int, int);
    bool gameOver();
};

#endif //CHESSBOARDGAME_CHESS_H
