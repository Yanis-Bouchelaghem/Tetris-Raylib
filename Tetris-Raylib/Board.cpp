#include <assert.h>
#include "Board.h"
#include "Rect.h"

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
	//Draw the border of the board
	Vec2<int> borderTopLeft(posX - blockSize/2, posY - blockSize/2);
	Vec2<int> borderWidthHeight((width + 1) * blockSize, (height + 1) * blockSize);
	rayCpp::DrawRectangleLinesEx(Rect<int>(borderTopLeft, borderWidthHeight),
								 blockSize/2,
								 borderColor);
	
	//Draw the content of the board
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Block block = content[y * width + x];
			Vec2<int> sceenPos(posX + x * blockSize, posY +  y * blockSize);
			rayCpp::DrawRectangle(sceenPos + blockPadding,
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


