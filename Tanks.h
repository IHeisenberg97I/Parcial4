#pragma once
#include "Rect.h"
#include "Vector.h"


class Vector1
{
public:

	Vector1(float X, float Y)
	{
		x = X;
		y = Y;
	}
	float x, y;

};

class Tanks
{
public: Tanks();

	  Tanks(float posX, float posY, float sizeX, float sizeY);

	  Tanks(float x, float y, float scale);

	  void Draw();

	  void Move(int DirectionX, int DirectionY, float dt);

	  bool isCollision(Tanks);

	  bool Collision(Ball b);

	  virtual ~Tanks();

	  float m_xPos, m_yPos;

	  float m_size;

private:

	float x, y;
	float speed = 5;
	float scale;
	float m_colorR, m_colorG, m_colorB;

	Tanks* m_base;
	Vector1* m_P1, * m_P2, * m_P3, * m_P4;
	Vector1* m_pos;

};
