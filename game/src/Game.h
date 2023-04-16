#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

class Game
{
private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::VideoMode videoMode;
    sf::Event event;

    sf::Vector2i mousePositionWindow;

    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    void InitializeVariables();
    void InitializeWindow();
    void InitializeEnemy();

public:
    Game();
    virtual ~Game();

    const bool GetWindowIsOpen() const;

    void PollEvent();
    void Update();
    void Render();
    void UpdateMousePosition();
    void SpawnEnemy();
    void UpdateEnemies();
    void RenderEnemies();
};
