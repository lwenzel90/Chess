// Copyright 2022 Logan Wenzel.

#ifndef SRC_PIECE_HPP_
#define SRC_PIECE_HPP_
// The piece should have:
// 1. an id that defines its type.
// 2. a text/image class for the icon
// 3. information about where it is on the board


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>  // sf::Image

class Piece {
 public:
    explicit Piece(unsigned int id);
    sf::Sprite getSprite();
 private:
    sf::Vector2f position;
    sf::Image mImage;
    sf::Texture mTexture;
    sf::Sprite mSprite;
};


#endif  // SRC_PIECE_HPP_
