#include <iostream>

#include <Windows.h>

#include "level.h"
#include "snake.h"

#include <ctime>


#include "conio.h" // TODO Remove maybe
using namespace std;


int main()
{
	cout << "This is a Snake Game" << endl << endl;

	char userInput = char(0);


	clock_t startTime = clock();

	clock_t testTime;
	
	clock_t timePassed;
	double secondsPassed;


	// Creating new object of class Level
	Level lvl1;


	// Game Over Condition
	while (1)
	{
		Sleep(300);
		lvl1.updateLevel();
		lvl1.drawLevel();




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
		userInput = _getch();
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


		// Copy Point Values from top to bottom in the vector
		// new value will be written at 0
		lvl1.snake.updateSnake();

		// write new point vlaue in 0
		switch (lvl1.snake.direction)
		{
		case SnakeUp: lvl1.snake.snakePoints[0].Row--; break;
		case SnakeRight: lvl1.snake.snakePoints[0].Col++; break;
		case SnakeDown: lvl1.snake.snakePoints[0].Row++; break;
		case SnakeLeft: lvl1.snake.snakePoints[0].Col--; break;
		default:break;
		}
	}





	system("pause");
	return 0;
}