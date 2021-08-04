#pragma once
#pragma warning(push, 0) 
#include <raylib.h>
#pragma warning(pop)
#include "Vec2.h"
#include "Rect.h"

//This is a wrapper for the raylib library to make it compatible with the useful complex types we make that are not available in C.
namespace rayCpp 
{
	void DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color);
	void DrawRectangleLinesEx(Rect<int> rect, int lineThick, Color color);
	void DrawText(const char* text, Vec2<int> pos, int fontSize, Color color);
	void DrawTextEx(Font font, const char* text, Vec2<int> pos, float fontSize, float spacing, Color tint);
}


