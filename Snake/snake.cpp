
#include "snake.h"





Snake::Snake()
{
	/*initLocation.Row = rows / 2;
	initLocation.Col = cols / 2;*/
	snakeLength = 1;

	initLocation.Row = 5;
	initLocation.Col = 5;
	location.Row = initLocation.Row;
	location.Col = initLocation.Col;

	direction = SnakeUp; // rechts
}

Snake::~Snake()
{
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