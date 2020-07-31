#pragma once
#include "Tanks.h"
#include "Rect.h"
#include "Vector.h"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

float x, y;
/*Tanks::Tanks() //Variables fijo
{
	x = 0;
	y = 0;
	scale = 5;
}*/

Tanks::Tanks() 
{
	m_P1 = new Vector1(0, 0);
	m_P2 = new Vector1(0, 0);
	m_P3 = new Vector1(0, 0);
	m_P4 = new Vector1(0, 0);

	m_pos = new Vector1(0, 0);
}

Tanks::Tanks(float posX, float posY, float sizeX, float sizeY)
{
	m_P1 = new Vector1(-sizeX / 2, sizeY / 2);
	m_P2 = new Vector1(sizeX / 2, sizeY / 2);
	m_P3 = new Vector1(sizeX / 2, -sizeY / 2);
	m_P4 = new Vector1(-sizeX / 2, -sizeY / 2);

	m_pos = new Vector1(posX, posY);
	//m_colorG = 1;
}

Tanks::Tanks(float _x, float _y, float _scale)  //Variables cambian
{
	m_base = new Tanks(_x, _y, scale, scale);
	m_base->m_colorB = 1;
	m_base->m_colorG = 1;
	m_base->m_colorR = 1;
	m_xPos = _x;
	m_yPos = _y;
	scale = _scale;
	m_P1 = new Vector1(m_xPos - .5 / 2, m_yPos + .5 / 2);
	m_P2 = new Vector1(m_xPos + .5 / 2, m_yPos + .5 / 2);
	m_P3 = new Vector1(m_xPos + .5 / 2, m_yPos - .5 / 2);
	m_P4 = new Vector1(m_xPos - .5 / 2, m_yPos - .5 / 2);
}

void Tanks::Draw() //Dibuja
{
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glColor3f(1, 0, 0);
	glTranslatef(m_xPos, m_yPos, 0);
	glScalef(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.5f, 0);
	glVertex3f(-0.5f, 0.5f, 0);
	glVertex3f(-0.5f, -0.5f, 0);
	glVertex3f(0.5f, -0.5f, 0);
	glEnd();
	glPopMatrix();
}

void Tanks::Move (int DirectionX, int DirectionY, float dt)
{
	float Increase = speed * dt;
	if (DirectionY > 0) //Arriba 
	{
		if (true)
		{
			m_yPos += Increase;
			m_P1 = new Vector1(m_xPos - .5 / 2, m_yPos + .5 / 2);
			m_P2 = new Vector1(m_xPos + .5 / 2, m_yPos + .5 / 2);
			m_P3 = new Vector1(m_xPos + .5 / 2, m_yPos - .5 / 2);
			m_P4 = new Vector1(m_xPos - .5 / 2, m_yPos - .5 / 2);
		}
	}

	if (DirectionY < 0) //Abajo
	{
		if (true) //Checa que se cumpla el limite
		{
			m_yPos -= Increase;
			m_P1 = new Vector1(m_xPos - .5 / 2, m_yPos + .5 / 2);
			m_P2 = new Vector1(m_xPos + .5 / 2, m_yPos + .5 / 2);
			m_P3 = new Vector1(m_xPos + .5 / 2, m_yPos - .5 / 2);
			m_P4 = new Vector1(m_xPos - .5 / 2, m_yPos - .5 / 2);
		}
	}

	if (DirectionX > 0) //Arriba 
	{
		if (true)
		{
			m_xPos -= Increase;
			m_P1 = new Vector1(m_xPos - .5 / 2, m_yPos + .5 / 2);
			m_P2 = new Vector1(m_xPos + .5 / 2, m_yPos + .5 / 2);
			m_P3 = new Vector1(m_xPos + .5 / 2, m_yPos - .5 / 2);
			m_P4 = new Vector1(m_xPos - .5 / 2, m_yPos - .5 / 2);
		}
	}

	if (DirectionX < 0) //Abajo
	{
		if (true)
		{
			m_xPos += Increase;
			m_P1 = new Vector1(m_xPos - .5 / 2, m_yPos + .5 / 2);
			m_P2 = new Vector1(m_xPos + .5 / 2, m_yPos + .5 / 2);
			m_P3 = new Vector1(m_xPos + .5 / 2, m_yPos - .5 / 2);
			m_P4 = new Vector1(m_xPos - .5 / 2, m_yPos - .5 / 2);
		}
	}
}

bool Tanks::isCollision(Tanks b)
{
	bool xColl = (b.m_xPos > m_P1->x - b.m_size) && (b.m_xPos < m_P3->x + b.m_size);
	bool yColl = (b.m_yPos < m_P1->y + b.m_size) && (b.m_yPos > m_P3->y - b.m_size);
	bool collision = xColl && yColl;

	if (collision)
	{
		std::cout << "Hola" << std::endl;
	}

	return collision;
}

bool Tanks::Collision(Ball b)
{
	bool xColl = (b.m_xPos > m_P1->x - b.m_size) && (b.m_xPos < m_P3->x + b.m_size);
	bool yColl = (b.m_yPos < m_P1->y + b.m_size) && (b.m_yPos > m_P3->y - b.m_size);
	bool collision = xColl && yColl;

	if (collision)
	{
		std::cout << "B" << std::endl;
	}

	return collision;
}

Tanks::~Tanks()
{

}