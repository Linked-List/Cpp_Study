#include <fstream>
#include <string>
#include "FileManager.h"
using namespace std;
int main() {
	ifstream from;
	from.open("word.txt");
	ofstream to;
	to.open("cpyTest.txt");
	ofstream to2;
	to2.open("cpyTest2.txt");

	FileManager f;
	f.copyFile(from, to);
	from.close();

	from.open("word.txt");
	string tofind = "wa";
	f.copyFileIfContain(from, to2, tofind);

	from.close();
	to.close();
	to2.close();
	return 0;
}