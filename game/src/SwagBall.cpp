#include "SwagBall.h"

void SwagBall::InitializeShape(const sf::RenderWindow& window)
{
    this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
    sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    this->shape.setFillColor(color);
    sf::FloatRect bounds = this->shape.getGlobalBounds();
    float x              = static_cast<float>(rand() % window.getSize().x - bounds.width);
    float y              = static_cast<float>(rand() % window.getSize().y - bounds.height);
    this->shape.setPosition(sf::Vector2f(x, y));
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

const sf::CircleShape& SwagBall::GetShape() const
{
    return this->shape;
}
