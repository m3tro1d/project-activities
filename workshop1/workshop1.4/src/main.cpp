#include <SFML/Graphics.hpp>
#include <iostream>

// === Typedefs ===

using uint = unsigned int;

// === Constants ===

// Window
constexpr uint WINDOW_WIDTH = 800;
constexpr uint WINDOW_HEIGHT = 600;

const sf::Color WINDOW_BACKGROUND_COLOR = sf::Color(0xFF, 0xFF, 0xFF);

// Cat
constexpr uint CAT_SPRITE_WIDTH = 38;
constexpr uint CAT_SPRITE_HEIGHT = 35;
constexpr uint CAT_INITIAL_X = WINDOW_WIDTH / 2 - CAT_SPRITE_WIDTH;
constexpr uint CAT_INITIAL_Y = WINDOW_HEIGHT / 2 - CAT_SPRITE_HEIGHT;
const std::string CAT_TEXTURE_PATH = "assets/cat.png";

// Pointer
constexpr uint POINTER_SPRITE_WIDTH = 38;
constexpr uint POINTER_SPRITE_HEIGHT = 35;
const std::string POINTER_TEXTURE_PATH = "assets/red_pointer.png";

// === Function declarations ===

// Initialization
void initCat(sf::Sprite& cat);
void initPointer(sf::Sprite& pointer);

// Events handling
void pollEvents(sf::RenderWindow& window, sf::Vector2f& clickPosition);
void onMousePressed(const sf::Event::MouseButtonEvent& event, sf::Vector2f& clickPosition);

// Rendering
void redrawFrame(sf::RenderWindow& window, const sf::Sprite& cat, const sf::Sprite& pointer);

// Updating
void update(sf::Sprite& cat, sf::Sprite& pointer, const sf::Vector2f& clickPosition);
sf::Vector2f calculatePointerPosition(const sf::Vector2f& clickPosition);

// === Main program ===

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
        "Cat's Moving :o",
        sf::Style::Default,
        settings);

    sf::Sprite cat;
    sf::Sprite pointer;

    sf::Vector2f clickPosition;

    initCat(cat);
    initPointer(pointer);
    while (window.isOpen())
    {
        pollEvents(window, clickPosition);
        update(cat, pointer, clickPosition);
        redrawFrame(window, cat, pointer);
    }
}

// === Function definitions ===

void initCat(sf::Sprite& cat)
{
    cat.setPosition(CAT_INITIAL_X, CAT_INITIAL_Y);

    static sf::Texture texture;
    if (!texture.loadFromFile(CAT_TEXTURE_PATH))
    {
        std::exit(1);
    }
    cat.setTexture(texture);
}

void initPointer(sf::Sprite& pointer)
{
    static sf::Texture texture;
    if (!texture.loadFromFile(POINTER_TEXTURE_PATH))
    {
        std::exit(1);
    }
    pointer.setTexture(texture);
}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& clickPosition)
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            onMousePressed(event.mouseButton, clickPosition);
            break;
        default:
            break;
        }
    }
}

void onMousePressed(const sf::Event::MouseButtonEvent& event, sf::Vector2f& clickPosition)
{
    if (event.button == sf::Mouse::Left)
    {
        std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
        clickPosition = { float(event.x), float(event.y) };
    }
}

void redrawFrame(sf::RenderWindow& window, const sf::Sprite& cat, const sf::Sprite& pointer)
{
    window.clear(WINDOW_BACKGROUND_COLOR);
    window.draw(pointer);
    window.draw(cat);
    window.display();
}

void update(sf::Sprite& cat, sf::Sprite& pointer, const sf::Vector2f& clickPosition)
{
    pointer.setPosition(calculatePointerPosition(clickPosition));
}

sf::Vector2f calculatePointerPosition(const sf::Vector2f& clickPosition)
{
    return {
        clickPosition.x - POINTER_SPRITE_WIDTH / 2,
        clickPosition.y - POINTER_SPRITE_HEIGHT / 2,
    };
}
