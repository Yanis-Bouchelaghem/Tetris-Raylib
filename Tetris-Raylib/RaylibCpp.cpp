#include "RaylibCpp.h"

void DrawRectangle(Vec2<int> pos, int width, int height, Color color)
{
	DrawRectangle(pos.GetX(), pos.GetY(), width, height, color);
}
