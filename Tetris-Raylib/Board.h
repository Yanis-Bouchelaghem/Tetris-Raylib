#pragma once  
#include <vector>
#include "RaylibCpp.h"
#include "Vec2.h"

//Represents the game board
class Board
{
public:
	Board(int width, int height);
	void putBlock(int x, int y, Color c);
	void RemoveBlock(int x, int y);
	void Draw(int posX, int posY) const;
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
private:
	std::vector<Block> content;
	int width;
	int height;
	static constexpr int blockSize = 25;
	static constexpr int blockPadding = 2;
	
};