include "menu.h"

void showHowToPlay(sf::RenderWindow& window, const sf::Font& font) {
    sf::Text howToPlayText(
        "How to Play:\n\n"
        "- Left Click on the targets to score points.\n"
        "- Avoid missing to keep your combo up.\n"
        "- Achieve a 10-hit combo to enter Power-Up Mode.\n\n"
        "Press 'B' to go back.",
        font, 20
    );

    howToPlayText.setFillColor(sf::Color::White);
    howToPlayText.setPosition(50, 50);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            // Check for 'B' key to return to the menu
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                return;
            }
        }

        window.clear(sf::Color::Black); 
        window.draw(howToPlayText);
        window.display();
    }
}

int showMenu(sf::RenderWindow& window) {
    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int result = menu.handleMouseInput(sf::Mouse::getPosition(window), true);
                if (result != -1) {
                    return result;
                }
            }

            if (event.type == sf::Event::MouseMoved) {
                menu.handleMouseInput(sf::Mouse::getPosition(window), false);
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }

    return -1;
}
