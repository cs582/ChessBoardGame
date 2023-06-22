#include <iostream>
#include "include/Chess.h"
#include <SFML/Window.hpp>

int main() {
    // run the program as long as the window is open
    //    Game game;
    //    game.run();
    int ROWS = 8;
    int COLS = 8;
    int fromX; int fromY; int toX; int toY;

    Chess chess(ROWS, COLS);
    chess.restart();

    while(!chess.gameOver()){
        // Show board in console
        chess.showInConsole();

        // Input numbers
        std::cin >> fromX >> fromY >> toX >> toY;

        // Read move to board
        if(!chess.readMove(fromX, fromY, toX, toY)) continue;

        // Switch player
        chess.switchPlayer();

        // Check if game over
        if(chess.gameOver()) chess.restart();
    }
    return 0;
}
