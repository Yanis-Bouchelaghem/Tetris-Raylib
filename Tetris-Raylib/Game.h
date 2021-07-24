#pragma once
#include <string>
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
private:
	static constexpr int targetFPS = 60;
};