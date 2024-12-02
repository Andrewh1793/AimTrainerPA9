#include "PowerUpTarget.h"

PowerUpTarget::PowerUpTarget(float x, float y, float r) : Target(x, y, r) {
    shape.setFillColor(sf::Color::Green);
}

void PowerUpTarget::draw(sf::RenderWindow& window) {
    shape.setOutlineThickness(3);
    shape.setOutlineColor(sf::Color::Yellow);
    Target::draw(window);
}