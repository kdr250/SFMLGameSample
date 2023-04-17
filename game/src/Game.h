#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

class Game
{
private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::Font font;
    sf::Text uiText;

    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePositionView;

    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;
    bool endGame;

    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    void InitializeVariables();
    void InitializeWindow();
    void InitializeFont();
    void InitializeText();
    void InitializeEnemy();

public:
    Game();
    virtual ~Game();

    const bool IsRunning() const;
    const bool GetEndGame() const;

    void PollEvent();
    void Update();
    void Render();
    void UpdateMousePosition();
    void SpawnEnemy();
    void UpdateEnemies();
    void RenderEnemies(sf::RenderTarget& target);
    void RenderText(sf::RenderTarget& target);
    void UpdateText();
};
