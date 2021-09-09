#include "Menu.h"
#include "Book.h"

#include <stdlib.h>
#include <time.h>

Book::Book()
{
}

Book::Book(double posX, int radius, double speed, int state, int id)
{
	this->posX = posX;
	this->radius = radius;
	this->speed = speed;
	this->state = state;
	this->id = id;
	this->score = score;
	posY = -radius;
	score = 0;
}

Book::~Book()
{
}

void Book::bookUpdate()
{
	score++;
	state = 0;
	posX = rand() % 1024;
	posY = -radius;
	//id = rand() % 26;
	state = 1;
}
