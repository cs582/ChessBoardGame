//
// Created by Carlos Salas Flores on 6/16/23.
//
#include "../include/Board.h"
#include "../include/Piece.h"
#include <string>
#include <iostream>

Board::Board(int rows, int cols) : ROWS(), COLS(), whitePieces(), blackPieces() {
    ROWS = rows;
    COLS = cols;

    grid = new char*[rows];
    for(int i = 0; i < rows; i++)
        grid[i] = new char[cols];

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            grid[i][j] = ' ';

    totalBlack = 0;
    totalWhite = 0;
}

int Board::findPieceAt(int xPos, int yPos) {
    if(grid[yPos][xPos] >= 'a' & grid[yPos][xPos] <= 'z') return 1;
    if(grid[yPos][xPos] >= 'A' & grid[yPos][xPos] <= 'Z') return -1;
    return 0;
}

bool Board::moveFromTo(int xFromPos, int yFromPos, int xToPos, int yToPos) {
    if(grid[yToPos][xToPos] == ' '){
        grid[yToPos][xToPos] = grid[yFromPos][xFromPos];
        grid[yFromPos][xFromPos] = ' ';
        this->boardToString();
        return true;
    }
    return false;
}

void Board::createNewPiece(char piece, int xPos, int yPos) {
    if ('a' <= piece & 'z' >= piece){
        whitePieces.emplace_back(piece, xPos, yPos);
        totalWhite++;
    } else if ('A' <= piece & 'Z' >= piece){
        blackPieces.emplace_back(piece, xPos, yPos);
        totalBlack++;
    }
    std::cout << "Created New Piece" << piece << "@" << xPos << ", " << yPos << std::endl;
}

void Board::deletePiece(Piece piece) {
    char target = piece.id;
    int targetXPos = piece.x;
    int targetYPos = piece.y;

    int indexToErase = 0;

    if (piece.id >= 'a' & piece.id <= 'z'){

        for(int i = 0; i < whitePieces.size(); i++, indexToErase=i)
            if(whitePieces[i].id==target & whitePieces[i].x==targetXPos & whitePieces[i].y==targetYPos) break;

        whitePieces.erase(whitePieces.begin() + indexToErase);
        totalWhite--;
    } else {

        for(int i = 0; i < blackPieces.size(); i++, indexToErase=i)
            if(blackPieces[i].id==target & blackPieces[i].x==targetXPos & blackPieces[i].y==targetYPos) break;

        blackPieces.erase(blackPieces.begin() + indexToErase);
        totalBlack--;
    }

    std::cout << "Deleted Piece" << target << " @ x: " << targetXPos << " y: " << targetYPos << std::endl;
}

/* Helper Functions */
void Board::stringToBoard() {
    int currRow = 0;
    int currCol = 0;
    for( char c : str ) {
        if (c >= '1' and c <= '8'){
            currCol += int(c - '0');
        } else {
            grid[currRow][currCol++] = c;
            this->createNewPiece(c, currRow, currCol);
        }
        if (c == '/'){
            currRow++;
            currCol=0;
        }
    }
}

void Board::boardToString() {
    str = "";
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            str.append(&grid[i][j]);
        }
    }
}

void Board::setInitialSetup() {
    str = "rbnqknbr/pppppppp/8/8/8/8/PPPPPPPP/RBNQKNBR";
    stringToBoard();
}

void Board::update() {
    boardToString();
}


void Board::showBoardInConsole() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if (grid[i][j] != ' ') {
                std::cout << grid[i][j];
            } else {
                char nothing = (i+j)%2 == 0 ? '#' : ' ';
                std::cout << nothing;
            }
        }
        std::cout << std::endl;
    }
}