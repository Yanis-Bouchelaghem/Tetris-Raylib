#pragma once
#include <vector>
#include "RaylibCpp.h"

class Tetromino
{
public:
	Tetromino(int dimension,Color color);

	void RotateLeft();
	void RotateRight();
	virtual ~Tetromino() noexcept = default;

protected:
	std::vector<bool> shape;
	int dimension;
	Color color;
};

class Square : public Tetromino
{
public:
	Square(Color color);

public:
	static constexpr int squareDimension = 2;
	static constexpr bool square[squareDimension*2] = { 1,1,
													    1,1 };
};