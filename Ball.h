
#pragma once
#define steps 30
class Ball 
{

public:
	Ball();
	Ball(float);
	void update(float);
	void draw(float dt);

	void setGravity(float);
	void setPosition(float, float, float);
	void setInitVel(float, float, float);
	void resetColor();
	bool isCollision(float, float, float);
	bool isCollision(Ball*);
	void restart();
	float m_size;
	float m_xPos, m_yPos;
	float m_colorR, m_colorG, m_colorB;

private:

	float m_objX[steps], m_objY[steps];
	float m_xPosInit, m_yPosInit;
	float m_xVel, m_yVel;
	float m_xInitVel, m_yInitVel;
	float m_gravity;

};