#pragma once
#include <unordered_map>
#include <functional>
class PlayerController
{
public:
	void Bind(int key, std::function<void()> func);
	void DispatchInput() const;
private:
	std::unordered_map<int,std::function<void()>> callbacks;
};

extern PlayerController playerController;