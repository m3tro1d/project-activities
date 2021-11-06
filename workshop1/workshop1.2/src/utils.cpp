#include "utils.h"

float norm(const sf::Vector2f& vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

sf::Vector2f normalized(const sf::Vector2f& vec)
{
    return vec / norm(vec);
}
