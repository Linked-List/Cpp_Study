#include "Board.h"
#include <iostream>
#include <algorithm>

bool compLen(const std::string& s1, const std::string& s2) {
	return s1.length() > s2.length();
}

Board::Board()
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			data[i][j] = '\0';
	for (int i = 0; i < 20; i++)
		direction[i] = "\0";
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 2; j++)
			location[i][j] = 0;
}

char Board::getSpot(int row, int col)
{
	return data[row][col];
}

void Board::setSpot(char val, int row, int col)
{
	data[row][col] = val;
}

std::string Board::getDir(int i)
{
	return direction[i];
}

void Board::setDir(std::string dir, int i)
{
	direction[i] = dir;
}

int Board::getLoc(int i, int j)
{
	return location[i][j];
}

void Board::setLoc(int val, int i, int j)
{
	location[i][j] = val;
}

void Board::placeList(std::vector<std::string>& list)
{
	std::sort(list.begin(), list.end(), compLen); // 정렬

	std::string temp = list.front();
	int firstIndex = (15 - temp.length()) / 2; // 중앙자리
	for (int i = 0; i < temp.length(); i++)
		setSpot(temp[i], 7, firstIndex + i);
	setDir("Horizontal", 0);
	setLoc(7, 0, 0); // 첫단어 row = 7
	setLoc(firstIndex, 0, 1); // 첫단어 col = firstIndex

	for (int n = 1; n < list.size();n++) {
		std::string t2 = list[n];

		try {
			for (int i = 0; i < 15; i++) { // row
				for (int j = 0; j < 15; j++) { // col
					for (int k = 0; k < t2.length(); k++) {
						if (data[i][j] == t2[k] && (t2.length() - k - 1 <= 15 - i)) { // found vertical
							int p;
							for (p = 0; p < t2.length(); p++) {
								// 1조건 : 놓을 자리 글자가 같거나 없어야 한다.
								// 2조건 : 좌우는 비어있어야함 단, k번째 빼고
								if (!((data[i - k + p][j] == t2[p] || data[i - k + p][j] == '\0') && (p == k || j == 0 || data[i-k+p][j-1] == '\0') && (p == k || j == 14 || data[i-k+p][j+1] == '\0')))
									break; // not found space
							}
							if (p == t2.length()) {
								// found space
								for (int p = 0; p < t2.length(); p++)
									setSpot(t2[p], i - k + p, j);
								setDir("Vertical", n);
								setLoc(i - k, n, 0);
								setLoc(j, n, 1);
								throw std::string("Found") + t2; // 한번에 탈출할 방법
							}
						}
						else if (data[i][j] == t2[k] && (t2.length() - k - 1 <= 15 - j)) { // found horizontal
							int p;
							for (p = 0; p < t2.length(); p++) {
								if (!((data[i][j-k+p] == t2[p] || data[i][j-k+p] == '\0') && (p==k || i == 0 || data[i-1][j-k+p] == '\0') && (p==k || i == 14 || data[i+1][j-k + p] == '\0')))
									break; // not found space
							}

							if (p == t2.length()) {
								// found space
								for (int p = 0; p < t2.length(); p++)
									setSpot(t2[p], i, j - k + p);
								setDir("Horizontal", n);
								setLoc(i, n, 0);
								setLoc(j - k, n, 1);
								throw std::string("Found") + t2; // 한번에 탈출할 방법
							}
						}
					}
				}
			}
		}
		catch (std::string ff) {
			continue;
		}
		setDir("No Space", n);
	}
}

void Board::printBoard()
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (data[i][j] == '\0')
				std::cout << "_ ";
			else
				std::cout << data[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
