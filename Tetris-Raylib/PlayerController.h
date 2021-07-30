#pragma once
#include <map>
#include <functional>

enum KeyState
{
	isKeyPressed,
	isKeyDown,
	isKeyReleased,
	isKeyUp
};
enum Context
{
	running,
	pause,
	gameOver
};

//A global player controller
class PlayerController
{
public:
	void Bind(int key, Context context, KeyState state, std::function<void(float dt)> func);
	void HandleInput(Context context) const;

private:
	class Requirement
	{
	public:
		int key;
		Context context;
		KeyState keyState;
	public:
		//size_t operator()(const Requirement& requirement) const;
		bool operator<(const Requirement& rhs) const;
	};
private:
	std::map<Requirement,std::function<void(float dt)>> callbacks;
};

//Make the only 
extern PlayerController playerController;