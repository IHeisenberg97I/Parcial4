#include "Rect.h"
#include <GL\freeglut.h>

Rect::Rect(float posX, float posY, float sizeX, float sizeY) 
{
	m_P1 = new Vector(-sizeX / 2, sizeY / 2);
	m_P2 = new Vector(sizeX / 2, sizeY / 2);
	m_P3 = new Vector(sizeX / 2, -sizeY / 2);
	m_P4 = new Vector(-sizeX / 2, -sizeY / 2);

	m_pos = new Vector(posX, posY);
	m_colorG = 1;
}

void Rect::draw()
{
	glPushMatrix();
	glTranslatef(m_pos->x, m_pos->y, 0);
	glBegin(GL_LINE_LOOP);
	glColor3f(m_colorR, m_colorG, m_colorB);

	glVertex2f(m_P1->x, m_P1->y);
	glVertex2f(m_P2->x, m_P2->y);
	glVertex2f(m_P3->x, m_P3->y);
	glVertex2f(m_P4->x, m_P4->y);

	glEnd();
	glPopMatrix();
}

bool Rect::isCollision(Ball* b) 
{
	bool xColl = (b->m_xPos > m_P1->x - b->m_size) && (b->m_xPos < m_P3->x + b->m_size);
	bool yColl = (b->m_yPos < m_P1->y + b->m_size) && (b->m_yPos > m_P3->y - b->m_size);
	bool collision = xColl && yColl;

	if (collision) 
	{
		m_colorG = 0;
		m_colorR = 1;
		b->m_colorR = 0.89f;
		b->m_colorG = 0.0f;
		b->m_colorB = 0.486f;
	}

	return collision;
}

void Rect::resetColor() 
{
	m_colorG = 1;
	m_colorR = 0;
}