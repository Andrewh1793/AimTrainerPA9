#include "PowerUpTarget.h"

PowerUpTarget::PowerUpTarget(float x, float y, float r) : Target(x, y, r) 
{
    shape.setFillColor(sf::Color::Green); //Inside of power up target color (green)
}

void PowerUpTarget::draw(sf::RenderWindow& window) 
{
    shape.setOutlineThickness(3); //Outline of power up target thickness
    shape.setOutlineColor(sf::Color::Yellow); //Color of power up target outline (yellow)
    Target::draw(window);
}