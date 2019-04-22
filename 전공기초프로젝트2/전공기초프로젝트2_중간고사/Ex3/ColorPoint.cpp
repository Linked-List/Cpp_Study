#include "ColorPoint.h"


ColorPoint::ColorPoint(int x, int y, string color)
{
	setX(x);
	setY(y);
	this->color = color;
}

ColorPoint::~ColorPoint()
{
}

void ColorPoint::setPoint(int x, int y)
{
	setX(x);
	setY(y);
}

void ColorPoint::setColor(string color)
{
	this->color = color;
}

void ColorPoint::show()
{
	cout << "(" << getX() << "," << getY() << "). Color: " << color << endl;
}
