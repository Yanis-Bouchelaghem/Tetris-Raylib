#include <raylib.h>
#include <assert.h>
#include "Game.h"

Game::Game(int windowWidth, int windowHeight, std::string title)
{
	assert(!IsWindowReady()); //If assertion fails : A window already exists.
	InitWindow(windowWidth, windowHeight, title.c_str());
	SetTargetFPS(targetFPS);
	//////////// Initialize stuff here ////////////

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
}
