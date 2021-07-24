#pragma once
//#pragma warning(push, 0)      
#include <raylib.h>
//#pragma warning(pop)
#include <vector>

//Represents the game board
class Board
{
public:
	Board(int width, int height);
	void putBlock(int x, int y, Color c);
	void removeBlock(int x, int y);
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
	
};