#include <fstream>
#include <string>
#include "FileManager.h"
using namespace std;

/*
	문제1: word.txt 파일을 불러와서
	       1. 그대로 새로운 파일에 복사해주는 메소드 구현
		   2. 특정한 문자열이 포함된 줄만 복사해주는 메소드 구현
*/
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