#ifndef GAME_H
#define GAME_H

void iDraw();
void iMouseMove(int, int);
void iPassiveMouse(int, int);
void iMouse(int, int, int, int);
void iKeyboard(unsigned char);
void iSpecialKeyboard(unsigned char);
void update();
void start();

#endif