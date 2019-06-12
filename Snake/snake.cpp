//////////////////////////////////////////////////////////////////////////////////////////////
//																							//
//	Author:		DS																			//
//	Created:	2019.06.11																	//
//																							//
//////////////////////////////////////////////////////////////////////////////////////////////

#include "snake.h"


// Std-Constructor

Snake::Snake()
{
	snakeLength = 6;

	initLocation.Row = 5;
	initLocation.Col = 5;
	location.Row = initLocation.Row;
	location.Col = initLocation.Col;

	// Generate the head and body for the snake in a vertical line
	for (int i = 0; i < snakeLength; i++)
	{
		snakePoints.push_back(location);
		location.Row++;
	}

	// StartDirection in which the snake will move at the beginning
	direction = SnakeUp; 
}


// Destructor
Snake::~Snake()
{
}


// Copy point values of the snake from top to bottom
// Index 0 will be the new field when the snake has moved
void Snake::updateSnake()
{
	for (int i = (snakePoints.size()-1); i > 0; i--)
	{
		snakePoints[i] = snakePoints[i-1];
	}
}

