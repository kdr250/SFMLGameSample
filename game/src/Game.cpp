#include "Game.h"

void Game::InitializeVariables() {}

void Game::InitializeWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width  = 800;
    this->window           = std::make_unique<sf::RenderWindow>(this->videoMode,
                                                      "Game1",
                                                      (sf::Style::Titlebar | sf::Style::Close));
}

Game::Game()
{
    this->InitializeVariables();
    this->InitializeWindow();
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
    this->window->clear(sf::Color(255, 0, 0, 255));
    this->window->display();
}
