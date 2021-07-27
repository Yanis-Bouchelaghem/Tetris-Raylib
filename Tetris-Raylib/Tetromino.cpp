#include "Tetromino.h"

Tetromino::Tetromino(int dimension, Color color, const bool* _shape)
	:
	color(color),
	dimension(dimension),
	shape(_shape,_shape + dimension*dimension)
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
	Tetromino(squareDimension,color, square)
{}

Jay::Jay(Color color)
	:
	Tetromino(jayDimension,color, jay)
{}

Elle::Elle(Color color)
	:
	Tetromino(elleDimension, color, elle)
{}

Ess::Ess(Color color)
	:
	Tetromino(essDimension, color, ess)
{}

Zed::Zed(Color color)
	:
	Tetromino(zedDimension, color, zed)
{}

Tee::Tee(Color color)
	:
	Tetromino(teeDimension, color, tee)
{}

Straight::Straight(Color color)
	:
	Tetromino(straightDimension, color, straight)
{}
