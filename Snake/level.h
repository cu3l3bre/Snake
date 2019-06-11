#pragma once

#include "point.h"
#include <vector>
#include "snake.h"


#define EMPTYFIELD char(0);
#define BOUNDARY 'X';
#define SNAKEHEAD 'H';
#define SNAKEBODY 'B';

using namespace std;

class Level
{
protected:

	

public:

	Level();
	Level(int, int);
	~Level();

	int rows = 10;
	int cols = 10;
	int points;
	//vector<int> levelPoints;
	char levelPoints[10][10];
	Snake snake;

	// Getter

	// Setter


	// Methods

	void drawBoundaries();
	void updateLevel();

	void drawLevel();



};