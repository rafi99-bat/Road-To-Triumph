#pragma once

typedef struct Bubble Bubble;

struct Bubble
{
	double posX, posY;
	int radius;
	double speed;
	int state;
	int id;

	Bubble();
	Bubble(double posX, int radius, double speed, int state, int id);
	~Bubble();

	void bubbleUpdate();
};
