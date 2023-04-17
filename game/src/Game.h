#pragma once

#include <ctime>
#include <iostream>
#include <memory>
#include <sstream>

#include "Player.h"
#include "SwagBall.h"

class Game
{
private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::VideoMode videoMode;
    bool endGame;
    sf::Event event;
    sf::Font font;
    sf::Text uiText;

    Player player;

    int points;

    std::vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;

    void InitializeVariables();
    void InitializeWindow();
    void InitializeFont();
    void InitializeText();

public:
    Game();
    ~Game();

    const bool IsRunning() const;
    void PollEvent();

    void Update();
    void UpdateCollision();
    void UpdateGui();
    void Render();
    void RenderGui(sf::RenderTarget& target);

    void SpawnSwagBalls();
};
