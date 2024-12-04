#pragma once

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
public:
    Menu(float width, float height);
    void draw(sf::RenderWindow& window);
    int handleMouseInput(const sf::Vector2i& mousePosition, bool clicked);

private:
    static constexpr int MENU_ITEMS = 3;
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;
    sf::Font font;
    int hoveredIndex;
};

void runGame(sf::RenderWindow& window, const sf::Font& font);
int showMenu(sf::RenderWindow& window);
void showHowToPlay(sf::RenderWindow& window, const sf::Font& font);

#endif
