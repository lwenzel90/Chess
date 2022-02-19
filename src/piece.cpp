// Copyright 2022 Logan Wenzel.

#include "piece.hpp"
#include <iostream>
#include <string>
Piece::Piece(unsigned int id) {
    if (id == 0) {
        // White Pawn
        if (mImage.loadFromFile("/home/logan/chess/assets/tile005.png")) {
            mTexture.loadFromImage(mImage);
            mSprite.setTexture(mTexture);
        } else {
            std::cout << "Could not open tile png" << std::endl;
        }
    } else if (id == 1) {
        // White Knight
        if (mImage.loadFromFile("/home/logan/chess/assets/tile003.png")) {
            mTexture.loadFromImage(mImage);
            mSprite.setTexture(mTexture);
        } else {
            std::cout << "Could not open tile png" << std::endl;
        }
    } else if (id == 2) {
        // White Bishop
        if (mImage.loadFromFile("/home/logan/chess/assets/tile002.png")) {
            mTexture.loadFromImage(mImage);
            mSprite.setTexture(mTexture);
        } else {
            std::cout << "Could not open tile png" << std::endl;
        }
    } else if (id == 4) {
        // White Rook
        if (mImage.loadFromFile("/home/logan/chess/assets/tile004.png")) {
            mTexture.loadFromImage(mImage);
            mSprite.setTexture(mTexture);
        } else {
            std::cout << "Could not open tile png" << std::endl;
        }
    } else if (id == 8) {
        // White Queen
        if (mImage.loadFromFile("/home/logan/chess/assets/tile001.png")) {
            mTexture.loadFromImage(mImage);
            mSprite.setTexture(mTexture);
        } else {
            std::cout << "Could not open tile png" << std::endl;
        }
    } else if (id == 16) {
        // White King
        if (mImage.loadFromFile("/home/logan/chess/assets/tile000.png")) {
            mTexture.loadFromImage(mImage);
            mSprite.setTexture(mTexture);
        } else {
            std::cout << "Could not open tile png" << std::endl;
        }
    } else if (id == 32) {
        // Black Pawn
        if (mImage.loadFromFile("/home/logan/chess/assets/tile011.png")) {
            mTexture.loadFromImage(mImage);
            mSprite.setTexture(mTexture);
        } else {
            std::cout << "Could not open tile png" << std::endl;
        }
    }
}

sf::Sprite Piece::getSprite() {
    return mSprite;
}
