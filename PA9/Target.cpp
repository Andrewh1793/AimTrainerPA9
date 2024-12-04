#include "Target.h"

Target::Target(float x, float y, float r) : radius(r), position(x, y) 
{
    shape.setRadius(radius);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Red);
}

void Target::draw(sf::RenderWindow& window) 
{
    window.draw(shape);
}

bool Target::isHit(sf::Vector2i mousePosition) 
{
    float dx = mousePosition.x - (position.x + radius);
    float dy = mousePosition.y - (position.y + radius);
    return (dx * dx + dy * dy) <= (radius * radius);
}
