#include "SwagBall.h"

void SwagBall::InitializeShape(const sf::RenderWindow& window)
{
    this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
    sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    this->shape.setFillColor(color);
    float x = static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width);
    this->shape.setPosition(sf::Vector2f(x, 0.0f));
}

SwagBall::SwagBall(const sf::RenderWindow& window)
{
    this->InitializeShape(window);
}

SwagBall::~SwagBall() {}

void SwagBall::Update() {}

void SwagBall::Render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}
