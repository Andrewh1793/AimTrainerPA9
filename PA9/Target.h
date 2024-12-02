#pragma once

#ifndef TARGET_H
#define TARGET_H

#include <SFML/Graphics.hpp>

class Target {
protected:
    sf::CircleShape shape;
    float radius;
    sf::Vector2f position;

public:
    Target(float x, float y, float r);
    virtual void draw(sf::RenderWindow& window);
    virtual bool isHit(sf::Vector2i mousePosition);
    virtual ~Target() = default;
};

#endif
