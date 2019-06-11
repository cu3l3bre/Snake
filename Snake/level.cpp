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
				levelPoints[i][j] = ' ';
			}

			// else if ((i == snake.location.Row) && (j == snake.location.Col))
			
			for (snakeIndex = 0; snakeIndex < snake.snakePoints.size(); snakeIndex++)
			{
				if ((i == snake.snakePoints[snakeIndex].Row) && (j == snake.snakePoints[snakeIndex].Col) &&
					(snakeIndex == 0))
				{
					levelPoints[i][j] = 'H';
					//snakeIndex++; // Need to check for limit?
				}

				else if ((i == snake.snakePoints[snakeIndex].Row) && (j == snake.snakePoints[snakeIndex].Col) &&
					(snakeIndex > 0))
				{
					levelPoints[i][j] = 'B';
					//snakeIndex++;
				}
			}



		}
	}
	
}

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
	cout << snake.snakePoints.size() << endl;
	cout << snake.snakePoints[0].Row << "  " << snake.snakePoints[0].Col << endl;
	cout << snake.snakePoints[1].Row << "  " << snake.snakePoints[1].Col << endl;
	


}


