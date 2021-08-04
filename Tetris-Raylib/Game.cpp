#include <assert.h>
#include "RaylibCpp.h"
#include "Game.h"


Game::Game(int windowWidth, int windowHeight, std::string title)
	:
	board(10,20)
{
	assert(!IsWindowReady()); //If assertion fails : A window already exists
	InitWindow(windowWidth, windowHeight, title.c_str());
	SetTargetFPS(targetFPS);
	state = Context::running;
	score = 0;
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
			score += board.ClearCompletedLines() * lineScore + 5;
			if (board.IsLost())
			{
				state = Context::gameOver;
			}
		}
		timer = delay;
	});
	playerController.Bind(KEY_SPACE, Context::running, KeyState::isKeyPressed, [=](float dt) {
		board.DropTetromino();
		score += board.ClearCompletedLines() * lineScore + 10;
		score += board.ClearCompletedLines() * lineScore + 5;
		if (board.IsLost())
		{
			state = Context::gameOver;
		}
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
	if (state == Context::running)
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
				score += board.ClearCompletedLines() * lineScore + 5;
				if (board.IsLost())
				{
					state = Context::gameOver;
				}
			}
			timer = delay;
		}
	}
}

//Game rendering goes here
void Game::Render() 
{
	ClearBackground(BLACK);
	board.Draw({ 150,50 });
	rayCpp::DrawText("Next tetromino :", { 450,100 }, 30, RAYWHITE);
	if (state == Context::running)
	{
		rayCpp::DrawText("Score :", { 450, 350 }, 30, RAYWHITE);
		rayCpp::DrawText(TextFormat("%d", score), { 450, 400 }, 50, RAYWHITE);
	}
	else
	{
		rayCpp::DrawRectangle({0,0},{GetScreenWidth(),GetScreenHeight()},{0,0,0,190});
		rayCpp::DrawText("GAME OVER", { GetScreenWidth() / 2 - 155, GetScreenHeight() / 2 - 150 }, 50, RAYWHITE);
		rayCpp::DrawText("Score :", { GetScreenWidth()/2 - 50, GetScreenHeight()/2 - 50}, 30, RAYWHITE);
		rayCpp::DrawText(TextFormat("%d", score), { GetScreenWidth()/2 - 50, GetScreenHeight()/2}, 50, RAYWHITE);
	}

}
