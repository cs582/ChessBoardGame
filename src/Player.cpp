//
// Created by Carlos Salas Flores on 6/16/23.
//
#include "../include/Player.h"
#include "../include/Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>


sf::Color brightColor(sf::Color(90, 184, 18));

Player::Player(char c) : id(c) {
    std::cout << "Player Constructor" << std::endl;
}
