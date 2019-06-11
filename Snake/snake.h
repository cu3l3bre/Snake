#pragma once

#include "point.h"
#include "vector"

enum SnakeDirection
{
	SnakeUp,
	SnakeRight,
	SnakeDown,
	SnakeLeft
};


class Snake
{
private:




public:
	Snake();
	~Snake();

	void updateSnake();
	void initSnake();
	void drawSnake();

	int snakeLength;
	Point initLocation;

	Point location;
	std::vector<Point> snakePoints;

	int direction; // 0 = up, 1 = right; 2 = down , 3 = left

};