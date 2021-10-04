#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({ 800, 600 }),
        "House",
        sf::Style::Default,
        settings);

    window.clear(sf::Color(0xFF, 0xFF, 0xFF));

    const sf::Color houseColor = sf::Color(0x4D, 0x2E, 0x0B);
    const sf::Color doorColor = sf::Color(0x18, 0x17, 0x17);
    const sf::Color roofColor = sf::Color(0x5D, 0x1E, 0x17);
    const sf::Color pipeColor = sf::Color(0x3B, 0x38, 0x38);
    const sf::Color smokeColor = sf::Color(0xBF, 0xBF, 0xBF);

    // TODO

    window.display();

    sf::sleep(sf::seconds(5));
}
