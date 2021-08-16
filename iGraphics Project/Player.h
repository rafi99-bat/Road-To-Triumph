#pragma once

typedef struct Player Player;

struct Player
{
	double x, y;
	int size;

	Player();
	~Player();

	void move();
};
