#include "pch.h"
#include "snake.h"
#include <iostream>
using namespace std;

Snake::Snake(Wall &tempWall, Food &tempFood):wall(tempWall),food(tempFood) {
	pHead = nullptr;
}

void Snake::initSnake() {
	destroySnake();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
	addPoint(5, 6);
	addPoint(5, 7);

}

void Snake::destroySnake() {
	Point *pCur = pHead;
	while (pHead!=nullptr) {
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y) {
	Point *newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = nullptr;

	if (pHead != nullptr) {
		wall.setWall(pHead->x, pHead->y, '=');
	}
	newPoint->next = pHead;
	pHead = newPoint;
	wall.setWall(pHead->x, pHead->y, '@');
}

void Snake::delPoint() {
	if (pHead == nullptr || pHead->next == nullptr)
		return;
	Point *pCur = pHead->next;
	Point *pPre=pHead;
	while (pCur->next != nullptr) {
		pPre = pPre->next;
		pCur = pCur->next;
	}
	wall.setWall(pCur->x, pCur->y, ' ');
	delete pCur;
	pCur = nullptr;
	pPre->next = nullptr;
}


bool Snake::move(char c) {
	int x = pHead->x;
	int y = pHead->y;
	switch(c) {
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}

	if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
		cout << "GAME OVER!!" << endl;
		return false;
	}

	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		food.setFood();
	}
	else {
		addPoint(x, y);
		delPoint();
	}
	return true;
}