#include <SFML/Graphics.hpp>
#include "Target.h"
#include "PowerUpTarget.h"
#include "menu.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>



int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Aim Trainer");
    sf::Font font;

    if (!font.loadFromFile("arial.ttf")) 
    {
        throw std::runtime_error("Failed to load font (arial.ttf)");
    }

    while (window.isOpen()) 
    {
        int menuChoice = showMenu(window);

        switch (menuChoice) 
        {
        case 0:
            runGame(window, font);
            break;

        case 1:
            showHowToPlay(window, font);
            break;

        case 2:
            window.close();
            break;

        default:
            break;
        }
    }

    return 0;
}
