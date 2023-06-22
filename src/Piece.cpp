//
// Created by Carlos Salas Flores on 6/16/23.
//

#include "../include/Piece.h"

Piece::Piece() : id(), x(), y() {
    id = 'd';
    x = -1;
    y = -1;
}

Piece::Piece(char pieceId, int xPos, int yPos) : id(), x(), y() {
    id = pieceId;
    x = xPos;
    y = yPos;
}

void Piece::set(char pieceId, int xPos, int yPos) {
    id = pieceId;
    x = xPos;
    y = yPos;
}