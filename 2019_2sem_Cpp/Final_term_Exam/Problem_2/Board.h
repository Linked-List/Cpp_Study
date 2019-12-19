#pragma once

#include <string>
#include <vector>

class Board {
private:
	char data[15][15];
	std::string direction[20];
	int location[20][2];

public:
	Board();
	char getSpot(int row, int col);
	void setSpot(char val, int row, int col);
	std::string getDir(int i);
	void setDir(std::string dir, int i);
	int getLoc(int i, int j);
	void setLoc(int val, int i, int j);
	void placeList(std::vector<std::string>& list);
	void printBoard();
};