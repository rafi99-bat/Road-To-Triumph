#include "Menu.h"
#include "Book.h"

#include <stdlib.h>
#include <time.h>
#include <Windows.h>

Book::Book()
{
}

Book::Book(double posX, double speed, int index)
{
	this->posX = posX;
	posY = -size - rand() % 300;
	size = 85;
	this->speed = speed;
	this->index = index;
	state = true;
	score = 0;
	count = 101;
	GPA = 0.00;
}

Book::~Book()
{
}

void Book::bookUpdate()
{
	PlaySound(TEXT("res/audio/book-collect.wav"), NULL, SND_ASYNC);
	if (score <= 100)
		score++;
	if (count != 0)
		count--;
	state = false;
	posY = -size - rand() % 100;
	state = true;
}

void Book::GPAcount()
{
	if (score >= 80)
		GPA = 4.00;
	else if (score < 80 && score >= 75)
		GPA = 3.75;
	else if (score < 75 && score >= 70)
		GPA = 3.50;
	else if (score < 70 && score >= 65)
		GPA = 3.25;
	else if (score < 65 && score >= 60)
		GPA = 3.00;
	else if (score < 60 && score >= 55)
		GPA = 2.75;
	else if (score < 55 && score >= 50)
		GPA = 2.50;
	else if (score < 50 && score >= 45)
		GPA = 2.25;
	else if (score < 45 && score >= 40)
		GPA = 2.00;
	else
		GPA = 0.00;
}
