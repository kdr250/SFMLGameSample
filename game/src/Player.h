#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
private:
    sf::RectangleShape shape;

    void InitializeVariables();
    void InitializeShape();

public:
    Player();
    ~Player();

    void Update();
    void Render(sf::RenderTarget& target);
};
