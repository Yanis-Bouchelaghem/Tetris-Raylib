#include <assert.h>
#include "Board.h"

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

void Board::removeBlock(int x, int y)
{
	assert(x >= 0 && x < width); //If assertion fails : x or y is out of bounds
	assert(y >= 0 && y < height);

	content[size_t(y * width + x)].bExists = false;
}

void Board::Block::putColor(Color c)
{
	color = c;
	bExists = true;
}


