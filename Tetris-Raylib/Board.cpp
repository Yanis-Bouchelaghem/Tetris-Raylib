#include <assert.h>
#include "Board.h"

//Creates a board with width * height blocks
Board::Board(int _width, int _height)
	:
	width(_width),
	height(_height)
{
	content.resize(size_t(width*height));
}

void Board::putBlock(int x, int y, Color c)
{
	assert(x >= 0 && x < width); //If assertion fails : x or y is out of bounds
	assert(y >= 0 && y < height);

	content[size_t(y * width + x)].putColor(c);
}

void Board::RemoveBlock(int x, int y)
{
	assert(x >= 0 && x < width); //If assertion fails : x or y is out of bounds
	assert(y >= 0 && y < height);

	content[size_t(y * width + x)].bExists = false;
}

//Draws the whole board at the given position (the given position is the top-left of the board)
void Board::Draw(int posX, int posY) const
{
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			Block block = content[y * width + x];
			DrawRectangle((posX + x * blockSize) + blockPadding,
						  (posY + y * blockSize) + blockPadding,
						  blockSize - blockPadding,
						  blockSize - blockPadding,
						  block.color);
		}
	}
}

void Board::Block::putColor(Color c)
{
	color = c;
	bExists = true;
}


