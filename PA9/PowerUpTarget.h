#pragma once
#ifndef POWERUPTARGET_H
#define POWERUPTARGET_H

#include "Target.h"

class PowerUpTarget : public Target {
public:
    PowerUpTarget(float x, float y, float r);
    void draw(sf::RenderWindow& window) override;
    ~PowerUpTarget() override = default;
};

#endif
