#pragma once
#include <vector>
#include "RaylibCpp.h"
#include "Vec2.h"
#include <memory>

class Tetromino
{
public:
	void RotateRight();
	void RotateLeft();
	const std::vector<bool> GetRotatedLeft() const;
	const std::vector<bool> GetRotatedRight() const;
	bool ContainsBlock(Vec2<int> pos);
	Color GetColor() const;
	int GetDimension() const;
	const std::vector<bool>& GetCurrentShape() const;
	void Draw(const Vec2<int> screenPos, const int blockSize, const int blockPadding) const;
	static std::unique_ptr<Tetromino> RandomTetromino();

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
	Square();
	static constexpr int squareDimension = 2;
	static constexpr bool square[squareDimension*squareDimension] = { 1,1,
																	  1,1 };
	static constexpr Color color = YELLOW;
};

class Jay : public Tetromino
{
public:
	Jay();
	static constexpr int jayDimension = 3;
	static constexpr bool jay[jayDimension*jayDimension] = { 1,0,0,
															 1,1,1,
															 0,0,0 };
	static constexpr Color color = BLUE;
};

class Elle : public Tetromino
{
public:
	Elle();
	static constexpr int elleDimension = 3;
	static constexpr bool elle[elleDimension*elleDimension] = { 0,0,1,
															    1,1,1,
															    0,0,0 };
	static constexpr Color color = ORANGE;
};

class Ess : public Tetromino
{
public:
	Ess();
	static constexpr int essDimension = 3;
	static constexpr bool ess[essDimension*essDimension] = { 0,1,1,
															 1,1,0,
															 0,0,0 };
	static constexpr Color color = GREEN;
};

class Zed : public Tetromino
{
public:
	Zed();
	static constexpr int zedDimension = 3;
	static constexpr bool zed[zedDimension*zedDimension] = { 1,1,0,
															 0,1,1,
															 0,0,0 };
	static constexpr Color color = RED;
};

class Tee : public Tetromino
{
public:
	Tee();
	static constexpr int teeDimension = 3;
	static constexpr bool tee[teeDimension*teeDimension] = { 0,1,0,
															 1,1,1,
															 0,0,0 };
	static constexpr Color color = PURPLE;
};

class Straight : public Tetromino
{
public:
	Straight();
	static constexpr int straightDimension = 4;
	static constexpr bool straight[straightDimension*straightDimension] = { 0,0,0,0,
																			1,1,1,1,
																			0,0,0,0,
																			0,0,0,0 };
	static constexpr Color color = SKYBLUE;
};