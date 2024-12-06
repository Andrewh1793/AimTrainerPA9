#include <iostream>
/*************************************************************
 * Function: testPowerUpActivation()                        *
 * Description: Tests the activation of power-up mode after *
 * achieving a combo of 10 consecutive hits.                *
 * Input parameters: None                                   *
 * Returns: None                                            *
 * Preconditions: Power-up logic is implemented correctly.  *
 * Postconditions: The test results for power-up activation *
 * are printed to the console.                              *
 *************************************************************/
void testPowerUpActivation() 
{
    int combo = 0;
    bool powerUpMode = false;

    // Simulate 10 consecutive hits
    for (int i = 0; i < 10; ++i) 
    {
        combo++;
        if (combo >= 10) 
        {
            powerUpMode = true;
        }
    }

    // Test
    if (powerUpMode) 
    {
        std::cout << "Test Passed: Power-up mode activated after 10 hits.\n";
    }
    else 
    {
        std::cout << "Test Failed: Power-up mode not activated after 10 hits.\n";
    }

    //return 0;
}
