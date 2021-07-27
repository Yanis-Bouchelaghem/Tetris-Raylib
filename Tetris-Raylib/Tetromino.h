#pragma once
#include <vector>
#include "RaylibCpp.h"

class Tetromino
{
public:
	Tetromino(int _dimension,Color color);

	virtual void RotateLeft() = 0;
	virtual void RotateRight() = 0;
	virtual ~Tetromino() noexcept = default;

protected:
	std::vector<bool> shape;
	Color color;
};