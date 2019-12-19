#include <iostream>
#include <fstream>
#include "myManip.h"

using namespace std;

int main()
{
	ifstream in("score.txt");
	if (!in.is_open()) {
		cout << "[ERROR] File Not Found" << endl;
		return 0;
	}

	string hdr1[6];
	int** val;
	val = new int* [10];
	for (int i = 0; i < 10; i++)
		val[i] = new int[6];
	
	for (int i = 0; i < 6; i++)
		in >> hdr1[i];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 6; j++)
			in >> val[i][j];

	string hdr2[10] = { "no 1","no 2","no 3","no 4","no 5","no 6","no 7","no 8","no 9", "no 10" };
	string hdr3[5] = { "math", "eng", "phy", "chem", "hist" };

	cout << "Score table: " << endl << ptab(hdr1, val, 0, 0, 9, 5) << endl;
	cout << "Average per student:" << endl << prave(hdr2, val, 0, 1, 9, 5) << endl;
	cout << "Average per subject:" << endl << pcave(hdr3, val, 0, 1, 9, 5) << endl;


	for (int i = 0; i < 10; i++)
		delete[] val[i];
	delete[] val;

	in.close();
}