#pragma once  
#include <vector>
#include "RaylibCpp.h"
#include "Vec2.h"
#include "Tetromino.h"
#include <memory>

//Represents the game board
class Board
{
private:
	//Represents the state of a block inside of the board
	class Block
	{
	public:
		void putColor(Color c);
	public:
		Color color = BLACK;
		bool bExists = false;
	};
public:
	Board(int width, int height);
	void putBlock(int x, int y, Color c);
	void RemoveBlock(int x, int y);
	void RotateTetrominoLeft();
	void RotateTetrominoRight();
	bool IsBlockAvailable(const Vec2<int>& pos) const;
	bool IsWithinBoard(const Vec2<int>& pos, const std::vector<bool>& shape, int dimension) const;
	int CollideLeftWall(const Vec2<int>& pos, const std::vector<bool>& shape, int dimension) const;
	int CollideRightWall(const Vec2<int>& pos, const std::vector<bool>& shape, int dimension) const;
	bool IsPositionValid(const Vec2<int>& pos, const std::vector<bool>& shape, int dimension) const;
	void MoveTetromino(const Vec2<int> delta);
	void Draw(Vec2<int> pos) const;
	void Draw(int posX, int posY) const;


private:
	std::vector<Block> content;
	std::unique_ptr<Tetromino> activeTetromino;
	const int width;
	const int height;
	Vec2<int> tetrominoPos;

	static constexpr int blockSize = 25;
	static constexpr int blockPadding = 2;
	static constexpr Color borderColor = WHITE;
	
};