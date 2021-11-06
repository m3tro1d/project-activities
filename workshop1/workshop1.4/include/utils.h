#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

float norm(const sf::Vector2f& vec);
sf::Vector2f normalized(const sf::Vector2f& vec);

sf::Vector2f calculateMovementPosition(const sf::Vector2f& currentPosition,
    const sf::Vector2f& direction,
    const float speed,
    const float dt);
