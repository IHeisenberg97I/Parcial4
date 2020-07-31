#pragma once
#include <cmath>
class Vector
{
public:
	Vector() {}
	;
	Vector(float X, float Y) 
	{
		x = X;
		y = Y;
	}
	float x, y;

private:
};

inline Vector rotateAroundPt(float angle, Vector* point, Vector* root)
{
	float theta = angle;

	float xf, yf;

	// update theta anticlockwise rotation 

	// check overflow 
	if (theta >= (2.0 * 3.14159))
		theta = theta - (2.0 * 3.14159);

	// actual calculations.. 
	xf = root->x + ((float)(point->x - root->x) * cos(theta))
		- ((float)(point->y - root->y) * sin(theta));
	yf = root->y + ((float)(point->x - root->x) * sin(theta))
		+ ((float)(point->y - root->y) * cos(theta));

	// drawing the centre point 

	// drawing the rotating point 
	//drawPoint(root->x, root->y, xf, yf);

	// creating a delay 
	// so that the point can be noticed 
	return (Vector(xf, yf));
}

inline bool equalFloat(float A, float B, float limit = 0.01f) 
{
	return (fabs(A - B) < limit);
}