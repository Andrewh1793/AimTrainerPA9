#include "menuElements.cpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu");
    sf::Font font;

    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Failed to load font (arial.ttf)");
    }

    while (window.isOpen()) {
        int menuChoice = showMenu(window);

        switch (menuChoice) {
        case 0:
            //put the game stuff
            break;

        case 1:
            showHowToPlay(window, font); // Show "How to Play" screen
            break;

        case 2:
            window.close();
            break;

        default:
            break;
        }
    }

    return 0;
}
