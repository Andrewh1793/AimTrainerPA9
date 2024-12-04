/*******************************************************************************************
* Programmers: Andrew Hazelbaker, Zachary Marseglia, and Jonathan Jaycob Bautista
* Class: CptS 122, Fall 2024; Lab Section 3
* Programming Assignment: PA9
* Date: November 22, 2024
* Description: This is an Aim Trainer Game the game features two types of targets standard
targets which reward basic points and special power-up targets which gives bonus points. 
The challenge is in the quick spotting and clicking on targets before they disappear while
striving for the highest possible score. The random spawning system and multiple target 
sizes ensure a fun and engaging experience for players of all skill levels.
*******************************************************************************************/
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
