#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ 800, 600 }),
        "Initials",
        sf::Style::Default,
        sf::ContextSettings(0, 0, 8)
    );

    window.clear();

    // TODO

    window.display();

    sf::sleep(sf::seconds(5));
}

// vim: set sw=4
