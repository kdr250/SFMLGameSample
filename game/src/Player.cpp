#include "Player.h"

void Player::InitializeVariables()
{
    this->movementSpeed = 10.0f;
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

void Player::Update(std::unique_ptr<sf::RenderWindow>& window)
{
    // Window collision
    this->UpdateInput();
}

void Player::Render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}
