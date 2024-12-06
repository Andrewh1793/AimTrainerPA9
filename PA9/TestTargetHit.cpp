#include <iostream>
#include "Target.h"
/*************************************************************
 * Function: testTargetHit()                                 *
 * Description: Tests the hit detection functionality of the *
 * Target class. Includes test cases for detecting hits and  *
 * misses based on the mouse position.                      *
 * Input parameters: None                                    *
 * Returns: None                                             *
 * Preconditions: Target class and SFML are initialized.     *
 * Postconditions: Results of the hit and miss tests are     *
 * printed to the console.                                   *
 *************************************************************/
void testTargetHit() 
{
    Target target(100, 100, 20);

    // Test Case: Hit detection
    sf::Vector2i hitPosition(110, 110);
    if (target.isHit(hitPosition)) 
    {
        std::cout << "Test Passed: Target registers hit correctly.\n";
    }
    else 
    {
        std::cout << "Test Failed: Target should register hit.\n";
    }

    // Test Case: Miss detection
    sf::Vector2i missPosition(150, 150);
    if (!target.isHit(missPosition)) 
    {
        std::cout << "Test Passed: Target registers miss correctly.\n";
    }
    else 
    {
        std::cout << "Test Failed: Target should register miss.\n";
    }

    //return 0;
}
