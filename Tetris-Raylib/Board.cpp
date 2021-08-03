#include <assert.h>
#include "Board.h"
#include "Rect.h"
#include "PlayerController.h"
#include <algorithm>
//Creates a board with width * height blocks
Board::Board(int _width, int _height)
	:
	width(_width),
	height(_height),
	activeTetromino(Tetromino::RandomTetromino()),
	tetrominoPos(_width/2 - activeTetromino->GetDimension()/2, 0)
{
	assert(_width > 0 && _height > 0); //If assertion fails : width or height is negative
	content.resize(size_t(width*height));
	UpdatePrediction();
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
	auto rotated = activeTetromino->GetRotatedLeft();
	int leftWallBump = CollideLeftWall(tetrominoPos,rotated, activeTetromino->GetDimension());
	int rightWallBump = CollideRightWall(tetrominoPos, rotated, activeTetromino->GetDimension());

	Vec2<int> newPos = tetrominoPos +Vec2<int>{leftWallBump - rightWallBump, 0};
	if (IsPositionValid(newPos, rotated, activeTetromino->GetDimension()))
	{
		tetrominoPos = newPos;
		activeTetromino->RotateLeft();
	}
	UpdatePrediction();
}

void Board::RotateTetrominoRight()
{
	auto rotated = activeTetromino->GetRotatedRight();
	int leftWallBump = CollideLeftWall(tetrominoPos, rotated, activeTetromino->GetDimension());
	int rightWallBump = CollideRightWall(tetrominoPos, rotated, activeTetromino->GetDimension());

	Vec2<int> newPos = tetrominoPos + Vec2<int>{leftWallBump - rightWallBump, 0};
	if (IsPositionValid(newPos, rotated, activeTetromino->GetDimension()))
	{
		tetrominoPos = newPos;
		activeTetromino->RotateRight();
	}
	UpdatePrediction();
}

void Board::PutTetromino()
{
	//Put the tetromino into the board
	for (int y = 0; y < activeTetromino->GetDimension(); ++y)
	{
		for (int x = 0; x < activeTetromino->GetDimension(); ++x)
		{
			if (activeTetromino->ContainsBlock({ x,y }))
			{
				putBlock(tetrominoPos.GetX() + x, tetrominoPos.GetY() + y, activeTetromino->GetColor());
			}
		}
	}
	NextTetromino();
}

void Board::NextTetromino()
{
	//TODO : Generate new shape
	activeTetromino = Tetromino::RandomTetromino();

	tetrominoPos = { width / 2 - activeTetromino->GetDimension() / 2,0 };
	UpdatePrediction();
}

//Checks if the given shape fits in the given position without overlapping a wall
bool Board::IsWithinBoard(const Vec2<int>& pos, const std::vector<bool>& shape, int dimension) const
{
	for (int y = 0; y < dimension; ++y)
	{
		for (int x = 0; x < dimension; ++x)
		{
			if (shape[y * dimension + x] &&
			(pos.GetX() + x < 0 || pos.GetX() + x >= width || pos.GetY() + y < 0 || pos.GetY() + y >= height))
			{
				return false;
			}
		}
	}
	return true;
}

//If the shape is outside of the left wall, returns the number of blocks necessarry to move the shape back into the board, otherwise returns 0
int Board::CollideLeftWall(const Vec2<int>& pos, const std::vector<bool>& shape, int dimension) const
{
	for (int x = 0; x < dimension; ++x)
	{
		for (int y = 0; y < dimension; ++y)
		{
			if (shape[y * dimension + x])
			{
				if (pos.GetX() + x < 0)
				{
					return -(pos.GetX() + x);
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return 0;
}
//If the shape is outside of the right wall, returns the number of blocks necessarry to move the shape back into the board, otherwise returns 0
int Board::CollideRightWall(const Vec2<int>& pos, const std::vector<bool>& shape, int dimension) const
{
	for (int x = dimension - 1; x >= 0; --x)
	{
		for (int y = dimension - 1; y >= 0; --y)
		{
			if (shape[y * dimension + x])
			{
				if (pos.GetX() + x >= width)
				{
					return pos.GetX() + x - (width-1) ;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return 0;
}

//Checks if the tetromino is within the board AND if the blocks it's in are not taken.
bool Board::IsPositionValid(const Vec2<int>& pos, const std::vector<bool>& shape, int dimension) const
{
	if (IsWithinBoard(pos, shape, dimension))
	{
		//Check if the blocks are not taken
		for (int y = 0; y < dimension; ++y)
		{
			for (int x = 0; x < dimension; ++x)
			{
				if (shape[y * dimension + x])
				{
					//Find the block in board coordinates
					Vec2<int> boardPos{ pos.GetX() + x, pos.GetY() + y };
					Block boardBlock = content[boardPos.GetY() * width + boardPos.GetX()];
					//Check if it's empty
					if (boardBlock.bExists)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	return false;
}

//Moves the tetromino by a delta but only if the move is possible (returns true if moved, false otherwise)
bool Board::MoveTetromino(const Vec2<int> delta)
{
	Vec2<int> newPos = tetrominoPos + delta;
	if (IsPositionValid(newPos, activeTetromino->GetCurrentShape(), activeTetromino->GetDimension()))
	{
		tetrominoPos += delta;
		UpdatePrediction();
		return true;
	}
	return false;
}

int Board::ClearCompletedLines()
{
	int linesCleared = 0;
	for (int y = 0; y < height; ++y)
	{
		//Check if the line is completed
		auto iterator = content.begin() + (y * width);
		bool completed = std::all_of(iterator, iterator + width, [](const Block& block){
			return block.bExists;
			});

		if (completed)
		{
			//Shift down every line above this one
			for (int line = y - 1; line >= 0; --line)
			{
				for (int x = 0; x < width; ++x)
				{
					content[(line + 1) * width + x] = content[line * width + x];
				}
			}
			++linesCleared;
		}
	}
	return linesCleared;
}

void Board::DropTetromino()
{
	//Keep going down until hitting the bottom or a block
	while (MoveTetromino({ 0,1 }));
	PutTetromino();
}

//Finds out where the current shape is going to land if hard dropped and updates the prediction's position
void Board::UpdatePrediction()
{
	Vec2<int> tempPos{tetrominoPos};
	auto shape = activeTetromino->GetCurrentShape();
	int dimension = activeTetromino->GetDimension();
	//Keep going down until hitting the bottom or a block
	while (IsPositionValid({ tempPos.GetX(), tempPos.GetY() + 1 }, shape, dimension))
	{
		tempPos.SetY(tempPos.GetY() + 1);
	}
	//Update the prediction position
	predictionPos = tempPos;
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
	activeTetromino->Draw(screenPos + (tetrominoPos * blockSize), blockSize, blockPadding, false);
	//Draw the prediction
	activeTetromino->Draw(screenPos + (predictionPos * blockSize), blockSize, blockPadding, true);
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


