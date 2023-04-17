#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SwagBall
{
private:
    sf::CircleShape shape;

    void InitializeShape(const sf::RenderWindow& window);

public:
    SwagBall(const sf::RenderWindow& window);
    virtual ~SwagBall();

    void Update();
    void Render(sf::RenderTarget& target);
};
