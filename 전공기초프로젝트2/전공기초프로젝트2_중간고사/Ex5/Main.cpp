#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
	문제5: LinkedList를 구현하고, word.txt 파일로부터 글을 읽어서 LinkedList에 Add 해준뒤
		   printAll 메소드를 구현하여 LinkedList가 전부 출력되도록 구현
*/
int main() {
	LinkedList list;
	ifstream ifs;
	ifs.open("word.txt");
	
	list.readFile(ifs);
	list.printAll();


	ifs.close();
	system("pause");
}