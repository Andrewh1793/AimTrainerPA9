#pragma once
#ifndef POWERUPTARGET_H
#define POWERUPTARGET_H

#include "Target.h"

/*************************************************************
 * Class: PowerUpTarget                                      *
 * Description: Represents a specialized target with power-up*
 * functionality, inheriting from the Target class.          *
 *************************************************************/
class PowerUpTarget : public Target {
public:
    /*********************************************************
     * Function: PowerUpTarget(float x, float y, float r)    *
     * Description: Constructor that initializes the power-up*
     * target with position and radius.                      *
     * Input parameters: x (float), y (float), r (float)     *
     * Returns: None                                         *
     * Preconditions: None                                   *
     * Postconditions: Power-up target is initialized.       *
     *********************************************************/
    PowerUpTarget(float x, float y, float r);

    /*********************************************************
     * Function: draw(sf::RenderWindow& window)              *
     * Description: Draws the power-up target on the screen. *
     * Input parameters: window (sf::RenderWindow&)          *
     * Returns: None                                         *
     * Preconditions: Window is initialized.                 *
     * Postconditions: Power-up target is drawn on the window.*
     *********************************************************/
    void draw(sf::RenderWindow& window) override;

    /*********************************************************
     * Function: ~PowerUpTarget()                            *
     * Description: Destructor for cleanup of power-up target.*
     * Input parameters: None                                *
     * Returns: None                                         *
     * Preconditions: None                                   *
     * Postconditions: Object is properly destructed.        *
     *********************************************************/
    ~PowerUpTarget() override = default;
};

#endif
