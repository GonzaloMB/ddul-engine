#include <iostream>
#include "./Game/Game.h"

// constructor
int main(int arfc, char *argv[])
{
    // create a game object
    Game game;
    // initialize the game
    game.Initialize();
    // run the game
    game.Run();
    // destroy the game
    game.Destroy();

    return 0;
}
