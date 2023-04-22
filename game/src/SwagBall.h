#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum SwagBallTypes
{
    DEFAULT = 0,
    DAMAGING,
    HEALING,
    NROFTYPES
};

class SwagBall
{
private:
    sf::CircleShape shape;
    int type;

    void InitializeShape(const sf::RenderWindow& window);

public:
    SwagBall(const sf::RenderWindow& window, int type);
    virtual ~SwagBall();

    void Update();
    void Render(sf::RenderTarget& target);

    const sf::CircleShape& GetShape() const;
    const int& GetType() const;
};
