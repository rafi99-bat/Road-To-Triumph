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

void update()
{
	iSetTimer(8000, speedup);
	iSetTimer(10, book0Move);
	iSetTimer(10, book1Move);
	iSetTimer(10, book2Move);
	iSetTimer(10, book3Move);
	iSetTimer(10, book4Move);
	iSetTimer(10, supplementaryMove);
}

int main()
{
	initDeclare();
	update();
	iInitialize(screenWidth, screenHeight, "Road to Triumph");
	setResizable(false);
	iStart();
	return 0;
}