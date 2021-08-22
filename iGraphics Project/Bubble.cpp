#include "Menu.h"
#include "Bubble.h"

#include <stdlib.h>
#include <time.h>

Bubble::Bubble()
{
	posY = -radius;
}

Bubble::Bubble(double posX, int radius, double speed, int state, int id)
{
	this->posX = posX;
	this->radius = radius;
	this->speed = speed;
	this->state = state;
	this->id = id;
}

Bubble::~Bubble()
{
}

void Bubble::bubbleUpdate()
{
	state = 0;
	posX = rand() % 1024;
	posY = -radius;
	id = rand() % 26;
	state = 1;
}
