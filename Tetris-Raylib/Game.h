#pragma once
#include <string>
#include "Board.h"
class Game //Takes care of setting up the game window and managing the game loop.
{
public:
	Game(int windowWidth, int windowHeight, std::string title);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	~Game();
	bool GameShouldClose() const;
	void Tick();
private:
	void Update();
	void Render();
	static constexpr int targetFPS = 60;
private:
	/////////// Member variables go here ///////////
	Board board;

	//The time it takes for the piece to move down (in seconds)
	float delay = 0.3f;
	float timer = delay;
	//The amount by which the delay is reduced every tetromino landing (in seconds)
	static constexpr float drain = 0.01f;
	//The minimum delay possible (in seconds, making it too low may render the game too hard after a while)
	static constexpr float minDelay = 0.2f;

};