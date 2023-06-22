//
// Created by Carlos Salas Flores on 6/16/23.
//
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../include/Game.h"

sf::Color darkColor(sf::Color(68, 55, 66));
sf::Color lightColor(sf::Color(255, 185, 151));

Game::Game() : chess(ROWS, COLS) {
    std::cout << "Initializing Game" << std::endl;

    // Creating window
    window.create(sf::VideoMode(W, H), "Chess");

    // Creating background
    createBackground();

    std::cout << "Initialized Game" << std::endl;
};

void Game::createBackground() {
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            sf::RectangleShape rectangle(sf::Vector2f(boxW, boxH));
            rectangle.setPosition(sf::Vector2f(i*boxW, j*boxH));
            if ((i+j) % 2 == 1){
                rectangle.setFillColor(lightColor);
            } else {
                rectangle.setFillColor(darkColor);
            }
            window.draw(rectangle);
        }
    }
    window.display();
}


void Game::run() {
    this->newGame();
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        hearMouseEvents(event);
    }
}

void Game::newGame() {
    chess.restart();
}

int Game::result() {
    return chess.result;
}

void Game::hearMouseEvents(sf::Event event) {
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();

        // tracking the position of the mouse inside of the window
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                int clickedSquareX; int clickedSquareY;
                mapToBoard(event.mouseButton.x, event.mouseButton.y, &clickedSquareX, &clickedSquareY);
                std::cout << "square x: " << clickedSquareX << std::endl;
                std::cout << "square y: " << clickedSquareY << std::endl;
//                if(!chess.move(clickedSquareX, clickedSquareY, &window)) {
//                    this->hearMouseEvents(event);
//                }
                chess.switchPlayer();
                if (chess.gameOver()) {
                    std::cout << "Result: " << this->result() << std::endl;
                    this->newGame();
                }
            }
        }
    }
}


void Game::mapToBoard(int x, int y, int* squareX, int* squareY) {
    *squareX = floor(x/boxW);
    *squareY = floor(y/boxH);
}


