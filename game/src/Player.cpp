#include "Player.h"

void Player::InitializeVariables() {}

void Player::InitializeShape()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
}

Player::Player()
{
    this->InitializeVariables();
    this->InitializeShape();
}

Player::~Player() {}

void Player::Update() {}

void Player::Render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}
