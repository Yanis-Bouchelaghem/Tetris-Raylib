#pragma once
#include <vector>
#include "RaylibCpp.h"

class Tetromino
{
public:
	Tetromino(int dimension,Color color);

	void RotateRight();
	void RotateLeft();
	virtual ~Tetromino() noexcept = default;

protected:
	std::vector<bool> shape;
	const int dimension;
	Color color;
};

class Square : public Tetromino
{
public:
	Square(Color color);

	static constexpr int squareDimension = 2;
	static constexpr bool square[squareDimension*squareDimension] = { 1,1,
																	  1,1 };
};

class Jay : public Tetromino
{
public:
	Jay(Color color);

	static constexpr int JayDimension = 3;
	static constexpr bool jay[JayDimension*JayDimension] = { 1,0,0,
															 1,1,1,
															 0,0,0 };
};