#include <iostream>
#include <iomanip>
#include "myManip.h"

myManip::myManip(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2, int op) : hdr_str(hdr_str), val_array(val_array), row1(row1), col1(col1), row2(row2), col2(col2), myOptions(op)
{}

std::ostream& operator<<(std::ostream& out, myManip p){
	if (p.myOptions == 1) {
		int space = 5 + (p.col2 * 6);
		out << std::setw(space) << std::setfill('-') << ' ' << std::endl;
		out << std::setfill(' ') << std::setw(4) << p.hdr_str[0];
		for (int i = 1; i <= p.col2 - p.col1; i++)
			out << std::setw(6) << p.hdr_str[i];
		out << std::endl;
		out << std::setw(space) << std::setfill('=') << ' ' << std::endl;
		out << std::setfill(' ');
		for (int i = p.row1; i <= p.row2; i++) {
			out << std::setw(4) << p.val_array[i][p.col1];
			for (int j = p.col1 + 1; j <= p.col2; j++)
				out << std::setw(6) << p.val_array[i][j];
			out << std::endl;
		}
		out << std::setw(space) << std::setfill('-') << ' ';
		out << std::setfill(' ');
	}
	else if (p.myOptions == 2) {
		int space = 6 * (p.row2 - p.row1+1)+1;
		out << std::setfill('-') << std::setw(space) << ' ' << std::endl;
		out << std::setfill(' ');
		for (int i = p.row1; i <= p.row2; i++) {
			out << std::setw(6) << p.hdr_str[i];
		}
		out << std::endl;
		out << std::setfill('=') << std::setw(space) << ' ' << std::endl;
		out << std::setfill(' ');
		for (int i = p.row1; i <= p.row2; i++) {
			int sum = 0;
			for (int j = p.col1; j <= p.col2; j++) {
				sum += p.val_array[i][j];
			}
			out << std::setw(6) << sum / (p.col2 - p.col1 + 1);
		}
		out << std::endl;
		out << std::setfill('-') << std::setw(space) << ' ';
		out << std::setfill(' ');
	}
	else {
		int space = 6 * (p.col2 - p.col1 + 1) + 1;
		out << std::setfill('-') << std::setw(space) << ' ' << std::endl;
		out << std::setfill(' ');

		for (int i = p.col1 - 1; i < p.col2; i++)
			out << std::setw(6) << p.hdr_str[i];
		out << std::endl;
		out << std::setfill('=') << std::setw(space) << ' ' << std::endl;
		out << std::setfill(' ');
		for (int i = p.col1; i <= p.col2; i++) {
			int sum = 0;
			for (int j = p.row1; j <= p.row2; j++) {
				sum += p.val_array[j][i];
			}
			out << std::setw(6) << sum/(p.row2 - p.row1 + 1);
		}
		out << std::endl;
		out << std::setfill('-') << std::setw(space) << ' ';
		out << std::setfill(' ');
	}
	return out;
}

myManip ptab(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2) {
	return myManip(hdr_str, val_array, row1, col1, row2, col2, 1);
}

myManip prave(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2) {
	return myManip(hdr_str, val_array, row1, col1, row2, col2, 2);
}

myManip pcave(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2) {
	return myManip(hdr_str, val_array, row1, col1, row2, col2, 3);
}