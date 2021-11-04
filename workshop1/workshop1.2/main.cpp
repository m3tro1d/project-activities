#include <SFML/Graphics.hpp>
#include <iostream>

// === Typedefs ===

using uint = unsigned int;

// === Constants ===

constexpr uint WINDOW_WIDTH = 800;
constexpr uint WINDOW_HEIGHT = 600;
const sf::Color WINDOW_BACKGROUND_COLOR = sf::Color(0xFF, 0xFF, 0xFF);

constexpr uint ARROW_INITIAL_X = WINDOW_WIDTH / 2;
constexpr uint ARROW_INITIAL_Y = WINDOW_HEIGHT / 2;
constexpr float ARROW_BASE_WIDTH = 50.f;
constexpr float ARROW_BASE_HEIGHT = 50.f;
const sf::Color ARROW_FILL_COLOR = sf::Color(0xFF, 0xFF, 0);
const sf::Color ARROW_OUTLINE_COLOR = sf::Color(0, 0, 0);
const float ARROW_OUTLINE_THICKNESS = 2.f;
constexpr float ARROW_MAX_SPEED = 20.f;
constexpr float ARROW_MAX_ANGLE_SPEED = 90.f;

// === Data structures ===

struct Arrow
{
    sf::ConvexShape shape;
};

// === Function declarations ===

void initArrow(Arrow& arrow);
void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition);
void redrawFrame(sf::RenderWindow& window, Arrow& arrow);
void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition);

// === Main program ===

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
        "Moving Arrow",
        sf::Style::Default,
        settings);

    Arrow arrow;
    sf::Vector2f mousePosition;

    initArrow(arrow);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        redrawFrame(window, arrow);
    }
}

// === Function definitions ===

void initArrow(Arrow& arrow)
{
    arrow.shape.setPointCount(7);
    arrow.shape.setPoint(0, { -(ARROW_BASE_WIDTH / 2), ARROW_BASE_HEIGHT });
    arrow.shape.setPoint(1, { -(ARROW_BASE_WIDTH / 2), 0 });
    arrow.shape.setPoint(2, { -ARROW_BASE_WIDTH, 0 });
    arrow.shape.setPoint(3, { 0, -ARROW_BASE_HEIGHT });
    arrow.shape.setPoint(4, { ARROW_BASE_WIDTH, 0 });
    arrow.shape.setPoint(5, { ARROW_BASE_WIDTH / 2, 0 });
    arrow.shape.setPoint(6, { ARROW_BASE_WIDTH / 2, ARROW_BASE_HEIGHT });

    arrow.shape.setPosition(ARROW_INITIAL_X, ARROW_INITIAL_Y);
    arrow.shape.setFillColor(ARROW_FILL_COLOR);
    arrow.shape.setOutlineColor(ARROW_OUTLINE_COLOR);
    arrow.shape.setOutlineThickness(ARROW_OUTLINE_THICKNESS);
}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition)
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
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

void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

    mousePosition = { float(event.x), float(event.y) };
}
