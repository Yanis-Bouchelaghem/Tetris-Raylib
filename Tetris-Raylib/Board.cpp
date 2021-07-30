#include <assert.h>
#include "Board.h"
#include "Rect.h"
#include "PlayerController.h"
//Creates a board with width * height blocks
Board::Board(int _width, int _height)
	:
	width(_width),
	height(_height),
	activeTetromino(std::make_unique<Zed>(BLUE)),
	tetrominoPos(_width/2 - activeTetromino->GetDimension()/2, 0)
{
	assert(_width > 0 && _height > 0); //If assertion fails : width or height is negative
	content.resize(size_t(width*height));
	activeTetromino->RotateLeft();

	//Bind the player controls
	playerController.Bind(KEY_LEFT,[this](){
		RotateTetrominoRight();
	});
	playerController.Bind(KEY_RIGHT,[this](){
		RotateTetrominoLeft();
	});
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

void Board::RotateTetrominoLeft()
{
	activeTetromino->RotateLeft();
}

void Board::RotateTetrominoRight()
{
	activeTetromino->RotateRight();
}

//Draws the whole board at the given position (the given position is the top-left of the board)
void Board::Draw(Vec2<int> screenPos) const
{
	//Draw the border of the board
	Vec2<int> borderTopLeft(screenPos.GetX() - blockSize / 2, screenPos.GetY() - blockSize / 2);
	Vec2<int> borderWidthHeight((width + 1) * blockSize, (height + 1) * blockSize);
	rayCpp::DrawRectangleLinesEx(Rect<int>(borderTopLeft, borderWidthHeight),
		blockSize / 2,
		borderColor);

	//Draw the content of the board
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Block block = content[y * width + x];
			Vec2<int> sceenscreenPos(screenPos.GetX() + x * blockSize, screenPos.GetY() + y * blockSize);
			rayCpp::DrawRectangle(sceenscreenPos + blockPadding,
				Vec2<int>{blockSize,blockSize} - blockPadding,
				block.color);
		}
	}

	//Draw the active tetromino
	activeTetromino->Draw(screenPos + (tetrominoPos * blockSize), blockSize, blockPadding);
}

void Board::Draw(int posX, int posY) const
{
	Draw({ posX,posY });
}

void Board::Block::putColor(Color c)
{
	color = c;
	bExists = true;
}


