#include "PlayerController.h"
#include "RaylibCpp.h"

//Init the global player controller
PlayerController playerController;

void PlayerController::Bind(int key, Context context, KeyState state, std::function<void(float dt)> func)
{
	callbacks.emplace(Requirement{ key,context,state },func);
}

void PlayerController::HandleInput(Context context, float dt) const
{
	for (auto& pair : callbacks)
	{
		Requirement requirement = pair.first;
		//Check if the required context is the current one
		if (requirement.context == context)
		{
			//Perform the given key state check
			bool bShouldCall = false;
			switch (requirement.keyState)
			{
				case KeyState::isKeyDown:
					bShouldCall = IsKeyDown(requirement.key);
					break;
				case KeyState::isKeyPressed:
					bShouldCall = IsKeyPressed(requirement.key);
					break;
				case KeyState::isKeyReleased:
					bShouldCall = IsKeyReleased(requirement.key);
					break;
				case KeyState::isKeyUp:
					bShouldCall = IsKeyUp(requirement.key);
					break;
			}
			//If the check returns true, we call the bound function
			if(bShouldCall) pair.second(dt);
		}
	}
}

bool PlayerController::Requirement::operator<(const Requirement& rhs) const
{
	return key<rhs.key;
}
