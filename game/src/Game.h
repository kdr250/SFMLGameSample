#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>

class Game
{
private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::VideoMode videoMode;
    bool endGame;

    void InitializeVariables();
    void InitializeWindow();

public:
    Game();
    ~Game();

    void Update();
    void Render();
};
