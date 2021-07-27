#include "Tetromino.h"

Tetromino::Tetromino(int dimension, Color color)
	:
	color(color),
	dimension(dimension)
{
}

void Tetromino::RotateRight()
{
	std::vector<bool> copy = shape;
	for (int y = 0; y < dimension; ++y)
	{
		for (int x = 0; x < dimension; ++x)
		{
			//Algorithm to rotate a square array 90° clockwise (width-1 + x*width -y)
			shape[dimension-1 + x*dimension - y] = copy[y*dimension + x];
		}
	}
}

void Tetromino::RotateLeft()
{
	std::vector<bool> copy = shape;
	for (int y = 0; y < dimension; ++y)
	{
		for (int x = 0; x < dimension; ++x)
		{
			//Algorithm to rotate a square array 90° counter-clockwise ( (width * (width-1)) - (x * width) - y )
			shape[dimension * (dimension-1) - (x * dimension) + y] = copy[y * dimension + x];
		}
	}
}

Square::Square(Color color)
	:
	Tetromino(squareDimension,color)
{
	for (const bool block : square)
	{
		shape.emplace_back(block);
	}
}

Jay::Jay(Color color)
	:
	Tetromino(jayDimension,color)
{
	for (const bool block : jay)
	{
		shape.emplace_back(block);
	}
}

Elle::Elle(Color color)
	:
	Tetromino(elleDimension, color)
{
	for (const bool block : elle)
	{
		shape.emplace_back(block);
	}
}

Ess::Ess(Color color)
	:
	Tetromino(essDimension, color)
{
	for (const bool block : ess)
	{
		shape.emplace_back(block);
	}
}

Zed::Zed(Color color)
	:
	Tetromino(zedDimension, color)
{
	for (const bool block : zed)
	{
		shape.emplace_back(block);
	}
}

Tee::Tee(Color color)
	:
	Tetromino(teeDimension, color)
{
	for (const bool block : tee)
	{
		shape.emplace_back(block);
	}
}

Straight::Straight(Color color)
	:
	Tetromino(straightDimension, color)
{
	for (const bool block : straight)
	{
		shape.emplace_back(block);
	}
}
