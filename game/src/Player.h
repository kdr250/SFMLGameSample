#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
private:
    sf::RectangleShape shape;

    float movementSpeed;

    void InitializeVariables();
    void InitializeShape();

public:
    Player(float x = 0.0f, float y = 0.0f);
    ~Player();

    void UpdateInput();
    void UpdateWindowBoundsCollision(const std::unique_ptr<sf::RenderWindow>& window);
    void Update(std::unique_ptr<sf::RenderWindow>& window);
    void Render(sf::RenderTarget& target);
};
