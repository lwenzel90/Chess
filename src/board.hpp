// Copyright 2022 Logan Wenzel.

#ifndef SRC_BOARD_HPP_
#define SRC_BOARD_HPP_

#include <vector>
#include <SFML/Graphics.hpp>

class Board {
 public:
   explicit Board(sf::RenderWindow* window);
   std::vector<sf::RectangleShape*> mBoardSquares;
   bool draw(sf::RenderWindow* window);
 private:
   float mSquareLen;
   sf::Image wKingImage; 
   sf::Texture wKingTexture;
   sf::Sprite wKingSprite;
   sf::Image bKingImage; 
   sf::Texture bKingTexture;
   sf::Sprite bKingSprite;

   sf::Image wQueenImage; 
   sf::Texture wQueenTexture;
   sf::Sprite wQueenSprite;
   sf::Image bQueenImage; 
   sf::Texture bQueenTexture;
   sf::Sprite bQueenSprite;
   
   sf::Image wRookImage; 
   sf::Texture wRookTexture;
   sf::Sprite wRookSprite;
   sf::Image bRookImage; 
   sf::Texture bRookTexture;
   sf::Sprite bRookSprite;
   
   sf::Image wBishopImage; 
   sf::Texture wBishopTexture;
   sf::Sprite wBishopSprite;
   sf::Image bBishopImage; 
   sf::Texture bBishopTexture;
   sf::Sprite bBishopSprite;
   
   sf::Image wKnightImage; 
   sf::Texture wKnightTexture;
   sf::Sprite wKnightSprite;
   sf::Image bKnightImage; 
   sf::Texture bKnightTexture;
   sf::Sprite bKnightSprite;

   sf::Image wPawnImage; 
   sf::Texture wPawnTexture;
   sf::Sprite wPawnSprite;
   sf::Image bPawnImage; 
   sf::Texture bPawnTexture;
   sf::Sprite bPawnSprite;
};


#endif  // SRC_BOARD_HPP_
