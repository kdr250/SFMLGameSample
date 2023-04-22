#include "SwagBall.h"

void SwagBall::InitializeShape(const sf::RenderWindow& window)
{
    this->shape.setRadius(static_cast<float>(rand() % 10 + 10));

    sf::Color color;
    switch (this->type)
    {
        case DEFAULT:
            color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
            break;
        case DAMAGING:
            color = sf::Color::Red;
            this->shape.setOutlineColor(sf::Color::White);
            this->shape.setOutlineThickness(2.0f);
            break;
        case HEALING:
            color = sf::Color::Green;
            this->shape.setOutlineColor(sf::Color::White);
            this->shape.setOutlineThickness(2.0f);
            break;
    }

    this->shape.setFillColor(color);
    sf::FloatRect bounds = this->shape.getGlobalBounds();
    float x              = static_cast<float>(rand() % window.getSize().x - bounds.width);
    float y              = static_cast<float>(rand() % window.getSize().y - bounds.height);
    this->shape.setPosition(sf::Vector2f(x, y));
}

SwagBall::SwagBall(const sf::RenderWindow& window, int type) : type(type)
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

const int& SwagBall::GetType() const
{
    return this->type;
}
