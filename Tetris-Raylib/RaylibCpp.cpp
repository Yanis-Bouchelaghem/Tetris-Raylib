#include "RaylibCpp.h"
#include <assert.h>
void rayCpp::DrawRectangle(Vec2<int> pos,Vec2<int> widthHeight, Color color)
{
	assert(pos.GetX() >= 0 && pos.GetX() < GetScreenWidth());//If assertion fails: trying to draw outside of the screen
	assert(pos.GetY() >= 0 && pos.GetY() < GetScreenHeight());
	DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), color);
}

void rayCpp::DrawRectangleLinesEx(Rect<int> rect, int lineThick, Color color)
{
	assert(rect.getX() >= 0 && rect.getX() + rect.getWidth() < GetScreenWidth());//If assertion fails: trying to draw outside of the screen
	assert(rect.getY() >= 0 && rect.getY() + rect.getheight() < GetScreenHeight());
	DrawRectangleLinesEx(Rectangle{(float)rect.getX(), (float)rect.getY(), (float)rect.getWidth(), (float)rect.getheight()}, lineThick, color);
}
