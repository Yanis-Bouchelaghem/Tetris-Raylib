#include <raylib.h>
#include <assert.h>
#include "Game.h"

Game::Game(int windowWidth, int windowHeight, std::string title)
	:
	board(10,20)
{
	assert(!IsWindowReady()); //If assertion fails : A window already exists.
	InitWindow(windowWidth, windowHeight, title.c_str());
	SetTargetFPS(targetFPS);
	//////////// Initialize stuff here ////////////
	for (int x = 0; x < 10; ++x)
	{
		for (int y = 0; y < 20; ++y)
		{
			board.putBlock(x, y, RED);
		}
	}
}

Game::~Game()
{
	assert(IsWindowReady()); //If assertion fails : Window is not open.
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return WindowShouldClose();
}

//Advances the logic of the game and produces a new frame
void Game::Tick()
{
	BeginDrawing();
	Update();
	Render();
	EndDrawing();
}

//Game logic goes here
void Game::Update()	
{

}

//Game rendering goes here
void Game::Render() 
{
	ClearBackground(BLACK);
	board.Draw(50,50);
}
