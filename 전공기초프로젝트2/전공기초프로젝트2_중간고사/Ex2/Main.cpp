#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Sub.h"
#include "Mul.h"
using namespace std;
int main() {
	int x, y;
	char c;
	
	cout << "두 정수를 입력하시오" << endl;
	cin >> x >> y;

	cout << "사칙연산중 하나를 선택하시오(+,-,*,/)" << endl;
	cin >> c;

	if (c == '+') {
		Add* cl = new Add;
		cl->setValue(x, y);
		cout << "결과 : " << cl->calculate() << endl;
	}
	else if (c == '-') {
		Sub* cl = new Sub;
		cl->setValue(x, y);
		cout << "결과 : " << cl->calculate() << endl;
	}
	else if (c == '*') {
		Mul* cl = new Mul;
		cl->setValue(x, y);
		cout << "결과 : " << cl->calculate() << endl;
	}
	else if (c == '/') {
		Div* cl = new Div;
		cl->setValue(x, y);
		cout << "결과 : " << cl->calculate() << endl;
	}

	system("pause");
	return 0;
}