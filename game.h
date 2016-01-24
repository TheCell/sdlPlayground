#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "texturemanager.h"
#include <iostream>

class Game
{
public:
    Game(){}
    ~Game(){}

    // set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();

    bool isRunning() { return m_isRunning; }

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    int m_currentFrame;
    TextureManager m_textureManager;

    bool m_isRunning;
};

#endif // __Game__

