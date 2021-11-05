#include "utils.h"

// === Typedefs ===

using uint = unsigned int;

// === Constants ===

// Window
constexpr uint WINDOW_WIDTH = 800;
constexpr uint WINDOW_HEIGHT = 600;

const sf::Color WINDOW_BACKGROUND_COLOR = sf::Color(0xFF, 0xFF, 0xFF);

// Arrow
constexpr uint ARROW_INITIAL_X = WINDOW_WIDTH / 2;
constexpr uint ARROW_INITIAL_Y = WINDOW_HEIGHT / 2;
constexpr uint ARROW_ANGLE_OFFSET = 90;

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
    sf::Vector2f position; // Current position
    float rotation = 0; // Current rotation, in radians
};

// === Function declarations ===

// Initialization
void initArrow(Arrow& arrow);

// Events handling
void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition);
void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition);

// Rendering
void redrawFrame(sf::RenderWindow& window, Arrow& arrow);

// Updating
void update(Arrow& arrow, const sf::Vector2f& mousePosition);
void updateArrow(Arrow& arrow);

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
        update(arrow, mousePosition);
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

    arrow.shape.setFillColor(ARROW_FILL_COLOR);
    arrow.shape.setOutlineColor(ARROW_OUTLINE_COLOR);
    arrow.shape.setOutlineThickness(ARROW_OUTLINE_THICKNESS);

    arrow.position = { ARROW_INITIAL_X, ARROW_INITIAL_Y };
    updateArrow(arrow);
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

void update(Arrow& arrow, const sf::Vector2f& mousePosition)
{
    const sf::Vector2f delta = mousePosition - arrow.position;
    arrow.rotation = std::atan2(delta.y, delta.x);
    updateArrow(arrow);
}

void updateArrow(Arrow& arrow)
{
    arrow.shape.setPosition(arrow.position);
    arrow.shape.setRotation(toDegrees(arrow.rotation) + ARROW_ANGLE_OFFSET);
}
