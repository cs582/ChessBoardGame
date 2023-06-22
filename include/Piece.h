//
// Created by Carlos Salas Flores on 6/16/23.
//

#ifndef CHESSBOARDGAME_PIECE_H
#define CHESSBOARDGAME_PIECE_H

#include <SFML/Graphics.hpp>

class Piece {
public:
    char id;
    int x;
    int y;
    Piece();
    Piece(char, int, int);
    void set(char, int, int);
};

#endif //CHESSBOARDGAME_PIECE_H
