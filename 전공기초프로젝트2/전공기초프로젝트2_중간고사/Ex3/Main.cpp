#include "ColorPoint.h"
#include <iostream>

int main() {
	ColorPoint cp(10, 20, "RED");
	cp.setPoint(10, 20);
	cp.setColor("Green");
	cp.show();

	system("pause");
	return 0;
}