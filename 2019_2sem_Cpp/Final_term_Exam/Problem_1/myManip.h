#pragma once

#include <string>

class myManip {
private:
	int myOptions; // 1=PTAB, 2=PRAVE, 3=PCAVE
	std::string* hdr_str;
	int** val_array;
	int row1;
	int row2;
	int col1;
	int col2;

public:
	myManip(std::string*, int**, int, int, int, int, int);
	friend std::ostream& operator<<(std::ostream&, myManip);
};

myManip ptab(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2);

myManip prave(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2);

myManip pcave(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2);