#include <iostream>
#include "People.h"
#include "AddressBook.h"
/*
	문제4: People 클래스를 생성하고, 아래 main메소드 실행시 해당 출력형태가 나오도록 구현
	      *이 문제는 꼭 선언부는 .h파일에, 정의부는 .cpp파일에 나누어서 만들어라.
	
	현재 인스턴스 개수 14
	이님이 세상을 떠나셨습니다.
	정님이 세상을 떠나셨습니다.
	현재 인스턴스 개수 12
	계속하려면 아무 키나 누르십시오...
*/
int main() {
	People kim;
	People jang("장");
	People* lee = new People("이");
	People* choi = new People("정", 35);
	People peoples1[10];
	AddressBook addBook1;
	for (int i = 0; i < 10; i++) {
		peoples1[i].setAge(20 + i);
	}

	cout << "현재 인스턴스 개수 " << People::countCreated() << endl;
	delete(lee);
	delete(choi);
	cout << "현재 인스턴스 개수 " << People::countCreated() << endl;

	system("pause");
}