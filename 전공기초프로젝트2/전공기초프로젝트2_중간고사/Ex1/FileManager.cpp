#include "FileManager.h"

void FileManager::copyFile(ifstream& from, ofstream& to)
{
	string str;
	while (getline(from,str)) {
		to << str << endl;
	}
}

void FileManager::copyFileIfContain(ifstream & from, ofstream & to, string finding)
{
	string str;
	while (getline(from, str)) {
		if (str.find(finding) >= 0 && str.find(finding)<=str.length()-1)
			to << str << endl;
	}
}
