#include "iGraphics.h"
#include "Book.h"
#include "Menu.h"
#include "Input.h"

#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#include <time.h>

int screenWidth = 1024;
int screenHeight = 600;
double screenPosX = 0;
double screenPosY = 0;
int mousePosX, mousePosY;
int mouseMode = NON_CLICKABLE;
bool typeMode = false;
int max = 0;

Book book[5];
Book supplementary;

int score = 0;
bool specialState = false;
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
				   'u', 'v', 'w', 'x', 'y', 'z',',', ';', '=', '!', '&', '*', '#', '%', '(', ')', '{', '}', '-'};
char playerName[30];
char str[30];
char str2[30];
char buffer[2];
int len = 0;
int menu = INTRO;
int charLength = sizeof(alphabet)/sizeof(char);

int main()
{
	book[0] = Book(313, 1, rand() % (charLength / 5));
	book[1] = Book(455, 1, (charLength / 5) + rand() % (charLength / 5));
	book[2] = Book(597, 1, 2 * (charLength / 5) + rand() % (charLength / 5));
	book[3] = Book(739, 1, 3 * (charLength / 5) + rand() % (charLength / 5));
	book[4] = Book(881, 1, 4 * (charLength / 5) + rand() % (charLength / 5));
	supplementary.posX = 171 + rand() % 853;
	supplementary.posY = -300;
	supplementary.speed = 2;
	supplementary.index = rand() % charLength;
	supplementary.count = 40;
	supplementary.score = 5;

	iSetTimer(8000, speedup);
	iSetTimer(10, book0Move);
	iSetTimer(10, book1Move);
	iSetTimer(10, book2Move);
	iSetTimer(10, book3Move);
	iSetTimer(10, book4Move);
	iSetTimer(10, supplementaryMove);

	iInitialize(screenWidth, screenHeight, "Road to Triumph");
	setResizable(false);
	iStart();
	return 0;
}