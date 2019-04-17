#ifndef SNAKE_H_
#define SNAKE_H_
#include "wall.h"
#include "food.h"
#include <iostream>

using namespace std;

class Snake {

public:
	Snake(Wall & tempWall, Food & tempFood);
	void initSnake();
	void destroySnake();
	void addPoint(int x, int y);
	void delPoint();
	bool move(char c);

private:
	struct Point {
		int x;
		int y;

		Point *next;
	};

	enum {
		UP='w',
		DOWN='s',
		RIGHT='d',
		LEFT='a'
	};

	Point *pHead;

	Wall &wall;

	Food &food;
};





#endif // !SNAKE_H_



