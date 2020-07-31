#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <cmath>
#include "Tanks.h"
#include "Rect.h"
#include "Vector.h"
#include "Ball.h"

#define PI 3.1415926535
#define PI2 3.1415926535*2
using namespace std;
int frame, time, timebase, oldTime;

float dt;
Tanks Player1(-5, 0, 5);
Tanks Player2(5, 0, 5);
bool Up = false, Down = false, Right = false, Left = false; //Flechas
bool W = false, S = false, D = false, A = false; //Letras
float pos;
float vel;
char* s;
const int maxBall = 2; // 100 350fps; //250 100fps
//Ball* ball[maxBall];
Ball Balls[6];
Rect* rect1;
Tanks* tank;

void InputK(int key, int y, int x) //Detecta los inputs
{
	switch (key)
	{
	case GLUT_KEY_UP:
		Up = true;
		break;
	case GLUT_KEY_DOWN:
		Down = true;
		break;
	case GLUT_KEY_RIGHT:
		Right = true;
		break;
	case GLUT_KEY_LEFT:
		Left = true;
		break;
	}
}

void Input(unsigned char key, int y, int x)
{
	switch (key)
	{
	case 'w':
		W = true;
		break;
	case 's':
		S = true;
		break;
	case 'a':
		A = true;
		break;
	case 'd':
		D = true;
		break;
	case 'c':
		C = true;
		break;
	case 'v':
		V = true;
		break;
	}
}

//Flechas 
void InpRelease(int key, int y, int x)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		Up = false;
		break;
	case GLUT_KEY_DOWN:
		Down = false;
		break;
	case GLUT_KEY_LEFT:
		Left = false;
		break;
	case GLUT_KEY_RIGHT:
		Right = false;
		break;
	}
}

//Soltar las teclas
void InpReleaseK(unsigned char key, int y, int x)
{
	switch (key)
	{
	case 'w':
		W = false;
		break;
	case 's':
		S = false;
		break;
	case 'a':
		A = false;
		break;
	case 'd':
		D = false;
		break;
	}
}

void update()
{
	Player1.isCollision(Player2);
	Player2.isCollision(Player1);
	int i;
	for (i = 0; i < 6; i++)
	{
		Player1.Collision(Balls[i]);
		Player2.Collision(Balls[i]);
	}
}

void render()
{
	update();
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(0, 1.0f, -10, //pos
		0, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f);

	time = glutGet(GLUT_ELAPSED_TIME);
	dt = (time - oldTime) / 1000.0f;

	if (Up) Player1.Move(0, 1, dt);
	if (Down) Player1.Move(0, -1, dt);
	if (Left) Player1.Move(-1, 0, dt); 
	if (Right) Player1.Move(1, 0, dt);
	if (W) Player2.Move(0, 1, dt);
	if (S) Player2.Move(0, -1, dt);
	if (D) Player2.Move(1, 0, dt);
	if (A) Player2.Move(-1, 0, dt);

	Player1.Draw();
	Player2.Draw();
	
	for (int i = 0; i < 6; i ++)
	{
		Balls[i].draw(dt);
	}
	oldTime = time;
	glutSwapBuffers();
}

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	for (int i = 0; i < 6; i++)
	{
		Balls[i].setInitVel(.1, .1, 0);
		Balls[i].setPosition(.5, .5, 0);
	}
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	//glutInitWindowSize(1366, 768);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("");
	//myInitialization();
	//OnStart();
	// register callbacks
	glutDisplayFunc(render);
	glutReshapeFunc(changeSize);
	glutIdleFunc(render);
	//Teclas glut
	glutSpecialUpFunc(InpRelease);
	glutSpecialFunc(InputK);
	//Teclas normales
	glutKeyboardFunc(Input);
	glutKeyboardUpFunc(InpReleaseK);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();
}