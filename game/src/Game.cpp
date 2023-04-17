#include "Game.h"

void Game::InitializeVariables()
{
    this->points             = 0;
    this->enemySpawnTimerMax = 10.0f;
    this->enemySpawnTimer    = this->enemySpawnTimerMax;
    this->maxEnemies         = 10;
    this->mouseHeld          = false;
    this->health             = 10;
}

void Game::InitializeWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width  = 800;
    this->window           = std::make_unique<sf::RenderWindow>(this->videoMode,
                                                      "Game1",
                                                      (sf::Style::Titlebar | sf::Style::Close));
    this->window->setFramerateLimit(60);
}

void Game::InitializeFont()
{
    if (!this->font.loadFromFile("asset/font/Dosis-Light.ttf"))
    {
        std::cout << "Error: failed to load font!";
    }
}

void Game::InitializeText()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(32);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");
}

void Game::InitializeEnemy()
{
    this->enemy.setPosition(sf::Vector2f(100.0f, 100.0f));
    this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.0f);
}

Game::Game()
{
    this->InitializeVariables();
    this->InitializeWindow();
    this->InitializeFont();
    this->InitializeText();
    this->InitializeEnemy();
}

Game::~Game() {}

const bool Game::IsRunning() const
{
    return this->window->isOpen();
}

const bool Game::GetEndGame() const
{
    return this->endGame;
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
    if (!this->endGame)
    {
        this->UpdateMousePosition();
        this->UpdateEnemies();
    }
    if (this->health <= 0)
    {
        this->endGame = true;
    }
    this->UpdateText();
}

void Game::Render()
{
    this->window->clear();
    this->RenderEnemies(*this->window);
    this->RenderText(*this->window);
    this->window->display();
}

void Game::UpdateMousePosition()
{
    // Mouse position relative to window
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
    this->mousePositionView   = this->window->mapPixelToCoords(this->mousePositionWindow);
}

void Game::SpawnEnemy()
{
    int maxX = static_cast<int>(this->window->getSize().x - this->enemy.getSize().x);
    float x  = static_cast<float>(rand() % maxX);
    float y  = 0.0f;
    this->enemy.setPosition(x, y);

    int type = rand() % 5;
    switch (type)
    {
        case 0:
            this->enemy.setFillColor(sf::Color::Magenta);
            this->enemy.setSize(sf::Vector2f(10.0f, 10.0f));
            break;
        case 1:
            this->enemy.setFillColor(sf::Color::Blue);
            this->enemy.setSize(sf::Vector2f(30.0f, 30.0f));
            break;
        case 2:
            this->enemy.setFillColor(sf::Color::Cyan);
            this->enemy.setSize(sf::Vector2f(50.0f, 50.0f));
            break;
        case 3:
            this->enemy.setFillColor(sf::Color::Red);
            this->enemy.setSize(sf::Vector2f(70.0f, 70.0f));
            break;
        case 4:
            this->enemy.setFillColor(sf::Color::Green);
            this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
            break;
        default:
            this->enemy.setFillColor(sf::Color::Yellow);
            this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
            break;
    }
    this->enemies.push_back(this->enemy);
}

void Game::UpdateEnemies()
{
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            this->SpawnEnemy();
            this->enemySpawnTimer = 0.0f;
        }
        else
        {
            this->enemySpawnTimer += 1.0f;
        }
    }

    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool shouldDelete = false;
        this->enemies[i].move(0.0f, 3.0f);

        if (this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
            std::cout << "Health: " << this->health << std::endl;
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!this->mouseHeld)
        {
            this->mouseHeld   = true;
            bool shouldDelete = false;
            for (int i = 0; i < this->enemies.size(); i++)
            {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePositionView))
                {
                    shouldDelete = true;
                    this->enemies.erase(this->enemies.begin() + i);

                    if (this->enemies[i].getFillColor() == sf::Color::Magenta)
                    {
                        this->points += 10.0f;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Blue)
                    {
                        this->points += 7.0f;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
                    {
                        this->points += 5.0f;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Red)
                    {
                        this->points += 3.0f;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Green)
                    {
                        this->points += 1.0f;
                    }
                    std::cout << "Points: " << this->points << std::endl;
                }
            }
        }
    }
    else
    {
        this->mouseHeld = false;
    }
}

void Game::RenderEnemies(sf::RenderTarget& target)
{
    for (auto& enemy : this->enemies)
    {
        target.draw(enemy);
    }
}

void Game::RenderText(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}

void Game::UpdateText()
{
    std::stringstream ss;
    ss << "Points: " << this->points << std::endl;
    ss << "Health: " << this->health << std::endl;
    this->uiText.setString(ss.str());
}
