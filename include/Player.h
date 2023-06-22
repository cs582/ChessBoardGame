//
// Created by Carlos Salas Flores on 6/16/23.
//

#ifndef CHESSBOARDGAME_PLAYER_H
#define CHESSBOARDGAME_PLAYER_H

#include "../include/Board.h"
#include "../include/Piece.h"
#include <SFML/Graphics.hpp>

static const int MAX = 100;

class Player {
public:
    char id;
    Player(char);
};

#endif //CHESSBOARDGAME_PLAYER_H
