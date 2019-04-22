#pragma once
#include "Point.h"
#include <string>
#include <iostream>
using namespace std;

class ColorPoint :
	public Point
{
private:
	string color;
public:
	ColorPoint(int x, int y, string color);
	~ColorPoint();
	void setPoint(int x, int y);
	void setColor(string color);
	void show();
};

