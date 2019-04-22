#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Sub.h"
#include "Mul.h"
using namespace std;
int main() {
	int x, y;
	char c;
	Calc* cl = nullptr;
	
	cout << "두 정수를 입력하시오" << endl;
	cin >> x >> y;

	cout << "사칙연산중 하나를 선택하시오(+,-,*,/)" << endl;
	cin >> c;

	switch(c){
	case '+':
		cl = new Add;
		break;
	case '-':
		cl = new Div;
		break;
	case '*':
		cl = new Mul;
		break;
	case '/':
		cl = new Div;
	}

	if(cl != nullptr){
		cl->setValue(x, y);
			cout << "결과 : " << cl->calculate() << endl;
	}

	system("pause");
	return 0;
}