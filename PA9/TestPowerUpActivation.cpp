#include <iostream>

int main() {
    int combo = 0;
    bool powerUpMode = false;

    // Simulate 10 consecutive hits
    for (int i = 0; i < 10; ++i) {
        combo++;
        if (combo >= 10) {
            powerUpMode = true;
        }
    }

    // Test
    if (powerUpMode) {
        std::cout << "Test Passed: Power-up mode activated after 10 hits.\n";
    }
    else {
        std::cout << "Test Failed: Power-up mode not activated after 10 hits.\n";
    }

    return 0;
}
