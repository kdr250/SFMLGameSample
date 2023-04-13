#include "Game.h"

void Game::InitializeVariables() {}

void Game::InitializeWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width  = 800;
    this->window           = std::make_unique<sf::RenderWindow>(this->videoMode,
                                                      "Game1",
                                                      (sf::Style::Titlebar | sf::Style::Close));
    this->window->setFramerateLimit(144);
}

void Game::InitializeEnemy()
{
    this->enemy.setPosition(sf::Vector2f(100.0f, 100.0f));
    this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.0f);
}

Game::Game()
{
    this->InitializeVariables();
    this->InitializeWindow();
    this->InitializeEnemy();
}

Game::~Game() {}

const bool Game::GetWindowIsOpen() const
{
    return this->window->isOpen();
}

void Game::PollEvent()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                }
                break;
        }
    }
}

void Game::Update()
{
    this->PollEvent();
}

void Game::Render()
{
    this->window->clear();
    this->window->draw(this->enemy);
    this->window->display();
}
