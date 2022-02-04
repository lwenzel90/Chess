// Copyright 2022 Logan Wenzel.
#include <SFML/Graphics.hpp>
// Classes to implement
// Board,
// pieces,
// overlord game class
// pgn reader
// cpu ai
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
