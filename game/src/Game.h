#pragma once

#include <ctime>
#include <iostream>
#include <memory>

#include "Player.h"

class Game
{
private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::VideoMode videoMode;
    bool endGame;
    sf::Event event;

    Player player;

    void InitializeVariables();
    void InitializeWindow();

public:
    Game();
    ~Game();

    const bool IsRunning() const;
    void PollEvent();

    void Update();
    void Render();
};
