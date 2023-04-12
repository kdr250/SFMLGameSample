#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    // Windows
    sf::RenderWindow window(sf::VideoMode(640, 480),
                            "SFML Game Sample",
                            sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    // Game loop
    while (window.isOpen())
    {
        // Event polling
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    break;
            }
        }

        // Update
        window.clear(sf::Color::Blue);  // clear old frame

        // Render
        window.display();  // tell app that window is done drawing
    }

    return 0;
}
