#pragma once
#pragma warning(push, 0) 
#include <raylib.h>
#pragma warning(pop)
#include "Vec2.h"
#include "Rect.h"

//This is a wrapper for the raylib library to make it compatible with the useful complex types we make that are not available in C.
namespace rayCpp 
{
	void DrawRectangle(Vec2<int> pos, int width, int height, Color color);
	void DrawRectangleLinesEx(Rect<int> rect, int lineThick, Color color);
}


