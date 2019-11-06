#include <iostream>
#include <string>
#include <fstream>
#include "Dictionary.h"

using namespace std;

int main()
{
	Dictionary dic;
	ifstream in("dictionary.txt");

	if (!in.is_open())
	{
		cout << "[ERROR] File Not Found" << endl;
		return 0;
	}

	std::string line;
	while (getline(in, line))
	{
		int c = line.find(':');
		dic.insert(line.substr(0, c), const_cast<char *>(line.substr(c + 1).c_str()));
	}
	//dic.printAll();

	Entry *tmp = nullptr;

	cout << "Find key \'Apple\'" << endl;
	tmp = dic.find(string("Apple"));
	cout << tmp->getKey() << " : " << tmp->getValue() << endl;

	cout << endl;

	cout << "1. Modify \'Apple\' meaning and 2. Find againg key \'Apple\'" << endl;
	dic.modify("Apple", const_cast<char *>("A multimedia corporation and record company founded by the Beatles"));
	tmp = dic.find(string("Apple"));
	cout << tmp->getKey() << " : " << tmp->getValue() << endl;

	cout << endl;

	cout << "Find key \'Orange\'" << endl;
	tmp = dic.find(string("Orange"));
	cout << tmp->getKey() << " : " << tmp->getValue() << endl;
	cout << "1. Delete \'Orange\' and 2. Find again key \'Orange\'" << endl;
	cout << dic.deletion(string("Orange")) << endl;
	tmp = dic.find(string("Orange"));
	return 0;
}