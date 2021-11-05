#include "utils.h"

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

float norm(const sf::Vector2f& vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}
