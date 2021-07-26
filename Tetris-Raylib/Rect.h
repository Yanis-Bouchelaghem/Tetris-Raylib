#pragma once
#include "Vec2.h"
template<typename T>
class Rect
{
public:
	Rect(T _x, T _y, T _width, T _height)
		:
		x(_x),
		y(_y),
		width(_width),
		height(_height)
	{}
	Rect(Vec2<T> topleft, Vec2<T> width_height)
		:
		Rect(topleft.GetX(),topleft.GetY(), width_height.GetX(), width_height.GetY())
	{}
	T getX() {return x;}
	T getY() {return y;}
	T getWidth() {return width;}
	T getheight() {return height;}
private:
	T x;
	T y;
	T width;
	T height;
};
