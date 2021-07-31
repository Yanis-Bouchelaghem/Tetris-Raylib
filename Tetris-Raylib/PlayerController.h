#pragma once
#include <map>
#include <functional>

enum class KeyState
{
	isKeyPressed,
	isKeyDown,
	isKeyReleased,
	isKeyUp
};
enum class Context
{
	running,
	pause,
	gameOver
};

//A global player controller, keys can be bound to callback functions depending on a state
class PlayerController
{
public:
	void Bind(int key, Context context, KeyState state, std::function<void(float dt)> func);
	void HandleInput(Context context, float dt) const;

private:
	struct Requirement
	{
		int key;
		Context context;
		KeyState keyState;

		bool operator<(const Requirement& rhs) const;
	};
private:
	std::map<Requirement,std::function<void(float dt)>> callbacks;
};

//Declaring the controller as extern here and instanciating it in the .cpp file
//Anyone who includes this header will be able to bind controls using playerController
extern PlayerController playerController;