#include "Game.h"

void Game::InitializeVariables()
{
    this->endGame       = false;
    this->spawnTimerMax = 10.0f;
    this->spawnTimer    = this->spawnTimerMax;
    this->maxSwagBalls  = 10;
    this->points        = 0;
}

void Game::InitializeWindow()
{
    this->videoMode = sf::VideoMode(800, 600);
    this->window    = std::make_unique<sf::RenderWindow>(this->videoMode,
                                                      "Game2",
                                                      sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void Game::InitializeFont()
{
    if (!this->font.loadFromFile("asset/font/PixellettersFull.ttf"))
    {
        std::cout << "Error: Could not load font!" << std::endl;
    }
}

void Game::InitializeText()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(32);
    this->uiText.setPosition(0.0f, 0.0f);
    this->uiText.setString("NONE");
}

Game::Game()
{
    this->InitializeVariables();
    this->InitializeWindow();
    this->InitializeFont();
    this->InitializeText();
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
    this->SpawnSwagBalls();
    this->player.Update(this->window);
    this->UpdateCollision();
    this->UpdateGui();
}

void Game::UpdateCollision()
{
    for (size_t i = 0; i < this->swagBalls.size(); i++)
    {
        if (this->player.GetShape().getGlobalBounds().intersects(
                this->swagBalls[i].GetShape().getGlobalBounds()))
        {
            this->swagBalls.erase(this->swagBalls.begin() + i);
            this->points++;
        }
    }
}

void Game::UpdateGui()
{
    std::stringstream ss;
    ss << "- Points: " << this->points;
    this->uiText.setString(ss.str());
}

void Game::Render()
{
    this->window->clear();
    this->player.Render(*this->window);
    for (auto& ball : this->swagBalls)
    {
        ball.Render(*this->window);
    }
    this->RenderGui(*this->window);
    this->window->display();
}

void Game::RenderGui(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}

void Game::SpawnSwagBalls()
{
    if (this->spawnTimer < spawnTimerMax)
    {
        this->spawnTimer += 1.0f;
    }
    else
    {
        if (this->swagBalls.size() < this->maxSwagBalls)
        {
            this->swagBalls.push_back(SwagBall(*this->window));
        }
        this->spawnTimer = 0.0f;
    }
}
