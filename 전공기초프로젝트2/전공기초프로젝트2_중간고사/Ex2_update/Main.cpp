#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Sub.h"
#include "Mul.h"
using namespace std;
/*
	문제2: Calc라는 클래스를 생성한 뒤.
	       Calc를 상속받는 클래스4개 Add, Sub, Mul, Div를 생성하고
		   각각 클래스에 맞는 calculate() 메소드를 구현하라.
		   이후 Main함수에서 사칙연산에 맞춰서 클래스를 동적할당 하고
		   결과값을 출력해라.
*/
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
		delete cl;
	}

	system("pause");
	return 0;
}