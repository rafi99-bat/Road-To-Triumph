#include "Book.h"
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

int score = 0;
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
				   'u', 'v', 'w', 'x', 'y', 'z',',', ';', '=', '!', '&', '*', '#', '%', '(', ')', '{', '}', '-'};
char str[30];
char buffer[2];
int menu = GAME;
int charLength = sizeof(alphabet)/sizeof(char);

Book book1 = Book(rand()%screenWidth, 30, 0.5, 1, rand() % (charLength / 5));
Book book2 = Book(rand()%screenWidth, 30, 2, 1, (charLength / 5) + rand() % (charLength / 5));
Book book3 = Book(rand()%screenWidth, 30, 1, 1, 2 * (charLength / 5) + rand() % (charLength / 5));
Book book4 = Book(rand()%screenWidth, 30, 1.5, 1, 3 * (charLength / 5) + rand() % (charLength / 5));
Book book5 = Book(rand()%screenWidth, 30, 2.5, 1, 4 * (charLength / 5) + rand() % (charLength / 5));

void initDeclare()
{
	book1 = Book(rand()%screenWidth, 30, 0.5, 1, rand() % (charLength / 5));
	book2 = Book(rand()%screenWidth, 30, 2, 1, (charLength / 5) + rand() % (charLength / 5));
	book3 = Book(rand()%screenWidth, 30, 1, 1, 2 * (charLength / 5) + rand() % (charLength / 5));
	book4 = Book(rand()%screenWidth, 30, 1.5, 1, 3 * (charLength / 5) + rand() % (charLength / 5));
	book5 = Book(rand()%screenWidth, 30, 2.5, 1, 4 * (charLength / 5) + rand() % (charLength / 5));
	menu = GAME;
}

void book1Move()
{
	if (menu == GAME)
	{
		if (book1.state == 1)
		{
			if (book1.posY > screenHeight)
			{
				book1.posX = rand() % screenWidth;
				book1.posY = -book1.radius;
				book1.id = rand() % (charLength / 5);
			}
			else if (book1.posY <= screenHeight)
			{
				book1.posY += book1.speed;
			}
		}
	}
}

void book2Move()
{
	if (menu == GAME)
	{
		if (book2.state == 1)
		{
			if (book2.posY > screenHeight)
			{
				book2.posX = rand() % screenWidth;
				book2.posY = -book2.radius;
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (book2.posY <= screenHeight)
			{
				book2.posY += book2.speed;
			}
		}
	}
}

void book3Move()
{
	if (menu == GAME)
	{
		if (book3.state == 1)
		{
			if (book3.posY > screenHeight)
			{
				book3.posX = rand() % screenWidth;
				book3.posY = -book3.radius;
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (book3.posY <= screenHeight)
			{
				book3.posY += book3.speed;
			}
		}
	}
}

void book4Move()
{
	if (menu == GAME)
	{
		if (book4.state == 1)
		{
			if (book4.posY > screenHeight)
			{
				book4.posX = rand() % screenWidth;
				book4.posY = -book4.radius;
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (book4.posY <= screenHeight)
			{
				book4.posY += book4.speed;
			}
		}
	}
}

void book5Move()
{
	if (menu == GAME)
	{
		if (book5.state == 1)
		{
			if (book5.posY > screenHeight)
			{
				book5.posX = rand() % screenWidth;
				book5.posY = -book5.radius;
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (book5.posY <= screenHeight)
			{
				book5.posY += book5.speed;
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
		if (book1.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(book1.posX, book1.posY, book1.radius, 100);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[book1.id]);
			iText(book1.posX - 5, book1.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		if (book2.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(book2.posX, book2.posY, book2.radius, 100);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[book2.id]);
			iText(book2.posX - 5, book2.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		if (book3.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(book3.posX, book3.posY, book3.radius, 100);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[book3.id]);
			iText(book3.posX - 5, book3.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		if (book4.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(book4.posX, book4.posY, book4.radius, 100);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[book4.id]);
			iText(book4.posX - 5, book4.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
		if (book5.state)
		{
			iSetColor(rand()%255, rand()%255, rand()%255);
			iFilledCircle(book5.posX, book5.posY, book5.radius, 100);
			iSetColor(0, 0, 0);
			sprintf(buffer, "%c", alphabet[book5.id]);
			iText(book5.posX - 5, book5.posY - 5, buffer, GLUT_BITMAP_HELVETICA_18);
		}
	}
	if (menu == PAUSE_MENU)
	{
		iShowBMP(screenPosX, screenPosY, "res\\images\\PauseMenu(255).bmp");
		iSetColor(255, 255, 255);
		if (mouseMode == CLICKABLE)
		{
			if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 453 && mousePosY <= 507)) iLine(684, 464, 796, 464);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 383 && mousePosY <= 437)) iLine(689, 396, 788, 396);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 311 && mousePosY <= 366)) iLine(704, 327, 772, 327);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 240 && mousePosY <= 294)) iLine(705, 254, 771, 254);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 168 && mousePosY <= 223)) iLine(665, 183, 816, 183);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 96 && mousePosY <= 151)) iLine(715, 113, 764, 113);
		}
	}
	if (menu == CREDITS)
	{
		iShowBMP(screenPosX, screenPosY, "res\\images\\Credit.bmp");
		if (mouseMode == CLICKABLE)
		{
			if ((mousePosX >= 136 && mousePosX <= 348) && (mousePosY >= 136 && mousePosY <= 151)) iLine(138, 134, 348, 134);
			else if ((mousePosX >= 420 && mousePosX <= 602) && (mousePosY >= 136 && mousePosY <= 152)) iLine(422, 134, 602, 134);
			else if ((mousePosX >= 701 && mousePosX <= 832) && (mousePosY >= 136 && mousePosY <= 153)) iLine(702, 136, 834, 136);
		}
	}
	iShowBMP2(mousePosX, mousePosY - 31, "res\\images\\cursor(0).bmp", 0);
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
		if (((mx >= 653 && mx <= 825) && (my >= 453 && my <= 507)) || 
		    ((mx >= 653 && mx <= 825) && (my >= 383 && my <= 437)) ||
			((mx >= 653 && mx <= 825) && (my >= 311 && my <= 366)) || 
			((mx >= 653 && mx <= 825) && (my >= 240 && my <= 294)) || 
			((mx >= 653 && mx <= 825) && (my >= 168 && my <= 223)) || 
			((mx >= 653 && mx <= 825) && (my >= 96 && my <= 151))) mouseMode = CLICKABLE;
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
			menu = GAME;
		}
		if (menu == PAUSE_MENU)
		{
			if ((mx >= 653 && mx <= 825) && (my >= 453 && my <= 507))
			{
				menu = GAME;
				iResumeTimer(0);
				iResumeTimer(1);
				iResumeTimer(2);
				iResumeTimer(3);
				iResumeTimer(4);
			}
			else if ((mx >= 653 && mx <= 825) && (my >= 383 && my <= 437))
			{
				initDeclare();
				iResumeTimer(0);
				iResumeTimer(1);
				iResumeTimer(2);
				iResumeTimer(3);
				iResumeTimer(4);
			}
			else if ((mx >= 653 && mx <= 825) && (my >= 311 && my <= 366));
			else if ((mx >= 653 && mx <= 825) && (my >= 240 && my <= 294));
			else if ((mx >= 653 && mx <= 825) && (my >= 168 && my <= 223)) menu = MAIN_MENU;
			else if ((mx >= 653 && mx <= 825) && (my >= 96 && my <= 151)) exit(0);
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
		if (key == 'a')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'b')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'c')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'd')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'e')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'f')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'g')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'h')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'i')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'j')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'k')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'l')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'm')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'n')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'o')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY <= screenHeight)) book1.bookUpdate();
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY <= screenHeight)) book2.bookUpdate();
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY <= screenHeight)) book3.bookUpdate();
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY <= screenHeight)) book4.bookUpdate();
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY <= screenHeight)) book5.bookUpdate();
		}
		else if (key == 'p')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'q')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'r')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 's')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 't')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'u')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'v')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'w')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'x')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'y')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == 'z')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == ',')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == ';')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '=')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '!')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '&')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '*')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '#')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '%')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '(')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == ')')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '{')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '}')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		else if (key == '-')
		{
			if (alphabet[book1.id] == key && (book1.posY >= -book1.radius && book1.posY - 40 <= screenHeight))
			{
				book1.bookUpdate();
				book1.id = rand() % (charLength / 5);
			}
			else if (alphabet[book2.id] == key && (book2.posY >= -book2.radius && book2.posY - 40 <= screenHeight))
			{
				book2.bookUpdate();
				book2.id = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book3.id] == key && (book3.posY >= -book3.radius && book3.posY - 40 <= screenHeight))
			{
				book3.bookUpdate();
				book3.id = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book4.id] == key && (book4.posY >= -book4.radius && book4.posY - 40 <= screenHeight))
			{
				book4.bookUpdate();
				book4.id = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book5.id] == key && (book5.posY >= -book5.radius && book5.posY - 40 <= screenHeight))
			{
				book5.bookUpdate();
				book5.id = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
		}
		if (key == 27)
		{
			iPauseTimer(0);
			iPauseTimer(1);
			iPauseTimer(2);
			iPauseTimer(3);
			iPauseTimer(4);
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
	iSetTimer(10, book1Move);
	iSetTimer(10, book2Move);
	iSetTimer(10, book3Move);
	iSetTimer(10, book4Move);
	iSetTimer(10, book5Move);
	iInitialize(screenWidth, screenHeight, "Road to Triumph");
	setResizable(false);
}

void start()
{
	iStart();
}