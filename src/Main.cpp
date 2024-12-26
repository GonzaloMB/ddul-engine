#include <iostream>
#include "Game.h"

int main(int arfc, char *argv[])
{
    Game game;

    game.Initialize();
    game.Run();
    game.Destroy();

    return 0;
}
