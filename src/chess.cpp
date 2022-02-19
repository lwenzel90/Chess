// Copyright 2022 Logan Wenzel.

#include <iostream>
#include "board.hpp"
// Classes to implement
// Board,
// pieces,
// overlord game class
// pgn reader
// cpu ai

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800),
                            "Chess Game",
                            sf::Style::Close);
    Board board(&window);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        board.draw(&window);
        window.display();
    }

    return 0;
}
