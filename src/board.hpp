// Copyright 2022 Logan Wenzel.

#ifndef SRC_BOARD_HPP_
#define SRC_BOARD_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include "piece.hpp"

class Board {
 public:
    explicit Board(sf::RenderWindow* window);
    std::vector<sf::RectangleShape*> mBoardSquares;
    bool draw(sf::RenderWindow* window);
 private:
    float mSquareLen;
    Piece pawn;
    Piece knight;
    Piece bishop;
    Piece rook;
    Piece queen;
    Piece king;
};


#endif  // SRC_BOARD_HPP_
