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
	const float dt = GetFrameTime();
	playerController.HandleInput(Context::running, dt);

	timer -= dt;
	if (timer <= 0.0f)
	{
		//Move the tetromino down
		if (!board.MoveTetromino({ 0,1 }))
		{
			//If the tetromino couldn't be moved, then it should be put
			board.PutTetromino();
		}
		timer = delay;
	}
}

//Game rendering goes here
void Game::Render() 
{
	ClearBackground(BLACK);
	board.Draw({150,50});
}
