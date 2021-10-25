#include <SFML/Graphics.hpp>
#include <iostream>

// === Constants ===

using uint = unsigned int;

constexpr uint WINDOW_WIDTH = 800;
constexpr uint WINDOW_HEIGHT = 600;
const sf::Color WINDOW_BACKGROUND_COLOR = sf::Color(0xFF, 0xFF, 0xFF);

constexpr uint ARROW_INITIAL_X = 100;
constexpr uint ARROW_INITIAL_Y = 100;
const sf::Color ARROW_FILL_COLOR = sf::Color(0xFF, 0xFF, 0);
const sf::Color ARROW_OUTLINE_COLOR = sf::Color(0, 0, 0);
const float ARROW_OUTLINE_THICKNESS = 2.f;

// === Data structures ===

struct Arrow
{
    sf::RectangleShape shape;
};

// === Function declarations ===

void initArrow(Arrow& arrow);
void pollEvents(sf::RenderWindow& window);
void redrawFrame(sf::RenderWindow& window, Arrow& arrow);

// === Main program ===

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
        "Arrow",
        sf::Style::Default,
        settings);

    Arrow arrow;

    initArrow(arrow);
    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window, arrow);
    }
}

// === Function definitions ===

void initArrow(Arrow& arrow)
{
    arrow.shape.setSize({ 100, 100 });
    arrow.shape.setPosition(ARROW_INITIAL_X, ARROW_INITIAL_Y);
    arrow.shape.setFillColor(ARROW_FILL_COLOR);
    arrow.shape.setOutlineColor(ARROW_OUTLINE_COLOR);
    arrow.shape.setOutlineThickness(ARROW_OUTLINE_THICKNESS);
}

void pollEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow& window, Arrow& arrow)
{
    window.clear(WINDOW_BACKGROUND_COLOR);
    window.draw(arrow.shape);
    window.display();
}
