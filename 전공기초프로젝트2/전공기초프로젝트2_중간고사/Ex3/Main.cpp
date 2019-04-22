#include "ColorPoint.h"
#include <iostream>

/*
	문제3: Point라는 클래스를 만들고, 그것을 상속받는 ColorPoint 클래스를 생성하여
	      해당 main함수가 정상 작동하도록 구현
*/
int main() {
	ColorPoint cp(10, 20, "RED");
	cp.setPoint(10, 20);
	cp.setColor("Green");
	cp.show(); // 출력형태 자유

	system("pause");
	return 0;
}