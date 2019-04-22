#pragma once
#include <fstream>
#include <string>
using namespace std;
class FileManager
{
public:
	void copyFile(ifstream& from, ofstream& to);
	void copyFileIfContain(ifstream& from, ofstream& to, string finding);
};

