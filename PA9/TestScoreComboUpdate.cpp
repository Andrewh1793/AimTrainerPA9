#include <iostream>
#include <vector>
#include "Target.h"

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
