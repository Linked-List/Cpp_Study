#include <iostream>
#include "People.h"
#include "AddressBook.h"

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