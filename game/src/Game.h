#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

class Game
{
private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::VideoMode videoMode;
    sf::Event event;

    void InitializeVariables();
    void InitializeWindow();

public:
    Game();
    virtual ~Game();

    const bool GetWindowIsOpen() const;

    void PollEvent();
    void Update();
    void Render();
};
