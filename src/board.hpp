// Copyright 2022 Logan Wenzel.

#ifndef SRC_BOARD_HPP_
#define SRC_BOARD_HPP_

#include <vector>
#include <SFML/Graphics.hpp>

class Board {
 public:
    explicit Board(sf::RenderWindow* window);
    std::vector<sf::RectangleShape*> mBoardSquares;

 private:
    double mSquareLen;
};


#endif  // SRC_BOARD_HPP_
