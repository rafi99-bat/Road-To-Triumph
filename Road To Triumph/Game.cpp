#include "Book.h"
#include "Menu.h"
#include "iGraphics.h"
#include "Game.h"

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
bool playing = true;
bool gameMusic = true;
int max = 0;

Book book[5];
Book supplementary;

int score = 0;
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
				   'u', 'v', 'w', 'x', 'y', 'z',',', ';', '=', '!', '&', '*', '#', '%', '(', ')', '{', '}', '-'};
char playerName[30];
char str[30];
char str2[30];
char buffer[2];
int len = 0;
int menu = INTRO;
int charLength = sizeof(alphabet)/sizeof(char);

void initDeclare()
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
	supplementary.state = false;
	supplementary.score = 5;
	menu = GAME;
}

int lowestScore(Book book[])
{
	int min = book[0].score;
    for(int i = 0; i < 5; i++){
        if(book[i].score < min){
            min = book[i].score;
        }
    }
	return min;
}

void scoring()
{
	iSetColor(0, 0, 0);
	sprintf(str, "%d", book[0].score);
	iText(80, 483, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[1].score);
	iText(80, 453, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[2].score);
	iText(80, 424, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[3].score);
	iText(80, 395, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[4].score);
	iText(80, 367, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[0].count);
	iText(80, 216, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[1].count);
	iText(80, 186, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[2].count);
	iText(80, 156, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[3].count);
	iText(80, 126, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d", book[4].count);
	iText(80, 96, str, GLUT_BITMAP_TIMES_ROMAN_24);
}

void showResult()
{
	iShowBMP(screenPosX, screenPosY, "res/images/result.bmp");
	book[0].GPAcount();
	book[1].GPAcount();
	book[2].GPAcount();
	book[3].GPAcount();
	book[4].GPAcount();
	iSetColor(0, 0, 0);
	sprintf(str, "%.2lf", (book[0].GPA + book[1].GPA + book[2].GPA + book[3].GPA + book[4].GPA) / 5);
	iText(617, 420, str, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(str, "%d / 100", book[0].score);
	iText(675, 292, str, GLUT_BITMAP_HELVETICA_18);
	sprintf(str, "%d / 100", book[1].score);
	iText(675, 246, str, GLUT_BITMAP_HELVETICA_18);
	sprintf(str, "%d / 100", book[2].score);
	iText(675, 200, str, GLUT_BITMAP_HELVETICA_18);
	sprintf(str, "%d / 100", book[3].score);
	iText(675, 153, str, GLUT_BITMAP_HELVETICA_18);
	sprintf(str, "%d / 100", book[4].score);
	iText(675, 110, str, GLUT_BITMAP_HELVETICA_18);
	sprintf(str, "%d / 500", (book[0].score + book[1].score + book[2].score + book[3].score + book[4].score));
	iText(675, 50, str, GLUT_BITMAP_HELVETICA_18);
	int failed = iLoadImage("res/images/fail.png");
	if (book[0].score < 40)
		iShowImage(860, 285, 80, 29, failed);
	if (book[1].score < 40)
		iShowImage(860, 240, 80, 29, failed);
	if (book[2].score < 40)
		iShowImage(860, 193, 80, 29, failed);
	if (book[3].score < 40)
		iShowImage(860, 147, 80, 29, failed);
	if (book[4].score < 40)
		iShowImage(860, 100, 80, 29, failed);
	if (typeMode)
	{
		strcpy(playerName, str2);
		strcpy(str, str2);
		strcat(str, "|");
		iText(135, 421, str, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		if (len == 0)
		{
			iSetColor(150, 150, 150);
			iText(135, 422, "Enter Name and Surname", GLUT_BITMAP_HELVETICA_18);
		}
		else
		{
			iSetColor(0, 0, 0);
			iText(135, 421, playerName, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}

void showCertificate()
{
	iShowBMP(screenPosX, screenPosY, "res/images/certificate.bmp");
	iSetColor(0, 0, 0);
	strcpy(str, playerName);
	strupr(str);
	iText(405, 300, str, GLUT_BITMAP_TIMES_ROMAN_24);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(str, "%02d", tm.tm_mday);
	iText(213, 118, str, GLUT_BITMAP_HELVETICA_18);
	sprintf(str, "%02d", tm.tm_mon + 1);
	iText(254, 118, str, GLUT_BITMAP_HELVETICA_18);
	sprintf(str, "%d", tm.tm_year + 1900);
	iText(296, 118, str, GLUT_BITMAP_HELVETICA_18);
	iSetColor(131, 139, 56);
	iText(435, 56, "Press any key to continue", GLUT_BITMAP_HELVETICA_12);
}

void showScoreBoard()
{
	iShowBMP(screenPosX, screenPosY, "res/images/score-board.bmp");
	iSetColor(0, 0, 0);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(str, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	iText(780, 460, str, GLUT_BITMAP_HELVETICA_12);
	//iText(186, 324, "Rafeed Mahbub", GLUT_BITMAP_HELVETICA_18);
	//iText(186, 296, "Rafeed Mahbub", GLUT_BITMAP_HELVETICA_18);
	//iText(186, 268, "Rafeed Mahbub", GLUT_BITMAP_HELVETICA_18);
	//iText(186, 241, "Rafeed Mahbub", GLUT_BITMAP_HELVETICA_18);
	//iText(186, 212, "Rafeed Mahbub", GLUT_BITMAP_HELVETICA_18);
}

void showCursor()
{
	int cursor = iLoadImage("res/images/cursor.png");
	iShowImage(mousePosX, mousePosY - 31, 30, 30, cursor);
	glutSetCursor(GLUT_CURSOR_NONE);
}

void bookRender()
{
	if (book[0].state && book[0].count)
	{
		int b0 = iLoadImage("res/images/red.png");
		iShowImage(book[0].posX - 35, book[0].posY - 40, 80, 84, b0);
		iSetColor(0, 0, 0);
		sprintf(buffer, "%c", alphabet[book[0].index]);
		iText(book[0].posX - 10, book[0].posY - 8, buffer, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (book[1].state && book[1].count)
	{
		int b1 = iLoadImage("res/images/blue.png");
		iShowImage(book[1].posX - 35, book[1].posY - 40, 80, 84, b1);
		iSetColor(0, 0, 0);
		sprintf(buffer, "%c", alphabet[book[1].index]);
		iText(book[1].posX - 10, book[1].posY - 8, buffer, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (book[2].state && book[2].count)
	{
		int b2 = iLoadImage("res/images/green.png");
		iShowImage(book[2].posX - 35, book[2].posY - 40, 80, 84, b2);
		iSetColor(0, 0, 0);
		sprintf(buffer, "%c", alphabet[book[2].index]);
		iText(book[2].posX - 10, book[2].posY - 8, buffer, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (book[3].state && book[3].count)
	{
		int b3 = iLoadImage("res/images/yellow.png");
		iShowImage(book[3].posX - 35, book[3].posY - 40, 80, 84, b3);
		iSetColor(0, 0, 0);
		sprintf(buffer, "%c", alphabet[book[3].index]);
		iText(book[3].posX - 10, book[3].posY - 8, buffer, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (book[4].state && book[4].count)
	{
		int b4 = iLoadImage("res/images/violet.png");
		iShowImage(book[4].posX - 35, book[4].posY - 40, 80, 84, b4);
		iSetColor(0, 0, 0);
		sprintf(buffer, "%c", alphabet[book[4].index]);
		iText(book[4].posX - 10, book[4].posY - 10, buffer, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (supplementary.state && supplementary.count)
	{
		int s = iLoadImage("res/images/notes1.png");
		iShowImage(supplementary.posX - 35, supplementary.posY - 40, 80, 84, s);
		iSetColor(0, 0, 0);
		sprintf(buffer, "%c", alphabet[supplementary.index]);
		iText(supplementary.posX - 10, supplementary.posY - 10, buffer, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void book0Move()
{	
	if (menu == GAME)
	{
		if (book[0].state)
		{
			if (book[0].posY > screenHeight)
			{
				if (book[0].count)
				{
					book[0].count--;
					book[0].posX = 313;
					book[0].posY = -book[0].size - rand() % 100;
					book[0].index = rand() % (charLength / 5);
				}
			}
			else if (book[0].posY <= screenHeight)
			{
				book[0].posY += book[0].speed;
			}
		}
	}
}

void book1Move()
{
	if (menu == GAME)
	{
		if (book[1].state)
		{
			if (book[1].posY > screenHeight)
			{
				if (book[1].count)
				{
					book[1].count--;
					book[1].posX = 455;
					book[1].posY = -book[1].size - rand() % 100;
					book[1].index = (charLength / 5) + rand() % (charLength / 5);
				}
			}
			else if (book[1].posY <= screenHeight)
			{
				book[1].posY += book[1].speed;
			}
		}
	}
}

void book2Move()
{
	if (menu == GAME)
	{
		if (book[2].state)
		{
			if (book[2].posY > screenHeight)
			{
				if (book[2].count)
				{
					book[2].count--;
					book[2].posX = 597;
					book[2].posY = -book[2].size - rand() % 100;
					book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
				}
			}
			else if (book[2].posY <= screenHeight)
			{
				book[2].posY += book[2].speed;
			}
		}
	}
}

void book3Move()
{
	if (menu == GAME)
	{
		if (book[3].state)
		{
			if (book[3].posY > screenHeight)
			{
				if (book[3].count)
				{
					book[3].count--;
					book[3].posX = 739;
					book[3].posY = -book[3].size - rand() % 100;
					book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
				}
			}
			else if (book[3].posY <= screenHeight)
			{
				book[3].posY += book[3].speed;
			}
		}
	}
}

void book4Move()
{
	if (menu == GAME)
	{
		if (book[4].state)
		{
			if (book[4].posY > screenHeight)
			{
				if (book[4].count)
				{
					book[4].count--;
					book[4].posX = 881;
					book[4].posY = -book[4].size - rand() % 100;
					book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
				}
			}
			else if (book[4].posY <= screenHeight)
			{
				book[4].posY += book[4].speed;
			}
		}
	}
}

void supplementaryMove()
{	
	if (menu == GAME)
	{
		for (int i = 0; i < 5; i++)
		{
			if ((book[i].score == 20 || book[i].score == 40 || book[i].score == 60) && book[i].score > max)
			{
				supplementary.state = true;
				max = book[i].score;
			}
		}
		if (supplementary.state)
		{
			if (!book[0].count && !book[1].count && !book[2].count && !book[3].count && !book[4].count)
			{
				supplementary.count = 0;
			}
			if (supplementary.posY > screenHeight)
			{
				if (supplementary.count)
				{
					supplementary.count--;
					supplementary.posX = 171 + rand() % 853;
					supplementary.posY = -300;
					supplementary.index = rand() % charLength;
				}
			}
			else if (supplementary.posY <= screenHeight)
			{
				supplementary.posY += supplementary.speed;
			}
		}
	}
}

void speedup()
{
	if (book[0].score <= 40)
		book[0].speed += 0.125;
	if (book[1].score <= 40)
		book[1].speed += 0.125;
	if (book[2].score <= 40)
		book[2].speed += 0.125;
	if (book[3].score <= 40)
		book[3].speed += 0.125;
	if (book[4].score <= 40)
		book[4].speed += 0.125;

	if (book[0].score > 40 && book[0].score <= 60)
		book[0].speed += 0.5;
	if (book[1].score > 40 && book[1].score <= 60)
		book[1].speed += 0.5;
	if (book[2].score > 40 && book[2].score <= 60)
		book[2].speed += 0.5;
	if (book[3].score > 40 && book[3].score <= 60)
		book[3].speed += 0.5;
	if (book[4].score > 40 && book[4].score <= 60)
		book[4].speed += 0.5;

	if (book[0].score > 60)
		book[0].speed += 0.85;
	if (book[1].score > 60)
		book[1].speed += 0.85;
	if (book[2].score > 60)
		book[2].speed += 0.85;
	if (book[3].score > 60)
		book[3].speed += 0.85;
	if (book[4].score > 60)
		book[4].speed += 0.85;
}

void iDraw()
{
	iClear();
	if (menu == INTRO)
	{
		iShowBMP(screenPosX, screenPosY, "res/images/intro.bmp");
		showCursor();
	}
	if (menu == MAIN_MENU)
	{
		iShowBMP(screenPosX, screenPosY, "res/images/menu.bmp");
		if (mouseMode == CLICKABLE)
		{
			iSetColor(99, 98, 98);
			if ((mousePosX >= 675 && mousePosX <= 846) && (mousePosY >= 506 && mousePosY <= 547))
				iLine(675, 509, 847, 509);
			else if ((mousePosX >= 670 && mousePosX <= 847) && (mousePosY >= 422 && mousePosY <= 463))
				iLine(672, 426, 846, 426);
			else if ((mousePosX >= 676 && mousePosX <= 844) && (mousePosY >= 334 && mousePosY <= 379))
				iLine(677, 340, 844, 340);
			else if ((mousePosX >= 670 && mousePosX <= 848) && (mousePosY >= 254 && mousePosY <= 297))
				iLine(671, 258, 847, 258);
			else if ((mousePosX >= 709 && mousePosX <= 812) && (mousePosY >= 170 && mousePosY <= 212))
				iLine(709, 172, 812, 172);
			else if ((mousePosX >= 725 && mousePosX <= 791) && (mousePosY >= 86 && mousePosY <= 128))
				iLine(724, 88, 791, 88);
		}
		int button = iLoadImage("res/images/button.png");
		iShowImage(23, 30, 100, 40, button);
		iSetColor(0, 0, 0);
		iText(30, 43, "Sound:", GLUT_BITMAP_HELVETICA_18);
		if (playing)
		{
			iSetColor(0, 155, 0);
			iText(90, 43, "On", GLUT_BITMAP_HELVETICA_18);
		}
		else
		{
			iSetColor(255, 0, 0);
			iText(90, 43, "Off", GLUT_BITMAP_HELVETICA_18);
		}
		showCursor();
	}
	if (menu == GAME)
	{
		iShowBMP(screenPosX, screenPosY, "res/images/game.bmp");
		bookRender();
		scoring();
		if (!book[0].count && !book[1].count && !book[2].count && !book[3].count && !book[4].count)
		{
			iShowBMP(screenPosX, screenPosY, "res/images/image.bmp");
			int gameOver = iLoadImage("res/images/gameover.png");
			iShowImage(337, 260, 350, 110, gameOver);
			iSetColor(0, 0, 0);
			iText(468, 265, "Click to continue", GLUT_BITMAP_HELVETICA_12);
		}
		showCursor();
	}
	if (menu == PAUSE_MENU)
	{
		iShowBMP(screenPosX, screenPosY, "res/images/PauseMenu(255).bmp");
		if (mouseMode == CLICKABLE)
		{
			iSetColor(0, 0, 0);
			if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 453 && mousePosY <= 507))
				iLine(688, 467, 790, 467);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 383 && mousePosY <= 437))
				iLine(684, 397, 788, 397);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 311 && mousePosY <= 366))
				iLine(706, 324, 772, 324);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 240 && mousePosY <= 294))
				iLine(700, 253, 775, 253);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 168 && mousePosY <= 223))
				iLine(662, 183, 816, 183);
			else if ((mousePosX >= 653 && mousePosX <= 825) && (mousePosY >= 96 && mousePosY <= 151))
				iLine(710, 107, 764, 107);
		}
		int button = iLoadImage("res/images/button.png");
		iShowImage(23, 30, 100, 40, button);
		iSetColor(0, 0, 0);
		iText(30, 43, "Sound:", GLUT_BITMAP_HELVETICA_18);
		if (playing)
		{
			iSetColor(0, 155, 0);
			iText(90, 43, "On", GLUT_BITMAP_HELVETICA_18);
		}
		else
		{
			iSetColor(255, 0, 0);
			iText(90, 43, "Off", GLUT_BITMAP_HELVETICA_18);
		}
		showCursor();
	}
	if (menu == GAME_OVER)
	{
		showResult();
		if (mouseMode == CLICKABLE)
			glutSetCursor(GLUT_CURSOR_TEXT);
		else
			showCursor();
	}
	if (menu == CERTIFICATE)
	{
		showCertificate();
		showCursor();
	}
	if (menu == SCORE_BOARD)
	{
		showScoreBoard();
		showCursor();
	}
	if (menu == CREDITS)
	{
		iShowBMP(screenPosX, screenPosY, "res/images/Credit.bmp");
		if (mouseMode == CLICKABLE)
		{
			iSetColor(255, 255, 255);
			if ((mousePosX >= 136 && mousePosX <= 348) && (mousePosY >= 136 && mousePosY <= 151))
				iLine(138, 134, 348, 134);
			else if ((mousePosX >= 420 && mousePosX <= 602) && (mousePosY >= 136 && mousePosY <= 152))
				iLine(422, 134, 602, 134);
			else if ((mousePosX >= 701 && mousePosX <= 832) && (mousePosY >= 136 && mousePosY <= 153))
				iLine(702, 136, 834, 136);
		}
		showCursor();
	}
}

void iMouseMove(int mx, int my)
{
}

void iPassiveMouse(int mx, int my)
{
	if ((mx >= screenPosX && mx + 17 <= screenWidth) && (my - 31 >= screenPosY && my <= screenHeight))
	{
		mousePosX = mx;
		mousePosY = my;
	}
	if (menu == MAIN_MENU)
	{
		if (((mx >= 675 && mx <= 846) && (my >= 506 && my <= 547)) || 
		    ((mx >= 670 && mx <= 847) && (my >= 422 && my <= 463)) ||
			((mx >= 676 && mx <= 844) && (my >= 334 && my <= 379)) || 
			((mx >= 670 && mx <= 848) && (my >= 254 && my <= 297)) || 
			((mx >= 709 && mx <= 812) && (my >= 170 && my <= 212)) || 
			((mx >= 725 && mx <= 791) && (my >= 86 && my <= 128)))
			mouseMode = CLICKABLE;
		else
			mouseMode = NON_CLICKABLE;
	}
	else if (menu == PAUSE_MENU)
	{
		if (((mx >= 653 && mx <= 825) && (my >= 453 && my <= 507)) || 
		    ((mx >= 653 && mx <= 825) && (my >= 383 && my <= 437)) ||
			((mx >= 653 && mx <= 825) && (my >= 311 && my <= 366)) || 
			((mx >= 653 && mx <= 825) && (my >= 240 && my <= 294)) || 
			((mx >= 653 && mx <= 825) && (my >= 168 && my <= 223)) || 
			((mx >= 653 && mx <= 825) && (my >= 96 && my <= 151)))
			mouseMode = CLICKABLE;
		else
			mouseMode = NON_CLICKABLE;
	}
	else if (menu == GAME_OVER)
	{
		if ((mx >= 112 && mx <= 409) && (my >= 404 && my <= 464))
			mouseMode = CLICKABLE;
		else
			mouseMode = NON_CLICKABLE;
	}
	else if (menu == CREDITS)
	{
		if (((mx >= 136 && mx <= 348) && (my >= 136 && my <= 151)) || 
			((mx >= 420 && mx <= 602) && (my >= 136 && my <= 152)) || 
			((mx >= 701 && mx <= 832) && (my >= 136 && my <= 153)))
			mouseMode = CLICKABLE;
		else
			mouseMode = NON_CLICKABLE;
	}
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//printf("%d %d\n", mx, my);
		if (menu == INTRO)
		{
			menu = MAIN_MENU;
		}
		else if (menu == MAIN_MENU)
		{
			if ((mx >= 675 && mx <= 846) && (my >= 506 && my <= 547))
			{
				playing = false;
				if (!playing)
					PlaySound(NULL, NULL, SND_ASYNC);
				initDeclare();
			}
			else if ((mx >= 670 && mx <= 847) && (my >= 422 && my <= 463));
			else if ((mx >= 676 && mx <= 844) && (my >= 334 && my <= 379))
			{
				menu = SCORE_BOARD;
			}
			else if ((mx >= 670 && mx <= 848) && (my >= 254 && my <= 297))
			{
				menu = INSTRUCTIONS;
			}
			else if ((mx >= 709 && mx <= 812) && (my >= 170 && my <= 212))
			{
				menu = CREDITS;
			}
			else if ((mx >= 725 && mx <= 791) && (my >= 86 && my <= 128))
			{
				exit(0);
			}
			else if ((mx >= 23 && mx <= 120) && (my >= 33 && my <= 69))
			{
				if (playing)
				{
					playing = false;
					if (!playing)
						PlaySound(NULL, NULL, SND_ASYNC);
				}
				else
				{
					playing = true;
					if (playing)
						PlaySound(TEXT("res/audio/bensound-buddy.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
				gameMusic = playing;
			}
		}
		else if (menu == GAME)
		{
			if ((mx >= 930 && mx <= 1012) && (my >= 554 && my <= 590))
			{
				playing = gameMusic;
				if (gameMusic)
					PlaySound(TEXT("res/audio/bensound-buddy.wav"), NULL, SND_LOOP | SND_ASYNC);
				iPauseTimer(0);
				iPauseTimer(1);
				iPauseTimer(2);
				iPauseTimer(3);
				iPauseTimer(4);
				iPauseTimer(5);
				menu = PAUSE_MENU;
			}
			if (!book[0].count && !book[1].count && !book[2].count && !book[3].count && !book[4].count)
			{
				menu = GAME_OVER;
			}
		}
		else if (menu == PAUSE_MENU)
		{
			if ((mx >= 653 && mx <= 825) && (my >= 453 && my <= 507))
			{
				playing = false;
				if (!playing)
					PlaySound(NULL, NULL, SND_ASYNC);
				menu = GAME;
				iResumeTimer(0);
				iResumeTimer(1);
				iResumeTimer(2);
				iResumeTimer(3);
				iResumeTimer(4);
				iResumeTimer(5);
			}
			else if ((mx >= 653 && mx <= 825) && (my >= 383 && my <= 437))
			{
				playing = false;
				if (!playing)
					PlaySound(NULL, NULL, SND_ASYNC);
				initDeclare();
				iResumeTimer(0);
				iResumeTimer(1);
				iResumeTimer(2);
				iResumeTimer(3);
				iResumeTimer(4);
				iResumeTimer(5);
				iResumeTimer(6);
			}
			else if ((mx >= 653 && mx <= 825) && (my >= 311 && my <= 366));
			else if ((mx >= 653 && mx <= 825) && (my >= 240 && my <= 294));
			else if ((mx >= 653 && mx <= 825) && (my >= 168 && my <= 223))
				menu = MAIN_MENU;
			else if ((mx >= 653 && mx <= 825) && (my >= 96 && my <= 151))
				exit(0);
			else if ((mx >= 23 && mx <= 120) && (my >= 33 && my <= 69))
			{
				if (playing)
				{
					playing = false;
					PlaySound(NULL, NULL, SND_ASYNC);
				}
				else
				{
					playing = true;
					PlaySound(TEXT("res/audio/bensound-buddy.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
				gameMusic = playing;
			}
		}
		else if (menu == GAME_OVER)
		{
			playing = gameMusic;
			if (gameMusic)
				PlaySound(TEXT("res/audio/bensound-buddy.wav"), NULL, SND_LOOP | SND_ASYNC);
			if ((mx >= 112 && mx <= 409) && (my >= 404 && my <= 464) && !typeMode)
				typeMode = true;
			else
				typeMode = false;
		}
		else if (menu == CERTIFICATE)
		{
			menu = SCORE_BOARD;
		}
		else if (menu == SCORE_BOARD)
		{
			if ((mx >= 810 && mx <= 928) && (my >= 524 && my <= 563))
				menu = MAIN_MENU;
		}
		else if (menu == CREDITS)
		{
			if ((mx >= 136 && mx <= 348) && (my >= 136 && my <= 151))
				system("START https://www.github.com/SyedMashruk");
			else if ((mx >= 420 && mx <= 602) && (my >= 136 && my <= 152))
				system("START https://www.github.com/rafi99-bat");
			else if ((mx >= 701 && mx <= 832) && (my >= 136 && my <= 153))
				system("START https://www.github.com/alistairrr");
			else if ((mx >= 25 && mx <= 149) && (my >= 540 && my <= 589))
				menu = MAIN_MENU;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

void iKeyboard(unsigned char key)
{
	if (menu == INTRO)
	{
		menu = MAIN_MENU;
	}
	else if (menu == GAME)
	{
		if (key == 'a')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'b')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'c')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'd')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'e')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'f')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'g')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'h')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'i')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'j')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'k')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'l')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'm')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'n')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'o')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'p')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'q')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'r')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 's')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 't')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'u')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'v')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'w')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'x')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'y')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == 'z')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == ',')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == ';')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '=')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '!')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '&')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '*')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '#')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '%')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '(')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == ')')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '{')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '}')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
			}
		}
		else if (key == '-')
		{
			if (alphabet[book[0].index] == key && (book[0].posY >= -book[0].size && book[0].posY - 40 <= screenHeight))
			{
				book[0].posX = 313;
				book[0].bookUpdate();
				book[0].index = rand() % (charLength / 5);
			}
			else if (alphabet[book[1].index] == key && (book[1].posY >= -book[1].size && book[1].posY - 40 <= screenHeight))
			{
				book[1].posX = 455;
				book[1].bookUpdate();
				book[1].index = (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[2].index] == key && (book[2].posY >= -book[2].size && book[2].posY - 40 <= screenHeight))
			{
				book[2].posX = 597;
				book[2].bookUpdate();
				book[2].index = 2 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[3].index] == key && (book[3].posY >= -book[3].size && book[3].posY - 40 <= screenHeight))
			{
				book[3].posX = 739;
				book[3].bookUpdate();
				book[3].index = 3 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[book[4].index] == key && (book[4].posY >= -book[4].size && book[4].posY - 40 <= screenHeight))
			{
				book[4].posX = 881;
				book[4].bookUpdate();
				book[4].index = 4 * (charLength / 5) + rand() % (charLength / 5);
			}
			else if (alphabet[supplementary.index] == key && (supplementary.posY >= -supplementary.size && supplementary.posY - 40 <= screenHeight))
			{
				PlaySound(TEXT("res/audio/special-book-collect.wav"), NULL, SND_ASYNC);
				supplementary.count--;
				int min = lowestScore(book);
				for (int i = 0; i < 5; i++)
				{
					if (book[i].score == min)
					{
						book[i].score += supplementary.score;
						break;
					}
				}
				supplementary.posY = -300;
				supplementary.index = rand() % charLength;
				supplementary.state = false;
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
	else if (menu == GAME_OVER)
	{
		if (typeMode)
		{
			if (key == '\r')
			{
				typeMode = 0;
				for(int i = 0; i < len; i++)
					str2[i] = 0;
				len = 0;
				if (book[0].score >= 80 && book[1].score >= 80 && book[2].score >= 80 && book[3].score >= 80 && book[4].score >= 80)
					menu = CERTIFICATE;
				else
					menu = SCORE_BOARD;
			}
			else if(key == '\b')
			{
				if(len!=0)
					len--;
				str2[len] = 0;
			}
			else
			{
				str2[len] = key;
				len++;
			}
		}
		else
		{
			if (len > 0)
			{
				if (key == '\r')
					menu = SCORE_BOARD;
			}
		}
	}
	else if (menu == CERTIFICATE)
	{
		menu = SCORE_BOARD;
	}
	else if (menu == CREDITS)
	{
		if (key == '\b')
		{
			menu = MAIN_MENU;
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		
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
}

void update()
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
	supplementary.state = false;
	supplementary.score = 5;
	iSetTimer(8000, speedup);
	iSetTimer(10, book0Move);
	iSetTimer(10, book1Move);
	iSetTimer(10, book2Move);
	iSetTimer(10, book3Move);
	iSetTimer(10, book4Move);
	iSetTimer(10, supplementaryMove);
	if (playing)
		PlaySound(TEXT("res/audio/bensound-buddy.wav"), NULL, SND_LOOP | SND_ASYNC);
	iInitialize(screenWidth, screenHeight, "Road to Triumph");
	setResizable(false);
}

void start()
{
	iStart();
}