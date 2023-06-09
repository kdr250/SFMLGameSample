#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
private:
    sf::RectangleShape shape;
    int hp;
    int hpMax;

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

    const sf::RectangleShape& GetShape() const;
    const int& GetHp() const;
    const int& GetHpMax() const;

    void TakeDamage(const int damage);
    void GainHealth(const int health);
};
