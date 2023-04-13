#include "Game.h"

int main()
{
    Game game;

    // Game loop
    while (game.GetWindowIsOpen())
    {
        // Update
        game.Update();

        // Render
        game.Render();
    }

    return 0;
}
