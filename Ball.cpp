#include "Ball.h"
#include <GL\freeglut.h>
#include <cmath>
#include <iostream>

#define steps 30
#define PI 3.14159264f
#define PI2 3.14159264f*2



Ball::Ball()
{
	int x = 0;
	int y = 0;
}

Ball::Ball(float size)
{
	this->m_size = size;
	std::cout << "we are ethernally gratefull" << std::endl;
	float smallStep = PI2 / steps;
	int s = 0;
	for (float i = -PI; i < PI; i += smallStep, s++) 
	{
		m_objX[s] = cos(i) * m_size;
		m_objY[s] = sin(i) * m_size;
	}
}

void Ball::restart()
{
	m_xPos = m_xPosInit;
	m_yPos = m_yPosInit;

	m_xVel = m_xInitVel;
	m_yVel = m_yInitVel;

	m_colorR = 0.0f;
	m_colorG = 1.0f;
	m_colorB = 0.0f;
}

void Ball::setInitVel(float x, float y, float z) 
{
	m_xInitVel = x;
	m_yInitVel = y;
}

void Ball::setPosition(float x, float y, float z) 
{
	m_xPosInit = x;
	m_yPosInit = y;
	restart();
}

void Ball::setGravity(float g) 
{
	m_gravity = g;
}

void Ball::update(float dt) 
{
	m_xVel *= 0.999f;
	m_yVel *= 0.999f;

	m_xPos += m_xVel * dt;
	m_yPos += m_yVel * dt;
	//Using Gravity
	/*
	if (m_yPos> 0) {
		m_yVel += m_gravity * dt;
		m_yPos += m_yVel * dt;
	}
	else {
		m_yPos = 0;
	}
	*/
}

bool Ball::isCollision(Ball* ex_ball) 
{
	//float distance = sqrtf(((ex_ball->m_xPos - m_xPos) * (ex_ball->m_xPos - m_xPos)) + ((ex_ball->m_yPos - m_yPos) * (ex_ball->m_yPos - m_yPos)));
	int deltaX = ex_ball->m_xPos - m_xPos;
	int deltaY = ex_ball->m_yPos - m_yPos;
	float distance = deltaX * deltaX + deltaY * deltaY;
	float sz = m_size + ex_ball->m_size;

	bool collision = distance < sz;
	if (collision) 
	{
		m_colorR = 1.0f;
		m_colorG = 0.0f;
		m_colorB = 0.0f;
		std::cout << "B" << std::endl;
	}
	//std::cout << "Collision: " << distance << " size: " << sz  << std::endl;
	return collision;
}

void Ball::resetColor() 
{
	m_colorG = 1;
	m_colorR = 0;
}

void Ball::draw(float dt) 
{
	/*glPushMatrix();
	glTranslatef(m_xPos, m_yPos, 0);
	glColor3f(0, 1, 0);
	glBegin(GL_LINE_LOOP);
	glColor3f(m_colorR, m_colorG, m_colorB);
	for (int i = 0; i < steps; i++)
		glVertex3f(m_objX[i], m_objY[i], 0);
	glEnd();
	glPopMatrix();
	*/
	m_xPos += m_xVel * dt;
	m_yPos += m_yVel * dt;

	if (m_xPos > 1 - m_size || m_xPos < -1 + m_size)
	{
		m_xVel *= -1;
		m_xPos = (m_xPos > 0) ? 1 - m_size : -1 + m_size;
	}

	if (m_yPos > 1 - m_size || m_yPos < -1 + m_size)
	{
		m_yVel *= -1;
		m_yPos = (m_yPos > 0) ? 1 - m_size : -1 + m_size;
	}

	float x, y;
	glPushMatrix();
	glTranslatef(m_xPos, m_yPos, 0.0f);
	//changeShape();
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	for (float x_val = -PI; x_val < PI; x_val += PI2 / 30) 
	{
		x = cos(x_val);
		y = sin(x_val);
		glVertex2f((x * m_size), (y * m_size));
	}
	glEnd();
	glPopMatrix();

}