#include <iostream>

#include <Windows.h>

#include "level.h"
#include "snake.h"

#include "conio.h" // TODO Remove maybe
using namespace std;


int main()
{
	cout << "This is a Snake Game" << endl << endl;

	char userInput = char(0);

	Level lvl1;
	//Snake snake1;

	//snake1.drawBoundaries();
	//snake1.updateLevel();

	//snake1.initSnake();

	while (1)
	{
		Sleep(300);
		lvl1.updateLevel();
		lvl1.drawLevel();
		//snake1.drawSnake();
		//snake1.updateLevel();


		// TODO Timer laufen lassen in dem reagiert werden kann
		cin >> userInput;
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


		//switch (lvl1.snake.direction)
		//{
		//	case SnakeUp: lvl1.snake.location.Row--; break;
		//	case SnakeRight: lvl1.snake.location.Col++; break;
		//	case SnakeDown: lvl1.snake.location.Row++; break;
		//	case SnakeLeft: lvl1.snake.location.Col--; break;
		//	default:break;
		//}


		lvl1.snake.updateSnake();

		switch (lvl1.snake.direction)
		{
		case SnakeUp: lvl1.snake.snakePoints[0].Row--; break;
		case SnakeRight: lvl1.snake.snakePoints[0].Col++; break;
		case SnakeDown: lvl1.snake.snakePoints[0].Row++; break;
		case SnakeLeft: lvl1.snake.snakePoints[0].Col--; break;
		default:break;
		}







		//lvl1.snake.location.Col++;
		if (lvl1.snake.snakePoints[0].Col > 8) {
			lvl1.snake.snakePoints[0].Col = 1;
		}

	}





	system("pause");
	return 0;
}

/*

Klasse Level/Map

hat atrribute x und y als korrdinaten

methoden

createBoundaries

drawBoundaries // Zeichnen die Umrandung der Karte basierend auf der LevelGrösse


Klasse Snake



Class Flood
*/
