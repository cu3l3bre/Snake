//////////////////////////////////////////////////////////////////////////////////////////////
//																							//
//	Author:		DS																			//
//	Created:	2019.06.11																	//
//																							//
//////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include <Windows.h>

#include "level.h"
#include "snake.h"
#include "time.h"

#include <ctime>


#include "conio.h" // TODO Remove maybe
using namespace std;


int main()
{
	cout << "This is a Snake Game" << endl << endl;

	char userInput = char(0);

	// Zufallsgenerator starten mit der aktuellen Uhrzeit als Startwert
	srand(time(0));



	clock_t startTime = clock();

	clock_t testTime;
	
	clock_t timePassed;
	double secondsPassed;


	// Creating new object of class Level
	Level lvl1;
	bool gameOver = false;

	// Game Over Condition
	while (!gameOver)
	{
		Sleep(300);

		if (!lvl1.foodOnField)
		{
			lvl1.generateFood();
			lvl1.foodOnField = true;
		}

		lvl1.updateLevel();
		lvl1.drawLevel();
		

		gameOver = lvl1.checkGameOver();




		if (!gameOver)
		{

			testTime = clock();
			timePassed = testTime - startTime;
			secondsPassed = timePassed / (double)CLOCKS_PER_SEC;


			if (secondsPassed > 2.0)
			{
				startTime = clock();
			}

			cout << "Actual time " << secondsPassed << endl;


			/*
			while (secondsPassed < 1.5)
			{
				userInput = _getch();
			}
			*/
			//userInput = _getch();
			userInput = cin.get();
			cin.ignore();
			// TODO Timer laufen lassen in dem reagiert werden kann
			//cin >> userInput;
			//userInput = _getch();
			//while (_getch() != '\n');





			// Cycle through directions depending on user input and actual direction
			switch (userInput)
			{
			case 'a': lvl1.snake.direction -= 1; break;
			case 'd': lvl1.snake.direction += 1; break;
			default: lvl1.snake.direction = lvl1.snake.direction; break;
			}

			// Check for Overflow
			if (lvl1.snake.direction == -1)
			{
				lvl1.snake.direction = 3;
			}
			else if (lvl1.snake.direction == 4)
			{
				lvl1.snake.direction = 0;
			}

			// Check if snake has found some food and let it grow
			if ((lvl1.foodLocation.row == lvl1.snake.snakePoints[0].row) && (lvl1.foodLocation.col == lvl1.snake.snakePoints[0].col))
			{
				lvl1.eatFood();
			}


			// Copy Point Values from top to bottom in the vector
			// new value will be written at 0
			lvl1.snake.updateSnake();

			// write new point vlaue in 0
			switch (lvl1.snake.direction)
			{
			case SnakeUp: lvl1.snake.snakePoints[0].row--; break;
			case SnakeRight: lvl1.snake.snakePoints[0].col++; break;
			case SnakeDown: lvl1.snake.snakePoints[0].row++; break;
			case SnakeLeft: lvl1.snake.snakePoints[0].col--; break;
			default:break;
			}
		}
		else
		{
			cout << "GAME OVER!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
	}





	system("pause");
	return 0;
}