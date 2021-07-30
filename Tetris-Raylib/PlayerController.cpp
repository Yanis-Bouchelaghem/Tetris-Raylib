#include "PlayerController.h"
#include "RaylibCpp.h"

//Init the global player controller.
PlayerController playerController;

void PlayerController::Bind(int key, std::function<void()> func)
{
	callbacks[key] = func;
}

void PlayerController::DispatchInput() const
{
	for (auto& pair : callbacks)
	{
		if (IsKeyPressed(pair.first))
		{
			pair.second();
		}
	}
}
