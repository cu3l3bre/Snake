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



// GameOver is When Head of Snake is in its body or boundaries
bool Level::checkGameOver()
{
	bool gameOver = false;
	// Starts at 1 because Head is 0
	for (int i = 1; i < snake.snakePoints.size(); i++)
	{	
		// Check if snakes head is its body
		if ((snake.snakePoints[0].Row) ==  (snake.snakePoints[i].Row) &&
			(snake.snakePoints[0].Col) == (snake.snakePoints[i].Col))
		{
			gameOver = true;
		}
		// Check if snakes head is in boundaries
		else if((snake.snakePoints[0].Row == 0) || (snake.snakePoints[0].Row == rows-1) || 
			(snake.snakePoints[0].Col == 0) || (snake.snakePoints[0].Col == cols-1))
		{
			gameOver = true;
		}
	}

	if (gameOver == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}


