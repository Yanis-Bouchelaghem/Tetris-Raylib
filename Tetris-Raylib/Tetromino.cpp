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
	for (bool b : square)
	{
		shape.emplace_back(b);
	}
}

Jay::Jay(Color color)
	:
	Tetromino(JayDimension,color)
{
	for (bool b : jay)
	{
		shape.emplace_back(b);
	}
}
