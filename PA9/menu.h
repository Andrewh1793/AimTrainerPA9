#pragma once

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

/*************************************************************
 * Class: Menu                                               *
 * Description: Represents a menu system with buttons for   *
 * interacting with the application.                        *
 *************************************************************/
class Menu {
public:
    /*********************************************************
     * Function: Menu(float width, float height)             *
     * Description: Constructor that initializes the menu    *
     * layout with buttons and text.                         *
     * Input parameters: width (float), height (float)       *
     * Returns: None                                         *
     * Preconditions: None                                   *
     * Postconditions: Menu is initialized.                 *
     *********************************************************/
    Menu(float width, float height);

    /*********************************************************
     * Function: draw(sf::RenderWindow& window)              *
     * Description: Draws the menu on the specified window.  *
     * Input parameters: window (sf::RenderWindow&)          *
     * Returns: None                                         *
     * Preconditions: Window is initialized.                 *
     * Postconditions: Menu is drawn on the window.          *
     *********************************************************/
    void draw(sf::RenderWindow& window);

    /*********************************************************
     * Function: handleMouseInput(const sf::Vector2i& mousePosition, 
     *                            bool clicked)             *
     * Description: Handles mouse input, checking if buttons *
     * are hovered or clicked.                               *
     * Input parameters: mousePosition (sf::Vector2i),       *
     * clicked (bool)                                        *
     * Returns: int - Index of the clicked button, or -1 if  *
     * no button is clicked.                                 *
     * Preconditions: Mouse position is valid.               *
     * Postconditions: Button state is updated.              *
     *********************************************************/
    int handleMouseInput(const sf::Vector2i& mousePosition, bool clicked);

private:
    /*********************************************************
     * Constant: MENU_ITEMS                                  *
     * Description: Number of menu items.                   *
     *********************************************************/
    static constexpr int MENU_ITEMS = 3;

    /*********************************************************
     * Member: buttons                                       *
     * Description: Vector of rectangle shapes representing  *
     * menu buttons.                                         *
     *********************************************************/
    std::vector<sf::RectangleShape> buttons;

    /*********************************************************
     * Member: buttonTexts                                   *
     * Description: Vector of texts displayed on menu buttons.*
     *********************************************************/
    std::vector<sf::Text> buttonTexts;

    /*********************************************************
     * Member: font                                          *
     * Description: Font used for button texts.              *
     *********************************************************/
    sf::Font font;

    /*********************************************************
     * Member: hoveredIndex                                  *
     * Description: Index of the currently hovered button.   *
     *********************************************************/
    int hoveredIndex;
};

/*************************************************************
 * Function: runGame(sf::RenderWindow& window, const sf::Font& font) *
 * Description: Runs the main game logic.                   *
 * Input parameters: window (sf::RenderWindow&),            *
 * font (const sf::Font&)                                   *
 * Returns: None                                            *
 * Preconditions: Window and font are initialized.          *
 * Postconditions: Game logic is executed.                  *
 *************************************************************/
void runGame(sf::RenderWindow& window, const sf::Font& font);

/*************************************************************
 * Function: showMenu(sf::RenderWindow& window)             *
 * Description: Displays the main menu and handles user     *
 * interaction.                                             *
 * Input parameters: window (sf::RenderWindow&)             *
 * Returns: int - Selected menu option.                     *
 * Preconditions: Window is initialized.                    *
 * Postconditions: Menu is displayed, and user input is     *
 * processed.                                               *
 *************************************************************/
int showMenu(sf::RenderWindow& window);

/*************************************************************
 * Function: showHowToPlay(sf::RenderWindow& window, const sf::Font& font) *
 * Description: Displays the "How to Play" screen.          *
 * Input parameters: window (sf::RenderWindow&),            *
 * font (const sf::Font&)                                   *
 * Returns: None                                            *
 * Preconditions: Window and font are initialized.          *
 * Postconditions: "How to Play" screen is displayed.       *
 *************************************************************/
void showHowToPlay(sf::RenderWindow& window, const sf::Font& font);

#endif
