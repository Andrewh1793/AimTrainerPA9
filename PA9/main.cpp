#include <SFML/Graphics.hpp>
#include "Target.h"
#include "PowerUpTarget.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Aim Trainer");
    std::vector<Target*> targets;

    srand(static_cast<unsigned>(time(nullptr)));

    int score = 0;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text scoreText("Score: 0", font, 24);
    scoreText.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (auto it = targets.begin(); it != targets.end(); ++it) {
                    if ((*it)->isHit(sf::Mouse::getPosition(window))) {
                        score += dynamic_cast<PowerUpTarget*>(*it) ? 10 : 1;
                        delete* it;
                        targets.erase(it);
                        break;
                    }
                }
            }
        }

        if (rand() % 100 < 5) { // Spawn chance
            if (rand() % 5 == 0) {
                targets.push_back(new PowerUpTarget(rand() % 750, rand() % 550, 30));
            }
            else {
                targets.push_back(new Target(rand() % 750, rand() % 550, 20));
            }
        }

        window.clear();
        for (auto& target : targets) {
            target->draw(window);
        }

        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);
        window.display();
    }

    for (auto& target : targets)
        delete target;

    return 0;
}
