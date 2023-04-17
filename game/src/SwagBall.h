#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SwagBall
{
private:
    sf::CircleShape shape;

    void InitializeShape();

public:
    SwagBall();
    virtual ~SwagBall();

    void Update();
    void Render();
};
