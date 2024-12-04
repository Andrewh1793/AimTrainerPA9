#include <SFML/Graphics.hpp>
#include "PowerUpTarget.h"
#include <iostream>

void testPowerUpTargetAppearance() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test PowerUpTarget");
    PowerUpTarget powerUpTarget(200, 200, 30);

    // Test appearance manually by visual inspection
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }

        window.clear();
        powerUpTarget.draw(window);
        window.display();
    }

    std::cout << "Test Passed: Verify the visual appearance manually (Green fill, Yellow outline).\n";
    //return 0;
}
