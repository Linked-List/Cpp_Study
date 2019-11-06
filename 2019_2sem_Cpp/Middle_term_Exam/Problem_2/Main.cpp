#include <iostream>
#include <string>
#include <fstream>
#include "MDictionary.h"

using namespace std;

int main() {
	MDictionary dic;
	ifstream in("dictionary2.txt");

	if (!in.is_open()) {
		cout << "[ERROR] File Not Found" << endl;
		return 0;
	}

	std::string line;
	while (getline(in, line)) {
		int c = line.find(':');
		dic.insert(line.substr(0, c), const_cast<char*>(line.substr(c + 1).c_str()));
	}


	ExtEntry* tmp = nullptr;
	ExtEntry** tmp2 = nullptr;

	cout << "Find key \'Apple\'" << endl;
	tmp = dic.find("Apple");
	cout << tmp->getKey() << " : " << tmp->getValues() << endl;
	
	cout << "Find value \'speaker\'" << endl;
	tmp2 = dic.find(const_cast<char*>("speaker"));
	cout << tmp2[0]->getKey() << " : " << tmp2[0]->getValues() << endl;
	cout << tmp2[1]->getKey() << " : " << tmp2[1]->getValues() << endl;
	delete[] tmp2;

	cout << endl;

	cout << "Find \'trot\'" << endl;
	tmp = dic.find("trot");
	cout << tmp->getKey() << " : " << tmp->getValues() << endl;

	cout << endl;

	cout << "Insert and Find again \'trot\'" << endl;
	dic.insert("trot", const_cast<char*>("If something happens several times on the trot, it happens that number of times without a break."));
	tmp = dic.find("trot");
	cout << tmp->getKey() << " : " << tmp->getValues() << endl;

	return 0;
}