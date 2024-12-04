#include <SFML/Graphics.hpp>
#include "Target.h"
#include "PowerUpTarget.h"
#include "menu.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

void runGame(sf::RenderWindow& window, const sf::Font& font) {
    // Load background texture and create background sprite
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("shootingRange.jpg")) {
        throw std::runtime_error("Failed to load background texture");
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    std::vector<Target*> targets;

    srand(static_cast<unsigned>(time(nullptr)));

    int score = 0;
    int combo = 0;
    bool powerUpMode = false;
    float powerUpTimer = 0.0f;
    float spawnTimer = 0.0f;

    sf::Text scoreText("Score: 0", font, 24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    sf::Text missText("", font, 24);
    missText.setFillColor(sf::Color::Red);
    missText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 - 50);

    sf::Clock missClock;
    sf::Clock gameClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                bool hit = false;

                for (auto it = targets.begin(); it != targets.end();) {
                    if ((*it)->isHit(sf::Mouse::getPosition(window))) {
                        hit = true;
                        score += 10;
                        combo++;
                        delete* it;
                        it = targets.erase(it);
                    }
                    else {
                        ++it;
                    }
                }

                if (!hit) {
                    missText.setString("Missed!");
                    missClock.restart();
                    combo = 0;
                }

                if (combo >= 10 && !powerUpMode) {
                    powerUpMode = true;
                    powerUpTimer = 5.0f; // 5 seconds of power-up mode
                }
            }
        }

        if (missClock.getElapsedTime().asSeconds() > 1.0f) {
            missText.setString("");
        }

        float deltaTime = gameClock.restart().asSeconds();
        spawnTimer += deltaTime;
        if (powerUpMode) {
            powerUpTimer -= deltaTime;
            if (powerUpTimer <= 0.0f) {
                powerUpMode = false;
                combo = 0; // Reset combo after power-up mode
            }
        }

        if (spawnTimer > (powerUpMode ? 1.0f : 2.0f)) {
            spawnTimer = 0.0f;
            if (powerUpMode) {
                targets.push_back(new PowerUpTarget(rand() % (window.getSize().x - 60), rand() % (window.getSize().y - 60), 30));
            }
            else {
                targets.push_back(new Target(rand() % (window.getSize().x - 40), rand() % (window.getSize().y - 40), 20));
            }
        }

        window.clear();
        window.draw(backgroundSprite);

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

    for (auto& target : targets) {
        delete target;
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

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                return;
            }
        }

        window.clear(sf::Color::Black);
        window.draw(howToPlayText);
        window.display();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Aim Trainer");
    sf::Font font;

    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Failed to load font (arial.ttf)");
    }

    while (window.isOpen()) {
        int menuChoice = showMenu(window);

        switch (menuChoice) {
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
