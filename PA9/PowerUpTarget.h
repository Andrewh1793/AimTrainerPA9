#pragma once
#ifndef POWERUPTARGET_H
#define POWERUPTARGET_H

#include "Target.h"

//inherits from Target class
class PowerUpTarget : public Target {
public:
    //constructor
    PowerUpTarget(float x, float y, float r);
    //Function to draw the power up target to the screen
    void draw(sf::RenderWindow& window) override;
    //destructor
    ~PowerUpTarget() override = default;
};

#endif
