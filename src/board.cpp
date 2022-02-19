// Copyright 2022 Logan Wenzel.

#include "board.hpp"
#include <iostream>
#include <vector>
#include <SFML/Window/WindowStyle.hpp>  // sf::Image

Board::Board(sf::RenderWindow *window) : pawn(0),
                                         knight(1),
                                         bishop(2),
                                         rook(4),
                                         queen(8),
                                         king(16) {
    mSquareLen = 100;
}

bool Board::draw(sf::RenderWindow *window) {
    if (!window) {
        return false;
    }

    double OFFSET = 3;  // The icons are slightly off from centered adjust w/
                        // OFFSET
    double xPos = 0;
    double yPos = 0;
    bool isLightSquare = true;
    size_t idx = 0;  // This is used to keep mBoardSquares as a flat list for 2D

    sf::Color TAN = sf::Color(60, 40, 5, 255);
    sf::Color BROWN = sf::Color(210, 190, 173, 255);
    for (size_t file = 0; file < 8; file++) {
        for (size_t rank = 0; rank < 8; rank++) {
            mBoardSquares.push_back(
                    new sf::RectangleShape(sf::Vector2f(mSquareLen,
                                                        mSquareLen)));
            isLightSquare = (file + rank) % 2 != 0;
            // Set color
            if (isLightSquare) {
                mBoardSquares[idx]->setFillColor(TAN);
            } else {
                mBoardSquares[idx]->setFillColor(BROWN);
            }
            // Set position
            xPos = (file * mSquareLen);
            yPos = (rank * mSquareLen);
            mBoardSquares[idx]->setPosition(xPos, yPos);
            if (mBoardSquares[idx]) {
                window->draw(*mBoardSquares[idx]);
            }
            idx++;
        }
    }
    // TODO(Logan) Set locations for pieces based on a grid system either
    //             functions could look like the following setPos("e4"),
    //             setPos(row,col) // [0-7]

    sf::Sprite myPawn1 = pawn.getSprite();
    sf::Sprite myPawn2 = pawn.getSprite();
    sf::Sprite myPawn3 = pawn.getSprite();
    sf::Sprite myPawn4 = pawn.getSprite();
    sf::Sprite myPawn5 = pawn.getSprite();
    sf::Sprite myPawn6 = pawn.getSprite();
    sf::Sprite myPawn7 = pawn.getSprite();
    sf::Sprite myPawn8 = pawn.getSprite();
    sf::Sprite myKnight1 = knight.getSprite();
    sf::Sprite myKnight2 = knight.getSprite();
    sf::Sprite myBishop1 = bishop.getSprite();
    sf::Sprite myBishop2 = bishop.getSprite();
    sf::Sprite myRook1 = rook.getSprite();
    sf::Sprite myRook2 = rook.getSprite();
    sf::Sprite myQueen = queen.getSprite();
    sf::Sprite myKing = king.getSprite();
    myPawn1.setPosition(0.0 - OFFSET, 600.0 - OFFSET);
    myPawn2.setPosition(100.0 - OFFSET, 600.0 - OFFSET);
    myPawn3.setPosition(200.0 - OFFSET, 600.0 - OFFSET);
    myPawn4.setPosition(300.0 - OFFSET, 600.0 - OFFSET);
    myPawn5.setPosition(400.0 - OFFSET, 600.0 - OFFSET);
    myPawn6.setPosition(500.0 - OFFSET, 600.0 - OFFSET);
    myPawn7.setPosition(600.0 - OFFSET, 600.0 - OFFSET);
    myPawn8.setPosition(700.0 - OFFSET, 600.0 - OFFSET);
    myKnight1.setPosition(100.0 - OFFSET, 700.0 - OFFSET);
    myKnight2.setPosition(600.0 - OFFSET, 700.0 - OFFSET);
    myBishop1.setPosition(200.0 - OFFSET, 700.0 - OFFSET);
    myBishop2.setPosition(500.0 - OFFSET, 700.0 - OFFSET);
    myRook1.setPosition(0.0 - OFFSET, 700.0 - OFFSET);
    myRook2.setPosition(700.0 - OFFSET, 700.0 - OFFSET);
    myQueen.setPosition(300.0 - OFFSET, 700.0 - OFFSET);
    myKing.setPosition(400.0 - OFFSET, 700.0 - OFFSET);

    window->draw(myPawn1);
    window->draw(myPawn2);
    window->draw(myPawn3);
    window->draw(myPawn4);
    window->draw(myPawn5);
    window->draw(myPawn6);
    window->draw(myPawn7);
    window->draw(myPawn8);
    window->draw(myKnight1);
    window->draw(myKnight2);
    window->draw(myBishop1);
    window->draw(myBishop2);
    window->draw(myRook1);
    window->draw(myRook2);
    window->draw(myQueen);
    window->draw(myKing);
    return true;
}


