#pragma once

#ifndef TARGET_H
#define TARGET_H

#include <SFML/Graphics.hpp>

class Target {


public:
    //constructor
    Target(float x, float y, float r);
    //function to draw the target to the screen
    virtual void draw(sf::RenderWindow& window);
    //Function to check if the target was hit
    virtual bool isHit(sf::Vector2i mousePosition);

    //destructor
    virtual ~Target() = default;

protected:
    //Circle shape for target
    sf::CircleShape shape;
    //Radius of target
    float radius;
    //Position of target on screen
    sf::Vector2f position;
};

#endif
