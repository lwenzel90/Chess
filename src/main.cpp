// Copyright 2022 Logan Wenzel.


#include "board.hpp"
// Classes to implement
// Board,
// pieces,
// overlord game class
// pgn reader
// cpu ai

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        Board board(&window);

        window.display();
    }

    return 0;
}
