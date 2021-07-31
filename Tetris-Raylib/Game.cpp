#include <assert.h>
#include "RaylibCpp.h"
#include "Game.h"
#include "PlayerController.h"

Game::Game(int windowWidth, int windowHeight, std::string title)
	:
	board(10,20)
{
	assert(!IsWindowReady()); //If assertion fails : A window already exists.
	InitWindow(windowWidth, windowHeight, title.c_str());
	SetTargetFPS(targetFPS);
	//////////// Initialize stuff here ////////////
	/*for (int x = 0; x < 10; ++x)
	{
		for (int y = 0; y < 20; ++y)
		{
			board.putBlock(x, y, RED);
		}
	}*/
	board.putBlock(7,3,RED);
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
	playerController.HandleInput(Context::running);

}

//Game rendering goes here
void Game::Render() 
{
	ClearBackground(BLACK);
	board.Draw({150,50});
}
