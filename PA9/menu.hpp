#include "menu.h"

Menu::Menu(float width, float height) : hoveredIndex(-1) {
    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Failed to load font (arial.ttf)");
    }

    std::string labels[MENU_ITEMS] = { "Start", "How To Play", "Exit" };
    float buttonWidth = 250.0f;
    float buttonHeight = 60.0f;
    float spacing = 20.0f;

    for (int i = 0; i < MENU_ITEMS; ++i) {
        sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
        button.setFillColor(sf::Color::White);
        button.setPosition(
            width / 2 - buttonWidth / 2,
            height / 2 - (MENU_ITEMS * buttonHeight + (MENU_ITEMS - 1) * spacing) / 2 + i * (buttonHeight + spacing)
        );
        buttons.push_back(button);

        sf::Text label(labels[i], font, 24);
        label.setFillColor(sf::Color::Black);
        label.setPosition(
            button.getPosition().x + buttonWidth / 2 - label.getGlobalBounds().width / 2,
            button.getPosition().y + buttonHeight / 2 - label.getGlobalBounds().height / 2
        );
        buttonTexts.push_back(label);
    }
}

void Menu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < MENU_ITEMS; ++i) {
        if (i == hoveredIndex) {
            buttons[i].setFillColor(sf::Color::Blue);
            buttonTexts[i].setFillColor(sf::Color::White);
        }
        else {
            buttons[i].setFillColor(sf::Color::White);
            buttonTexts[i].setFillColor(sf::Color::Black);
        }

        window.draw(buttons[i]);
        window.draw(buttonTexts[i]);
    }
}

int Menu::handleMouseInput(const sf::Vector2i& mousePosition, bool clicked) {
    hoveredIndex = -1;

    for (int i = 0; i < MENU_ITEMS; ++i) {
        if (buttons[i].getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
            hoveredIndex = i;
            if (clicked) {
                return i;
            }
        }
    }

    return -1;
}
