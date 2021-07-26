#include "RaylibCpp.h"

void rayCpp::DrawRectangle(Vec2<int> pos, int width, int height, Color color)
{
	DrawRectangle(pos.GetX(), pos.GetY(), width, height, color);
}

void rayCpp::DrawRectangleLinesEx(Rect<int> rect, int lineThick, Color color)
{
	DrawRectangleLinesEx(Rectangle{(float)rect.getX(), (float)rect.getY(), (float)rect.getWidth(), (float)rect.getheight()}, lineThick, color);
}
