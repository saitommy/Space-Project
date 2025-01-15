#include <iostream>
#include "SFML/Graphics.hpp"

/*

Need to work on:
0) Can't load image file - I don't have VS-CMake and VSCode-MingGW set up properly so I can't use either
1) changing "Frames" along the spritesheet
2) Having the planet move (in a standard elipse for now - applying physics properties later)

*/



int main() {

    // Setup the window.
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    sf::Texture earthSheet;
    earthSheet.loadFromFile("./assets/earth_spritesheet.png");
    // Setup our sprite with a texture. Construct our sprite with its corresponding texture.
    sf::Sprite earthSprite(earthSheet);
    
    // Scale the planet to half the window size for now
    earthSprite.setScale(0.5f, 0.5f);

    // Input parameters of sprite sheet as variables
    // int totalFrames = 50;
    // int frameWidth = 5000;
    // int frameHeight = 100;
    //



    // Main application loop.
    while (window.isOpen()) {
        sf::Event event;
        // Handle events.
        while (window.pollEvent(event)) {
            // Terminate application.
            if (event.type == sf::Event::Closed) {
                std::cout << "Window Closed!" << std::endl;
                window.close();
            }
        }

        // Clear window.
        window.clear(sf::Color::Black);

        // Draw sprites.
        window.draw(earthSprite);

        // Display our graphics scene.
        window.display();
    }

    return 0;
}