
#include "snake.h"





Snake::Snake()
{
	/*initLocation.Row = rows / 2;
	initLocation.Col = cols / 2;*/
	snakeLength = 3;

	initLocation.Row = 5;
	initLocation.Col = 5;
	location.Row = initLocation.Row;
	location.Col = initLocation.Col;

	for (int i = 0; i < snakeLength; i++)
	{
		snakePoints.push_back(location);
		location.Row++;
	}

	direction = SnakeUp; 
}

Snake::~Snake()
{
}

void Snake::updateSnake()
{
	for (int i = (snakePoints.size()-1); i > 0; i--)
	{
		//snakePoints[1] = snakePoints[0];
		snakePoints[i] = snakePoints[i-1];
	}
}


void Snake::initSnake()
{
	//for (int i = 0; i < snakeLength; i++)
	//{
	//	snake.push_back(initLocation);
	//	initLocation.Row++;
	//}
}

void Snake::drawSnake()
{
/*
	for (int s = 0; s < snakeLength; s++)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if ((i == snake[s].Row) && (j == snake[s].Col))
				{
					if (s == 0)
					{
						levelPoints[i][j] = 'H';
					}
					else
					{
						levelPoints[i][j] = 'B';
					}
				}
			}
		}
	}*/
}

