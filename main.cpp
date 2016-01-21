#include "game.h"

// our Game object
Game* g_game = 0;

int main(int argc, char* argv[])
{
    g_game = new Game();

    g_game->init("playground", 100, 100, 640, 480, 0);

    while(g_game->isRunning())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }

    g_game->clean();

    return 0;
}

/*int main(int argc, char *argv[])
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        // if succeeded create our window
        g_pWindow = SDL_CreateWindow("Playground", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

        // if the window creation succeeded create our renderer
        if (g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }
    else
    {
        return 1; // sdl could not initialize
    }

    // everything succeeded lets draw the window

    // set to black // This function expects Red, Green, Blue and
    // Alpha as color values
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    // clear the window to black
    SDL_RenderClear(g_pRenderer);

    // show the window
    SDL_RenderPresent(g_pRenderer);

    // set a delay before quitting
    SDL_Delay(5000);

    return 0;
}*/
