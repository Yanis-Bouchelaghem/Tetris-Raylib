#pragma once
#include <vector>
#include "RaylibCpp.h"
#include "Vec2.h"

class Tetromino
{
public:
	void RotateRight();
	void RotateLeft();
	int GetDimension() const;
	const std::vector<bool>& GetCurrentShape() const;
	void Draw(const Vec2<int> screenPos, const int blockSize, const int blockPadding) const;
	virtual ~Tetromino() noexcept = default;
protected:
	Tetromino(int dimension, Color color, const bool* _shape);
	std::vector<bool> shape;
private:
	const int dimension;
	Color color;
};

class Square : public Tetromino
{
public:
	Square(Color color);
	static constexpr int squareDimension = 2;
	static constexpr bool square[squareDimension*squareDimension] = { 1,1,
																	  1,1 };
};

class Jay : public Tetromino
{
public:
	Jay(Color color);
	static constexpr int jayDimension = 3;
	static constexpr bool jay[jayDimension*jayDimension] = { 1,0,0,
															 1,1,1,
															 0,0,0 };
};

class Elle : public Tetromino
{
public:
	Elle(Color color);
	static constexpr int elleDimension = 3;
	static constexpr bool elle[elleDimension*elleDimension] = { 0,0,1,
															    1,1,1,
															    0,0,0 };
};

class Ess : public Tetromino
{
public:
	Ess(Color color);
	static constexpr int essDimension = 3;
	static constexpr bool ess[essDimension*essDimension] = { 0,1,1,
															 1,1,0,
															 0,0,0 };
};

class Zed : public Tetromino
{
public:
	Zed(Color color);
	static constexpr int zedDimension = 3;
	static constexpr bool zed[zedDimension*zedDimension] = { 1,1,0,
															 0,1,1,
															 0,0,0 };
};

class Tee : public Tetromino
{
public:
	Tee(Color color);
	static constexpr int teeDimension = 3;
	static constexpr bool tee[teeDimension*teeDimension] = { 0,1,0,
															 1,1,1,
															 0,0,0 };
};

class Straight : public Tetromino
{
public:
	Straight(Color color);
	static constexpr int straightDimension = 4;
	static constexpr bool straight[straightDimension*straightDimension] = { 0,0,0,0,
																			1,1,1,1,
																			0,0,0,0,
																			0,0,0,0 };
};