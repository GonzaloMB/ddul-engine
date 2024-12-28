#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
#include <iostream>

// constructor
Game::Game()
{
    isRunning = false;
    std::cout << "Game constructor called!" << std::endl;
}
// destructor
Game::~Game()
{
    std::cout << "Game destructor called!" << std::endl;
}

// this function initializes the game window and renderer
void Game::Initialize()
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }

    // get the current display mode
    SDL_DisplayMode displayMode;
    // get the current display mode of the first display
    SDL_GetCurrentDisplayMode(0, &displayMode);

    // set the window width and height to the display mode width and height
    windowWidth = displayMode.w;
    windowHeight = displayMode.h;

    // create a window with the specified width and height
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowWidth,
        windowHeight,
        SDL_WINDOW_BORDERLESS);

    // check if the window was created successfully
    if (!window)
    {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }

    // create a renderer for the window
    renderer = SDL_CreateRenderer(window, -1, 0);

    // check if the renderer was created successfully
    if (!renderer)
    {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    // set the window to fullscreen
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    isRunning = true;
}

glm::vec2 playerPosition;
glm::vec2 playerVelocity;

// this function sets up the game objects
void Game::Setup()
{
    playerPosition = glm::vec2(10.0, 20.0);
    playerVelocity = glm::vec2(0.5, 0.0);
}

// this function updates the game objects
void Game::Update()
{
    playerPosition.x += playerVelocity.x;
    playerPosition.y += playerVelocity.y;
}

// this function renders the game objects
void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // loads a PNG texture from a file
    SDL_Surface *surface = IMG_Load("./assets/images/tank-tiger-right.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // what is the destination rectangle that the texture will be rendered to
    SDL_Rect dstRect = {
        static_cast<int>(playerPosition.x),
        static_cast<int>(playerPosition.y),
        32,
        32};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);

    // present the renderer
    SDL_RenderPresent(renderer);
}

// this function runs the game loop
void Game::Run()
{
    Setup();
    while (isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

// this function processes the input events
void Game::ProcessInput()
{
    // create an SDL event
    SDL_Event sdlEvent;
    // poll the event
    while (SDL_PollEvent(&sdlEvent))
    {
        // switch on the event type
        switch (sdlEvent.type)
        {
        // if the event is SDL_QUIT
        case SDL_QUIT:
            isRunning = false;
            break;
        // if the event is SDL_KEYDOWN
        case SDL_KEYDOWN:
            if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            break;
        }
    }
}

// this function destroys the window and renderer
void Game::Destroy()
{
    // destroy the renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}