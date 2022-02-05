// Copyright 2022 Logan Wenzel.

#include "board.hpp"
#include <iostream>
#include <vector>

Board::Board(sf::RenderWindow *window) {
    mSquareLen = 50;

    // Calculate margin
    sf::Vector2u size = window->getSize();
    unsigned int width = size.x;
    double xMargin = (width - (mSquareLen * 8)) / 2;
    double yMargin = 100;

    double xPos = 0;
    double yPos = 0;
    bool isLightSquare = true;
    size_t idx = 0;

    for (size_t file = 0; file < 8; file++) {
        for (size_t rank = 0; rank < 8; rank++) {
            mBoardSquares.push_back(
                    new sf::RectangleShape(sf::Vector2f(mSquareLen,
                                                        mSquareLen)));
            isLightSquare = (file + rank) % 2 != 0;
            // Set color
            if (isLightSquare) {
                mBoardSquares[idx]->setFillColor(sf::Color(60, 40, 5, 255));
            } else {
                mBoardSquares[idx]->setFillColor(sf::Color(210, 190, 173, 255));
            }
            // Set position
            xPos = xMargin + (file * mSquareLen);
            yPos = yMargin + (rank * mSquareLen);
            mBoardSquares[idx]->setPosition(xPos, yPos);

            window->draw(*mBoardSquares[idx]);
            idx++;
        }
    }
}
