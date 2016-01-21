#ifndef __Game__
#define __Game__

#include "SDL.h"
#include <iostream>

class Game
{
public:
    Game(){}
    ~Game(){}

    // set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update(){}
    void handleEvents();
    void clean();

    bool isRunning() { return m_isRunning; }

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    bool m_isRunning;
};

#endif // __Game__

