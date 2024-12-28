#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

// this class represents the game
class Game
{
    // private members of the class
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

    // public members of the class
public:
    Game();
    ~Game();
    void Initialize();
    void Run();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

    int windowWidth;
    int windowHeight;
};

#endif // GAME_H
