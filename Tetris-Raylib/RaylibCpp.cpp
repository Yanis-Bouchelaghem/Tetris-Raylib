#include "RaylibCpp.h"

void rayCpp::DrawRectangle(Vec2<int> pos,Vec2<int> widthHeight, Color color)
{
	DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), color);
}

void rayCpp::DrawRectangleLinesEx(Rect<int> rect, int lineThick, Color color)
{
	DrawRectangleLinesEx(Rectangle{(float)rect.getX(), (float)rect.getY(), (float)rect.getWidth(), (float)rect.getheight()}, lineThick, color);
}
