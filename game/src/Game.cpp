#include "Game.h"

void Game::InitializeVariables() {}

void Game::InitializeWindow()
{
    this->videoMode = sf::VideoMode(800, 600);

    this->window = std::make_unique<sf::RenderWindow>(this->videoMode,
                                                      "Game2",
                                                      sf::Style::Close | sf::Style::Titlebar);
}

Game::Game()
{
    this->InitializeVariables();
    this->InitializeWindow();
}

Game::~Game() {}

const bool Game::IsRunning() const
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
    this->player.Render(*this->window);
    this->window->display();
}
