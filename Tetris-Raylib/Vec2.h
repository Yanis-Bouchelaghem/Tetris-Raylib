#pragma once
template <typename T>
class Vec2
{
public:
	Vec2(T _x, T _y)
	:
	x(_x),
	y(_y)
	{}

	T GetX(){return x;}
	T GetY(){return y;}
	void SetX(T _x){x = _x;}
	void SetY(T _y){y = _y;}

public:
	bool operator==(const Vec2& rhs) const
	{
		return(x == rhs.x && y == rhs.y);
	}
	bool operator!=(const Vec2& rhs) const
	{
		return !(*this == rhs);
	}
	Vec2 operator+(const Vec2& rhs) const
	{
		return {x + rhs.x, y + rhs.y};
	}
	Vec2 operator+(const int rhs) const
	{
		return {x + rhs, y + rhs};
	}
	Vec2 operator-(const Vec2& rhs) const
	{
		return {x - rhs.x, y - rhs.y};
	}
	Vec2& operator+=(const Vec2& rhs)
	{
		return *this = *this + rhs;
	}
	Vec2& operator-=(const Vec2 rhs)
	{
		return *this = *this - rhs;
	}
private:
	T x;
	T y;
};


