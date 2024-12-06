#include <iostream>
#include <vector>
#include "Target.h"
/*************************************************************
 * Function: testScoreComboUpdate()                         *
 * Description: Tests the score and combo update logic when *
 * a target is hit.                                         *
 * Input parameters: None                                   *
 * Returns: None                                            *
 * Preconditions: Target class is implemented and functional.*
 * Postconditions: Results of score and combo updates are   *
 * printed to the console.                                  *
 *************************************************************/
void testScoreComboUpdate() 
{
    int score = 0;
    int combo = 0;
    std::vector<Target*> targets;

    targets.push_back(new Target(100, 100, 20));
    sf::Vector2i clickPosition(110, 110);

    // Simulate a hit
    for (auto it = targets.begin(); it != targets.end(); ++it) 
    {
        if ((*it)->isHit(clickPosition)) 
        {
            score += 10;
            combo++;
            delete* it;
            targets.erase(it);
            break;
        }
    }

    // Test
    if (score == 10 && combo == 1) 
    {
        std::cout << "Test Passed: Score and combo updated correctly.\n";
    }
    else 
    {
        std::cout << "Test Failed: Score or combo not updated correctly.\n";
    }

    //return 0;
}
