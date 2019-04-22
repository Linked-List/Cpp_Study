#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	LinkedList list;
	ifstream ifs;
	ifs.open("word.txt");
	
	list.readFile(ifs);
	list.printAll();


	ifs.close();
	system("pause");
}