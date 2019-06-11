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

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((i == 0) || (j == 0) || (i == (rows - 1)) || (j == (cols - 1)))
			{
				levelPoints[i][j] = BOUNDARY;
			}
			else if ((i == snake.location.Row) && (j == snake.location.Col))
			{
				levelPoints[i][j] = 'H';
			}
			else if (false) {

			}
			else {
				levelPoints[i][j] = ' ';
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

	


}


