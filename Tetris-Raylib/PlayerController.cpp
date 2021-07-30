#include "PlayerController.h"
#include "RaylibCpp.h"

//Init the global player controller
PlayerController playerController;

void PlayerController::Bind(int key, Context context, KeyState state, std::function<void(float dt)> func)
{
	callbacks[{key,context,state}] = func;
}

void PlayerController::HandleInput(Context context) const
{
	const float dt = GetFrameTime();
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

//An overload of the () operator to provide a hash function for the unordered_map
size_t PlayerController::Requirement::operator()(const Requirement& requirement) const
{
	//Simply hashes all of the member variables individually then combines them
	std::hash<int> hasher;
	auto hashKey = hasher(key);
	hashKey ^= hasher(context) + 0x9e3779b9 + (hashKey << 6) + (hashKey >> 2);
	hashKey ^= hasher(keyState) + 0x9e3779b9 + (hashKey << 6) + (hashKey >> 2);

	return hashKey;
}

bool PlayerController::Requirement::operator==(const Requirement& rhs) const
{
	return (context==rhs.context && key==rhs.key && keyState==rhs.keyState);
}
