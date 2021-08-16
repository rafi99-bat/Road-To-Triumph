#include "iGraphics.h"
#include "Game.h"
#include "Player.h"

int screenWidth = 1024;
int screenHeight = 600;

Player player = Player();

double X = 0;
double Y = 0;

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	iSetColor(255, 255, 255);
	iFilledRectangle(X, Y, screenWidth, screenHeight); 
	iSetColor(255, 0, 0);
	iFilledRectangle((screenWidth - player.size) / 2, (screenHeight - player.size) / 2 , player.size, player.size);
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
	//place your codes here
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
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
	if (key == 'w')
	{
		Y -= 10;
	}
	else if (key == 's')
	{
		Y += 10;
	}
	if (key == 'a')
	{
		X += 10;
	}
	else if (key == 'd')
	{
		X -= 10;
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
	iInitialize(screenWidth, screenHeight, "Gaym developar");
	setResizable(false);
}

void start()
{
	iStart();
}