//
// Created by Carlos Salas Flores on 6/16/23.
//

#ifndef CHESSBOARDGAME_GAME_H
#define CHESSBOARDGAME_GAME_H

#include "../include/Chess.h"
#include <SFML/Graphics.hpp>

class Game {
private:
    static const int W = 1200;
    static const int H = 1200;

    static const int ROWS = 8;
    static const int COLS = 8;

    static const int boxH = int(H/ROWS);
    static const int boxW = int(W/COLS);

    Chess chess;

    void newGame();
    void createBackground();
    void hearMouseEvents(sf::Event);
    void highlightSquare();
    void movePieceAround();
    void mapToBoard(int, int, int*, int*);
    int result();

public:
    sf::RenderWindow window;
    Game();
    void run();
};

#endif //CHESSBOARDGAME_GAME_H
