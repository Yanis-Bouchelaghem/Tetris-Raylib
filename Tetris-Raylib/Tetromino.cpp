#include "Tetromino.h"

Tetromino::Tetromino(int dimension, Color color, const bool* _shape)
	:
	color(color),
	dimension(dimension),
	shape(_shape,_shape + dimension*dimension)
{
}

const std::vector<bool> Tetromino::GetRotatedLeft() const
{
	std::vector<bool> copy(shape.size());
	for (int y = 0; y < dimension; ++y)
	{
		for (int x = 0; x < dimension; ++x)
		{
			//Algorithm to rotate a square array 90° counter-clockwise ( (width * (width-1)) - (x * width) - y )
			copy[dimension * (dimension - 1) - (x * dimension) + y] = shape[y * dimension + x];
		}
	}
	return copy;
}

const std::vector<bool> Tetromino::GetRotatedRight() const
{
	std::vector<bool> copy(shape.size());
	for (int y = 0; y < dimension; ++y)
	{
		for (int x = 0; x < dimension; ++x)
		{
			//Algorithm to rotate a square array 90° clockwise (width-1 + x*width -y)
			copy[dimension - 1 + x * dimension - y] = shape[y * dimension + x];
		}
	}
	return copy;
}

void Tetromino::RotateRight()
{
	shape = GetRotatedRight();
}

void Tetromino::RotateLeft()
{
	shape = GetRotatedLeft();
}

int Tetromino::GetDimension() const
{
	return dimension;
}

const std::vector<bool>& Tetromino::GetCurrentShape() const
{
	return shape;
}

//Draws the tetromino at the given screenPos with the given block size and padding.
void Tetromino::Draw(const Vec2<int> screenPos, const int blockSize, const int blockPadding) const
{
	for (int y = 0; y < dimension; ++y)
	{
		for (int x = 0; x < dimension; ++x)
		{
			if (shape[y * dimension + x])
			{
				//Figure out the coordinates of the block 
				Vec2<int> blockTopLeft{x* blockSize, y* blockSize};
				//Add the screen position and the padding to it
				blockTopLeft += screenPos + blockPadding;

				rayCpp::DrawRectangle(blockTopLeft,
									  Vec2<int>{blockSize,blockSize} - blockPadding,
									  color);
			}
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
