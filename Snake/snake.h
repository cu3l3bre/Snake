#pragma once

#include "point.h"

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

	void initSnake();
	void drawSnake();

	int snakeLength;
	Point initLocation;
	//vector<Point> snake;

	Point location;

	int direction; // 0 = oben, 1 = rechts; 2 = unten , 3 = links

};