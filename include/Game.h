//
// Created by Carlos Salas Flores on 6/8/23.
//

#ifndef CHESSGAME_GAME_H
#define CHESSGAME_GAME_H

class Game {
private:
    Board board;
    Player player1;
    Player player2;

public:
    Game();
    void hearNextMove();
    void changePlayer();
    void showBoard();
};


#endif //CHESSGAME_GAME_H
