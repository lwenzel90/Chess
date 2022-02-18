// Copyright 2022 Logan Wenzel.

#include "board.hpp"
#include <iostream>
#include <SFML/Graphics/Image.hpp> // sf::Image
#include <SFML/Graphics/Font.hpp> // sf::Image
#include <vector>
#include "piece.hpp"

Board::Board(sf::RenderWindow *window) {
    mSquareLen = 100;
    
    if (wKingImage.loadFromFile("/home/logan/chess/assets/tile000.png")) {
        wKingTexture.loadFromImage(wKingImage);
        wKingSprite.setTexture(wKingTexture);
    } else {
        std::cout << "Could not open tile png" << std::endl;
    }
    if (wQueenImage.loadFromFile("/home/logan/chess/assets/tile001.png")) {
        wQueenTexture.loadFromImage(wQueenImage);
        wQueenSprite.setTexture(wQueenTexture);
    } else {
        std::cout << "Could not open tile png" << std::endl;
    }
    if (wBishopImage.loadFromFile("/home/logan/chess/assets/tile002.png")) {
        wBishopTexture.loadFromImage(wBishopImage);
        wBishopSprite.setTexture(wBishopTexture);
    } else {
        std::cout << "Could not open tile png" << std::endl;
    }
    if (wKnightImage.loadFromFile("/home/logan/chess/assets/tile003.png")) {
        wKnightTexture.loadFromImage(wKnightImage);
        wKnightSprite.setTexture(wKnightTexture);
    } else {
        std::cout << "Could not open tile png" << std::endl;
    }
    if (wRookImage.loadFromFile("/home/logan/chess/assets/tile004.png")) {
        wRookTexture.loadFromImage(wRookImage);
        wRookSprite.setTexture(wRookTexture);
    } else {
        std::cout << "Could not open tile png" << std::endl;
    }
    if (wPawnImage.loadFromFile("/home/logan/chess/assets/tile005.png")) {
        wPawnTexture.loadFromImage(wPawnImage);
        wPawnSprite.setTexture(wPawnTexture);
    } else {
        std::cout << "Could not open tile png" << std::endl;
    }

}

bool Board::draw(sf::RenderWindow *window) {
    if (!window) {
        return false;
    }
    
    sf::Vector2u windowSize;
    if (window) {
        windowSize = window->getSize();
        if (window->isOpen())
        {
        } else {
            std::cout << "The window is not open!!!! :o" << std::endl;
            return false;
        }
    } else {
        return false;
    }

    // Calculate margin
    unsigned int width = windowSize.x;
    unsigned int height = windowSize.y;

    double xMargin = (width - (mSquareLen * 8)) / 2;
    double yMargin = 0;
    if (height > 800) {
        yMargin = (height - (mSquareLen * 8)) / 2;
    } else {
        yMargin = 0;
    }
    if (width > 800) {
        xMargin = (width - (mSquareLen * 8)) / 2;
    } else {
        xMargin = 0;
    }

    double offset = 3; // The icons are slightly off from centered adjust w/ offset
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
            if (mBoardSquares[idx]) {
                window->draw(*mBoardSquares[idx]);
            }

            idx++;
        }
    }
    wKingSprite.setPosition(400.0 - offset, 700.0 - offset);
    wQueenSprite.setPosition(300.0 - offset, 700.0 - offset);
    wRookSprite.setPosition(0.0 - offset, 700.0 - offset);
    wBishopSprite.setPosition(500.0 - offset, 700.0 - offset);
    wPawnSprite.setPosition(0.0 - offset, 600.0 - offset);
    wKnightSprite.setPosition(600.0 - offset, 700.0 - offset);

    window->draw(wKingSprite);
    window->draw(wQueenSprite);
    window->draw(wBishopSprite);
    window->draw(wRookSprite);
    window->draw(wPawnSprite);
    window->draw(wKnightSprite);
    return true;
}


