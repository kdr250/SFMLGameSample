#include "Player.h"

void Player::InitializeVariables()
{
    this->movementSpeed = 10.0f;
    this->hpMax         = 10;
    this->hp            = this->hpMax;
}

void Player::InitializeShape()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
}

Player::Player(float x, float y)
{
    this->InitializeVariables();
    this->InitializeShape();
    this->shape.setPosition(x, y);
}

Player::~Player() {}

void Player::UpdateInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->movementSpeed, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movementSpeed, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.0f, -this->movementSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.0f, this->movementSpeed);
    }
}

void Player::UpdateWindowBoundsCollision(const std::unique_ptr<sf::RenderWindow>& window)
{
    sf::FloatRect playerBounds = this->shape.getGlobalBounds();
    float x                    = playerBounds.left;
    float y                    = playerBounds.top;
    if (playerBounds.left <= 0.0f)
    {
        x = 0.0f;
    }
    else if (playerBounds.left + playerBounds.width >= window->getSize().x)
    {
        x = window->getSize().x - playerBounds.width;
    }
    if (playerBounds.top <= 0.0f)
    {
        y = 0.0f;
    }
    else if (playerBounds.top + playerBounds.height >= window->getSize().y)
    {
        y = window->getSize().y - playerBounds.height;
    }
    this->shape.setPosition(x, y);
}

void Player::Update(std::unique_ptr<sf::RenderWindow>& window)
{
    this->UpdateInput();
    this->UpdateWindowBoundsCollision(window);
}

void Player::Render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}

const sf::RectangleShape& Player::GetShape() const
{
    return this->shape;
}
