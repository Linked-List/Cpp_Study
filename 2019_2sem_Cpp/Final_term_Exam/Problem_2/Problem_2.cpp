#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include "Board.h"

using namespace std;

int main()
{
	ifstream in("wordlist.txt");
	if (!in.is_open()) {
		cout << "[ERROR] File Not Found" << endl;
		return 0;
	}
	vector<string> v;
	string temp;
	while (in >> temp)
		v.push_back(temp);

	Board b;
	b.placeList(v);


	cout << "Word List" << endl;
	cout << setw(41) << setfill('-') << ' ' << endl;
	cout << setfill(' ');
	for (vector<string>::iterator i = v.begin(); i != v.end(); i++)
		cout << *i << endl;
	cout << setw(41) << setfill('-') << ' ' << endl;
	cout << setfill(' ');


	cout << "Cross Word Puzzle" << endl;
	b.printBoard();
	cout << setw(41) << setfill('-') << ' ' << endl;
	cout << setfill(' ');
	cout << "Hint" << endl << endl;

	cout << left << setw(15) << "Location" << setw(15) << "Direction" << setw(15) << "Word" << setw(15) << "Anagram" << endl;
	cout << setw(60) << setfill('=') << '=' << endl;
	cout << setfill(' ');
	for (int i = 0; i < v.size(); i++) {
		ostringstream buf;
		string temp = v[i];
		random_shuffle(temp.begin(), temp.end());
		buf << "( " << b.getLoc(i, 0) << ", " << b.getLoc(i, 1) << " )";
		
		cout << setw(15) << buf.str();
		cout << setw(15) << b.getDir(i);
		cout << setw(15) << v[i];
		cout << setw(15) << temp;
		cout << endl;
	}
	cout << setw(60) << setfill('=') << '=' << endl;
	cout << setfill(' ');

	in.close();

	return 0;
}
