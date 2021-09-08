#ifndef BUBBLE_H
#define BUBBLE_H

#define MAX_SCORE 100

typedef struct Book Book;

struct Book
{
	double posX, posY;
	int size;
	double speed;
	int index;
	int score;
	int count;
	bool state;
	double GPA;

	Book();
	Book(double posX, double speed, int index);
	~Book();

	void bookUpdate();
	void GPAcount();
};
#endif