#include "Tetromino.h"
#include <assert.h>
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

bool Tetromino::ContainsBlock(Vec2<int> pos)
{
	assert(pos.GetX() >= 0 && pos.GetY() < dimension); //If assertion fails: pos is out of bounds
	assert(pos.GetY() >= 0 && pos.GetY() < dimension);
	return shape[pos.GetY() * dimension + pos.GetX()];
}

Color Tetromino::GetColor() const
{
	return color;
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

//Returns a random tetromino
std::unique_ptr<Tetromino> Tetromino::RandomTetromino()
{
	std::unique_ptr<Tetromino> tetromino;
	switch (GetRandomValue(0, 6))
	{
		case 0:
			tetromino = std::make_unique<Square>();
			break;
		case 1:
			tetromino = std::make_unique<Jay>();
			break;
		case 2:
			tetromino = std::make_unique<Elle>();
			break;
		case 3:
			tetromino = std::make_unique<Ess>();
			break;
		case 4:
			tetromino = std::make_unique<Zed>();
			break;
		case 5:
			tetromino = std::make_unique<Tee>();
			break;
		case 6:
			tetromino = std::make_unique<Straight>();
			break;
	}
	return std::move(tetromino);
}

Square::Square()
	:
	Tetromino(squareDimension,color, square)
{}

Jay::Jay()
	:
	Tetromino(jayDimension,color, jay)
{}

Elle::Elle()
	:
	Tetromino(elleDimension, color, elle)
{}

Ess::Ess()
	:
	Tetromino(essDimension, color, ess)
{}

Zed::Zed()
	:
	Tetromino(zedDimension, color, zed)
{}

Tee::Tee()
	:
	Tetromino(teeDimension, color, tee)
{}

Straight::Straight()
	:
	Tetromino(straightDimension, color, straight)
{}
