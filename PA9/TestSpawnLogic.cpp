#include <iostream>
#include <vector>
#include "Target.h"

int main() {
    std::vector<Target*> targets;

    // test spawning targets
    targets.push_back(new Target(100, 100, 20));
    targets.push_back(new Target(200, 200, 30));

    // Test
    if (targets.size() == 2) {
        std::cout << "Test Passed: Targets spawned right.\n";
    }
    else {
        std::cout << "Test Failed: Targets not spawned right.\n";
    }

    // Test individual targets
    if (targets[0]->isHit(sf::Vector2i(110, 110))) {
        std::cout << "Test Passed: First target hit detection right.\n";
    }
    else {
        std::cout << "Test Failed: First target hit detection incorrect.\n";
    }

    if (!targets[1]->isHit(sf::Vector2i(250, 250))) {
        std::cout << "Test Passed: Second target miss detection correct.\n";
    }
    else {
        std::cout << "Test Failed: Second target miss detection incorrect.\n";
    }

    for (auto target : targets) {
        delete target;
    }

    return 0;
}
