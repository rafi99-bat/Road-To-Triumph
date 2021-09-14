#ifndef BOOK_H
#define BOOK_H

#define MAX_SCORE 100

typedef struct Book Book;

struct Book
{
	double posX, posY;
	int radius;
	double speed;
	int state;
	int id;
	int score;

	Book();
	Book(double posX, int radius, double speed, int state, int id);
	~Book();

	void bookUpdate();
};
#endif