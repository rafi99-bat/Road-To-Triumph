#include "Bubble.h"
#include "Menu.h"
#include "iGraphics.h"
#include "Game.h"

#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int screenWidth = 1024;
int screenHeight = 600;
double screenPosX = 0;
double screenPosY = 0;
int mousePosX, mousePosY;
int mouseMode = NON_CLICKABLE;

int sec = 150;
int score = 0;
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q','r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char str[30];
char buffer[2];
int menu = GAME;
int charLength = sizeof(alphabet)/sizeof(char);

Bubble bubble1 = Bubble(rand()%screenWidth, 30, 0.5, 1, rand() % charLength);
Bubble bubble2 = Bubble(rand()%screenWidth, 30, 2, 1, rand() % charLength);
Bubble bubble3 = Bubble(rand()%screenWidth, 30, 1, 1, rand() % charLength);
Bubble bubble4 = Bubble(rand()%screenWidth, 30, 1.5, 1, rand() % charLength);
Bubble bubble5 = Bubble(rand()%screenWidth, 30, 2.5, 1, rand() % charLength);

void initDeclare()
{
	bubble1 = Bubble(rand()%screenWidth, 30, 0.5, 1, rand() % charLength);
	bubble2 = Bubble(rand()%screenWidth, 30, 2, 1, rand() % charLength);
	bubble3 = Bubble(rand()%screenWidth, 30, 1, 1, rand() % charLength);
	bubble4 = Bubble(rand()%screenWidth, 30, 1.5, 1, rand() % charLength);
	bubble5 = Bubble(rand()%screenWidth, 30, 2.5, 1, rand() % charLength);
	bubble1.posY = -bubble1.radius;
	bubble2.posY = -bubble2.radius;
	bubble3.posY = -bubble3.radius;
	bubble4.posY = -bubble4.radius;
	bubble5.posY = -bubble5.radius;
	sec = 150;
	score = 0;
	menu = GAME;
}

void timer()
{
	if (menu == GAME)
	{
		if(!sec) return;
		sec--;
	}
}

void scoring()
{
	iSetColor(255,255,255);
	iText(30, 556, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str,"%d",score);
	iText(130,556,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(900, 556, "Time: ", GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str,"%d",sec);
	iText(960,556,str,GLUT_BITMAP_TIMES_ROMAN_24);
}

void bubble1Move()
{
	if (menu == GAME)
	{
		if (sec == 0)
		{
			menu = GAME_OVER;
		}
	}
	if (menu == GAME)
	{
		if (bubble1.state == 1)
		{
			if (bubble1.posY > screenHeight)
			{
				bubble1.posX = rand() % screenWidth;
				bubble1.posY = -bubble1.radius;
				bubble1.id = rand() % charLength;
			}
			else if (bubble1.posY <= screenHeight)
			{
				bubble1.posY += bubble1.speed;
			}
		}
	}
}

void bubble2Move()
{
	if (menu == GAME)
	{
		if (sec == 0)
		{
			menu = GAME_OVER;
		}
	}
	if (menu == GAME)
	{
		if (bubble2.state == 1)
		{
			if (bubble2.posY > screenHeight)
			{
				bubble2.posX = rand() % screenWidth;
				bubble2.posY = -bubble2.radius;
				bubble2.id = rand() % charLength;
			}
			else if (bubble2.posY <= screenHeight)
			{
				bubble2.posY += bubble2.speed;
			}
		}
	}
}

void bubble3Move()
{
	if (menu == GAME)
	{
		if (sec == 0)
		{
			menu = GAME_OVER;
		}
	}
	if (menu == GAME)
	{
		if (bubble3.state == 1)
		{
			if (bubble3.posY > screenHeight)
			{
				bubble3.posX = rand() % screenWidth;
				bubble3.posY = -bubble3.radius;
				bubble3.id = rand() % charLength;
			}
			else if (bubble3.posY <= screenHeight)
			{
				bubble3.posY += bubble3.speed;
			}
		}
	}
}

void bubble4Move()
{
	if (menu == GAME)
	{
		if (sec == 0)
		{
			menu = GAME_OVER;
		}
	}
	if (menu == GAME)
	{
		if (bubble4.state == 1)
		{
			if (bubble4.posY > screenHeight)
			{
				bubble4.posX = rand() % screenWidth;
				bubble4.posY = -bubble4.radius;
				bubble4.id = rand() % charLength;
			}
			else if (bubble4.posY <= screenHeight)
			{
				bubble4.posY += bubble4.speed;
			}
		}
	}
}

void bubble5Move()
{
	if (menu == GAME)
	{
		if (sec == 0)
		{
			menu = GAME_OVER;
		}
	}
	if (menu == GAME)
	{
		if (bubble5.state == 1)
		{
			if (bubble5.posY > screenHeight)
			{
				bubble5.posX = rand() % screenWidth;
				bubble5.posY = -bubble5.radius;
				bubble5.id = rand() % charLength;
			}
			else if (bubble5.posY <= screenHeight)
			{
				bubble5.posY += bubble5.speed;
			}
		}
	}
}

/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	if (menu == MAIN_MENU)
	{
		iSetColor(135, 206, 235);
		iFilledRectangle(screenPosX, screenPosY, screenWidth, screenHeight);
	}
	if (menu == GAME)
	{
		iSetColor(135, 206, 235);
		iFilledRectangle(screenPosX, screenPosY, screenWidth, screenHeight);
		if (bubble1.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(bubble1.posX, bubble1.posY, bubble1.radius, 1000);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[bubble1.id]);
			iText(bubble1.posX - 5, bubble1.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		if (bubble2.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(bubble2.posX, bubble2.posY, bubble2.radius, 1000);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[bubble2.id]);
			iText(bubble2.posX - 5, bubble2.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		if (bubble3.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(bubble3.posX, bubble3.posY, bubble3.radius, 1000);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[bubble3.id]);
			iText(bubble3.posX - 5, bubble3.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		if (bubble4.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(bubble4.posX, bubble4.posY, bubble4.radius, 1000);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[bubble4.id]);
			iText(bubble4.posX - 5, bubble4.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		if (bubble5.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(bubble5.posX, bubble5.posY, bubble5.radius, 1000);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[bubble5.id]);
			iText(bubble5.posX - 5, bubble5.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		iSetColor(51, 51, 255);
		iFilledRectangle(screenPosX, screenPosY + 530, screenWidth, 70);
		scoring();
	}
	if (menu == PAUSE_MENU)
	{
		iShowBMP(screenPosX, screenPosY, "PauseMenu(255).bmp");
		if (mouseMode == CLICKABLE)
		{
			if ((mousePosX >= 448 && mousePosX <= 585) && (mousePosY >= 420 && mousePosY <= 464)) iLine(471, 430, 562, 430);
			else if ((mousePosX >= 448 && mousePosX <= 585) && (mousePosY >= 363 && mousePosY <= 408)) iLine(476, 374, 556, 374);
			else if ((mousePosX >= 448 && mousePosX <= 585) && (mousePosY >= 304 && mousePosY <= 351)) iLine(488, 318, 543, 318);
			else if ((mousePosX >= 448 && mousePosX <= 585) && (mousePosY >= 247 && mousePosY <= 292)) iLine(489, 259, 542, 259);
			else if ((mousePosX >= 448 && mousePosX <= 585) && (mousePosY >= 190 && mousePosY <= 236)) iLine(457, 201, 579, 201);
			else if ((mousePosX >= 448 && mousePosX <= 585) && (mousePosY >= 132 && mousePosY <= 177)) iLine(497, 144, 537, 144);
		}
	}
	if (menu == CREDITS)
	{
		iShowBMP(screenPosX, screenPosY, "Credit.bmp");
		if (mouseMode == CLICKABLE)
		{
			if ((mousePosX >= 136 && mousePosX <= 348) && (mousePosY >= 136 && mousePosY <= 151)) iLine(138, 134, 348, 134);
			else if ((mousePosX >= 420 && mousePosX <= 602) && (mousePosY >= 136 && mousePosY <= 152)) iLine(422, 134, 602, 134);
			else if ((mousePosX >= 701 && mousePosX <= 832) && (mousePosY >= 136 && mousePosY <= 153)) iLine(702, 136, 834, 136);
		}
	}
	iShowBMP2(mousePosX, mousePosY - 31, "cursor(0).bmp", 0);
	glutSetCursor(GLUT_CURSOR_NONE);
}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
function iPassiveMouse() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	if ((mx >= screenPosX && mx + 17 <= screenWidth) && (my - 31 >= screenPosY && my <= screenHeight))
	{
		mousePosX = mx;
		mousePosY = my;
	}
	if (menu == PAUSE_MENU)
	{
		if (((mx >= 448 && mx <= 585) && (my >= 420 && my <= 464)) || 
		    ((mx >= 448 && mx <= 585) && (my >= 363 && my <= 408)) ||
			((mx >= 448 && mx <= 585) && (my >= 304 && my <= 351)) || 
			((mx >= 448 && mx <= 585) && (my >= 247 && my <= 292)) || 
			((mx >= 448 && mx <= 585) && (my >= 190 && my <= 236)) || 
			((mx >= 448 && mx <= 585) && (my >= 132 && my <= 177))) mouseMode = CLICKABLE;
		else mouseMode = NON_CLICKABLE;
	}
	if (menu == CREDITS)
	{
		if (((mx >= 136 && mx <= 348) && (my >= 136 && my <= 151)) || 
			((mx >= 420 && mx <= 602) && (my >= 136 && my <= 152)) || 
			((mx >= 701 && mx <= 832) && (my >= 136 && my <= 153))) mouseMode = CLICKABLE;
		else mouseMode = NON_CLICKABLE;
	}
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//printf("%d %d\n", mx, my);
		if (menu == MAIN_MENU)
		{
			initDeclare();
			menu == GAME;
		}
		if (menu == PAUSE_MENU)
		{
			if (((mx >= 448 && mx <= 585) && (my >= 420 && my <= 464)))
			{
				menu = GAME;
				iResumeTimer(0);
				iResumeTimer(1);
				iResumeTimer(2);
				iResumeTimer(3);
				iResumeTimer(4);
				iResumeTimer(5);
			}
			else if ((mx >= 448 && mx <= 585) && (my >= 363 && my <= 408))
			{
				initDeclare();
				iResumeTimer(0);
				iResumeTimer(1);
				iResumeTimer(2);
				iResumeTimer(3);
				iResumeTimer(4);
				iResumeTimer(5);
				iResumeTimer(6);
			}
			else if ((mx >= 448 && mx <= 585) && (my >= 304 && my <= 351));
			else if ((mx >= 448 && mx <= 585) && (my >= 247 && my <= 292));
			else if ((mx >= 448 && mx <= 585) && (my >= 190 && my <= 236)) menu = MAIN_MENU;
			else if ((mx >= 448 && mx <= 585) && (my >= 132 && my <= 177)) exit(0);
		}
		if (menu == CREDITS)
		{
			if ((mx >= 136 && mx <= 348) && (my >= 136 && my <= 151)) system("START https://www.github.com/SyedMashruk");
			else if ((mx >= 420 && mx <= 602) && (my >= 136 && my <= 152)) system("START https://www.github.com/rafi99-bat");
			else if ((mx >= 701 && mx <= 832) && (my >= 136 && my <= 153)) system("START https://www.github.com/alistairrr");
		}
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (menu == MAIN_MENU)
	{
	}
	else if (menu == GAME)
	{
		//key = tolower(key);
		if (key == 'a')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'b')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'c')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'd')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'e')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'f')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'g')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'h')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'i')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'j')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'k')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'l')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'm')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'n')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'o')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'p')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'q')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'r')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 's')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 't')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'u')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'v')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'w')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'x')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'y')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		else if (key == 'z')
		{
			if (alphabet[bubble1.id] == key && (bubble1.posY >= -bubble1.radius && bubble1.posY <= screenHeight))
			{
				score++;
				bubble1.bubbleUpdate();
			}
			else if (alphabet[bubble2.id] == key && (bubble2.posY >= -bubble2.radius && bubble2.posY <= screenHeight))
			{
				score++;
				bubble2.bubbleUpdate();
			}
			else if (alphabet[bubble3.id] == key && (bubble3.posY >= -bubble3.radius && bubble3.posY <= screenHeight))
			{
				score++;
				bubble3.bubbleUpdate();
			}
			else if (alphabet[bubble4.id] == key && (bubble4.posY >= -bubble4.radius && bubble4.posY <= screenHeight))
			{
				score++;
				bubble4.bubbleUpdate();
			}
			else if (alphabet[bubble5.id] == key && (bubble5.posY >= -bubble5.radius && bubble5.posY <= screenHeight))
			{
				score++;
				bubble5.bubbleUpdate();
			}
		}
		if (key == 27)
		{
			iPauseTimer(0);
			iPauseTimer(1);
			iPauseTimer(2);
			iPauseTimer(3);
			iPauseTimer(4);
			iPauseTimer(5);
			menu = PAUSE_MENU;
		}
	}
	else if (menu == INSTRUCTIONS)
	{
	}
	else if (menu == SETTINGS)
	{
	}
	else if (menu == PAUSE_MENU)
	{
		if (key == 27)
		{
			menu = GAME;
			iResumeTimer(0);
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(5);
		}
	}
	else if (menu == DIFFICULTY)
	{
	}
	else if (menu == GAME_OVER)
	{
	}
	else if (menu == SCORE_BOARD)
	{
	}
	else if (menu == CREDITS)
	{
		if (key == 8)
		{
			menu = MAIN_MENU;
		}
	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_LEFT)
	{

	}
	if(key == GLUT_KEY_RIGHT)
	{

	}
	if(key == GLUT_KEY_UP)
	{

	}
	if(key == GLUT_KEY_DOWN)
	{

	}
	//place your codes for other keys here
}

void update()
{
	iSetTimer(10, bubble1Move);
	iSetTimer(10, bubble2Move);
	iSetTimer(10, bubble3Move);
	iSetTimer(10, bubble4Move);
	iSetTimer(10, bubble5Move);
	iSetTimer(1000, timer);
	iInitialize(screenWidth, screenHeight, "Gaym developar");
	setResizable(false);
}

void start()
{
	iStart();
}