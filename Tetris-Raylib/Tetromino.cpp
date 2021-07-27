#include "Tetromino.h"

Tetromino::Tetromino(int _dimension, Color color)
	:
	color(color)
{
	shape.resize(_dimension*2);
}