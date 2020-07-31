#pragma once
#include "Ball.h"
#include "Vector.h"
#define steps

class Rect
{

public:

	Rect(float, float, float, float);
	void draw();
	bool isCollision(Ball*);
	void resetColor();
	float m_colorR, m_colorG, m_colorB;
	Vector* m_P1, * m_P2, * m_P3, * m_P4;
	Vector* m_pos;

private:



};


