#include "game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        // if succeeded create our window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        // if the window creation succeeded create our renderer
        if (m_pWindow != 0)
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0)
            {
                std::cout << "renderer creation success\n";
                // set to black
                // This function expects Red, Green, Blue and Alpha as color values
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false;
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false;
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // sdl could not initialize
    }

    std::cout << "init success\n";
    m_textureManager.load("assets/gameassets/player.png", "animate", m_pRenderer);
    m_isRunning = true; // everything initiated successfully, start the main loop

    return true;
}

void Game::render()
{
    // clear the renderer to the draw color
    SDL_RenderClear(m_pRenderer);

    m_textureManager.drawFrame("animate", 0, 0, 128, 256, 1, m_currentFrame, m_pRenderer);

    // draw to the screen
    SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_isRunning = false;
                break;

            default:
                break;
        }
    }
}

void Game::update()
{
    m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
}
