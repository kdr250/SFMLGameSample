#pragma once

#include <ctime>
#include <iostream>
#include <memory>

#include "Player.h"
#include "SwagBall.h"

class Game
{
private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::VideoMode videoMode;
    bool endGame;
    sf::Event event;

    Player player;

    std::vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;

    void InitializeVariables();
    void InitializeWindow();

public:
    Game();
    ~Game();

    const bool IsRunning() const;
    void PollEvent();

    void Update();
    void Render();

    void SpawnSwagBalls();
};
