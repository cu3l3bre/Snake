//////////////////////////////////////////////////////////////////////////////////////////////
//																							//
//	Author:		DS																			//
//	Created:	2019.06.11																	//
//																							//
//////////////////////////////////////////////////////////////////////////////////////////////

// TODO calculate points and show highscore


#include <iostream>

#include <Windows.h>

#include "level.h"
#include "snake.h"
#include "time.h"

#include <ctime>


#include "conio.h" // TODO Remove maybe
using namespace std;



// TODO put this into a class method
// found on the net
// link
// https://www.quora.com/Is-there-a-way-to-skip-the-input-from-a-user-if-a-certain-time-is-exceeded-in-C++


char get_char(float time_limit)
{
	
	char res;

	time_t start = time(NULL); //start the clock
	while (!_kbhit()) {
		//compare the clock with current time, if it exceeds return -1;
		if ((time(NULL) - start) >= time_limit)
			return -1;
	}


	// TODO fast input remains
	//else return the value stored in keyboard buffer.


	res = _getch();
	_getch();

	
	time_t timeToSleep = time_limit- (time(NULL) - start);
	// TODO Set Sleep here, time difference depending on how long it took the user to press a button
	Sleep(timeToSleep*1000);

	return res;
}



int main()
{
	cout << "This is a Snake Game" << endl << endl;
	cout << "Press any key to begin" << endl;
	_getch();
	_getch();

	char userInput = char(0);

	// start RNG with actual time
	srand(time(0));

/*
	clock_t startTime = clock();

	clock_t testTime;
	
	clock_t timePassed;
	double secondsPassed = 0.0;
	*/

	











	// Creating new object of class Level
	Level lvl1;
	bool gameOver = false;

	//startTime = clock();

	lvl1.gameStartTime = time(0);

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

			// TODO maybe remove this 

			//cout << "Enter something in 3 sec :";
			//userInput = get_char(3); //passing time_limit = 1000 milliseconds

			//if (userInput == -1)
			//{
			//	cout << "Time limit exceeded. Try again later." << endl;
			//}
			//else
			//{
			//	cout << "Character is : " << userInput << endl;
			//}

			
			if (_kbhit()) {
				userInput = (char)_getch();
				_getch();
			}
			else {
				userInput = ' ';
			}



			// This works so far !!!!
			// for some reason _getchar() has two informations when a button is pressed
			// in order not to make a second move then
			// we call _getch() a second time to get rid of the second information
			// and so we only make one move
		
			
			//userInput = (char)_getch();
			//_getch();
			


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
			/*
			testTime = clock();
			timePassed = testTime - startTime;
			secondsPassed = timePassed / (double)CLOCKS_PER_SEC;
			*/
			
			
			
			lvl1.timeNow = time(0);
			lvl1.timeElapsed = lvl1.timeNow - lvl1.gameStartTime;


			localtime_s(&lvl1.nowLocal, &lvl1.timeNow);

			lvl1.year = lvl1.nowLocal.tm_year + 1900;
			lvl1.month = lvl1.nowLocal.tm_mon + 1;
			lvl1.day = lvl1.nowLocal.tm_mday;
			lvl1.hour = lvl1.nowLocal.tm_hour;
			lvl1.minute = lvl1.nowLocal.tm_min;
			lvl1.seconds = lvl1.nowLocal.tm_sec;

			lvl1.calculateScore();

			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!! GAME OVER !!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Your Run lastet " << lvl1.timeElapsed << " seconds! and ate " << lvl1.foodCount << " Food! Good Job :)" << endl;
			cout << "Your total score is: " << lvl1.score << " Keep up the good work!" << endl;
			cout << "Played on " << lvl1.day << "." << lvl1.month << "." << lvl1.year << " at " << lvl1.hour << ":" << lvl1.minute << ":" << lvl1.seconds << endl;
			

		}






	}


	system("pause");
	return 0;
}