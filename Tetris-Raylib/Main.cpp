#include "Game.h"

int main(void)
{
    Game game(800,600,"Tetris");
    while (!game.GameShouldClose())
    {
        game.Tick();
    }
}