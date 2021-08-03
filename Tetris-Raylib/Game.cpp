#include <assert.h>
#include "RaylibCpp.h"
#include "Game.h"
#include "PlayerController.h"

Game::Game(int windowWidth, int windowHeight, std::string title)
	:
	board(10,20)
{
	assert(!IsWindowReady()); //If assertion fails : A window already exists
	InitWindow(windowWidth, windowHeight, title.c_str());
	SetTargetFPS(targetFPS);

	//Bind the player controls
	playerController.Bind(KEY_E, Context::running, KeyState::isKeyPressed, [=](float dt) {
		board.RotateTetrominoRight();
	});
	playerController.Bind(KEY_Q, Context::running, KeyState::isKeyPressed, [=](float dt) {
		board.RotateTetrominoLeft();
	});
	playerController.Bind(KEY_LEFT, Context::running, KeyState::isKeyPressed, [=](float dt) {
		board.MoveTetromino({ -1,0 });
	});
	playerController.Bind(KEY_RIGHT, Context::running, KeyState::isKeyPressed, [=](float dt) {
		board.MoveTetromino({ 1,0 });
	});
	playerController.Bind(KEY_DOWN, Context::running, KeyState::isKeyPressed, [=](float dt) {
		//Move the tetromino down
		if (!board.MoveTetromino({ 0,1 }))
		{
			//If the tetromino couldn't be moved, then it should be put
			board.PutTetromino();
			board.ClearCompletedLines();
		}
		timer = delay;
	});
	playerController.Bind(KEY_SPACE, Context::running, KeyState::isKeyPressed, [=](float dt) {
		board.DropTetromino();
		board.ClearCompletedLines();
	});
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
			board.ClearCompletedLines();
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
