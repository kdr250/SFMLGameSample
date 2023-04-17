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

void Game::Update() {}

void Game::Render() {}
