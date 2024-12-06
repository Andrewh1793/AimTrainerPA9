#pragma once

#ifndef TARGET_H
#define TARGET_H

#include <SFML/Graphics.hpp>

/*************************************************************
 * Class: Target                                             *
 * Description: Represents a target object that can be drawn *
 * and interacted with.                                      *
 *************************************************************/
class Target {

public:
    /*********************************************************
     * Function: Target(float x, float y, float r)           *
     * Description: Constructor that initializes the target  *
     * with position and radius.                             *
     * Input parameters: x (float), y (float), r (float)     *
     * Returns: None                                         *
     * Preconditions: None                                   *
     * Postconditions: Target is initialized.               *
     *********************************************************/
    Target(float x, float y, float r);

    /*********************************************************
     * Function: draw(sf::RenderWindow& window)              *
     * Description: Draws the target on the specified window.*
     * Input parameters: window (sf::RenderWindow&)          *
     * Returns: None                                         *
     * Preconditions: Window is initialized.                 *
     * Postconditions: Target is drawn on the window.        *
     *********************************************************/
    virtual void draw(sf::RenderWindow& window);

    /*********************************************************
     * Function: isHit(sf::Vector2i mousePosition)           *
     * Description: Checks if the target is hit based on the *
     * mouse position.                                       *
     * Input parameters: mousePosition (sf::Vector2i)        *
     * Returns: bool - True if hit, false otherwise.         *
     * Preconditions: Mouse position is valid.               *
     * Postconditions: Returns true if the target is hit.    *
     *********************************************************/
    virtual bool isHit(sf::Vector2i mousePosition);

    /*********************************************************
     * Function: ~Target()                                   *
     * Description: Virtual destructor for cleanup.          *
     * Input parameters: None                                *
     * Returns: None                                         *
     * Preconditions: None                                   *
     * Postconditions: Object is properly destructed.        *
     *********************************************************/
    virtual ~Target() = default;

protected:
    /*********************************************************
     * Member: shape                                         *
     * Description: Represents the circular shape of the     *
     * target.                                               *
     *********************************************************/
    sf::CircleShape shape;

    /*********************************************************
     * Member: radius                                        *
     * Description: Radius of the target.                    *
     *********************************************************/
    float radius;

    /*********************************************************
     * Member: position                                      *
     * Description: Position of the target on the screen.    *
     *********************************************************/
    sf::Vector2f position;
};

#endif
