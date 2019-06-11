//////////////////////////////////////////////////////////////////////////////////////////////
//																							//
//	Author:		DS																			//
//	Created:	2019.06.11																	//
//																							//
//////////////////////////////////////////////////////////////////////////////////////////////


#include "level.h"
#include <iostream>

using namespace std;


// Std - Constructor
Level::Level()
{
	points = rows * cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			levelPoints[i][j] = char(0);
		}
	}	
}

// Allg. Constructor
Level::Level(int nRows, int nCols)
{
	rows = nRows;
	cols = nCols;
}

// Destructor
Level::~Level()
{}


// Methods

void Level::drawBoundaries()
{
	for (int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if ((i == 0) || (j == 0) || (i == (rows - 1)) || (j == (cols - 1)))
			{
				levelPoints[i][j] = BOUNDARY;
			}
			else
			{
				levelPoints[i][j] = EMPTYFIELD;
			}
		}
	}
}


// Method for update all items in the game
// Boundieres, Snake, Food etc.
void Level::updateLevel()
{
	int snakeIndex = 0;


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((i == 0) || (j == 0) || (i == (rows - 1)) || (j == (cols - 1)))
			{
				levelPoints[i][j] = BOUNDARY;
			}
			else if (false)
			{

			}
			else {
				levelPoints[i][j] = EMPTYFIELD;
			}

			// else if ((i == snake.location.Row) && (j == snake.location.Col))
			
			for (snakeIndex = 0; snakeIndex < snake.snakePoints.size(); snakeIndex++)
			{
				if ((i == snake.snakePoints[snakeIndex].Row) && (j == snake.snakePoints[snakeIndex].Col) &&
					(snakeIndex == 0))
				{
					levelPoints[i][j] = SNAKEHEAD;
				}

				else if ((i == snake.snakePoints[snakeIndex].Row) && (j == snake.snakePoints[snakeIndex].Col) &&
					(snakeIndex > 0))
				{
					levelPoints[i][j] = SNAKEBODY;
				}
			}
		}
	}
}


// Mehtod for drawing all items in the console
void Level::drawLevel()
{
	system("cls");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << levelPoints[i][j];
		}
		cout << endl;
	}
}


