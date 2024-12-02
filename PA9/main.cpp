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
    int combo = 0;
    bool powerUpMode = false;
    float powerUpTimer = 0.0f;
    float spawnTimer = 0.0f;

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text scoreText("Score: 0", font, 24);
    scoreText.setFillColor(sf::Color::White);

    sf::Text missText("", font, 24);
    missText.setFillColor(sf::Color::Red);
    missText.setPosition(300, 300);
    sf::Clock missClock;

    sf::Clock gameClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                bool hit = false;

                for (auto it = targets.begin(); it != targets.end(); ++it) {
                    if ((*it)->isHit(sf::Mouse::getPosition(window))) {
                        hit = true;
                        score += 10;
                        combo++;
                        delete* it;
                        targets.erase(it);
                        break;
                    }
                }

                if (!hit) {
                    missText.setString("Missed!");
                    missClock.restart();
                    combo = 0;
                }

                // Enter power-up mode after 10 hits in a row
                if (combo >= 10 && !powerUpMode) {
                    powerUpMode = true;
                    powerUpTimer = 5.0f; // 5 seconds of power-up mode
                }
            }
        }

        // Clear expired miss text
        if (missClock.getElapsedTime().asSeconds() > 1.0f) {
            missText.setString("");
        }

        // Update timers
        float deltaTime = gameClock.restart().asSeconds();
        spawnTimer += deltaTime;
        if (powerUpMode) {
            powerUpTimer -= deltaTime;
            if (powerUpTimer <= 0.0f) {
                powerUpMode = false;
                combo = 0; // Reset combo after power-up mode
            }
        }

        // Spawn logic
        if (spawnTimer > (powerUpMode ? 1.0f : 2.0f)) { // Spawn faster during power-up mode
            spawnTimer = 0.0f;
            if (powerUpMode) {
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

        if (!missText.getString().isEmpty()) {
            window.draw(missText);
        }

        window.display();
    }

    for (auto& target : targets)
        delete target;

    return 0;
}
