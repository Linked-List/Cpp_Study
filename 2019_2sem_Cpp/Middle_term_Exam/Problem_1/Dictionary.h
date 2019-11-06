#pragma once

#include "Entry.h"

class Dictionary {
private:
	Entry entries[100];
	int size;

public:
	Dictionary();
	Entry* find(std::string key); // 없으면 null반환 및 에러띄우기
	Entry** find(char* value); // 없으면 null반환 및 에러띄우기
	Entry* insert(std::string key, char* value); // 없으면 Entry추가, 있으면 에러띄우기
	Entry* modify(std::string key, char* value); // 있으면 뜻 변경, 없으면 에러띄우기
	std::string deletion(std::string key); // 있으면 삭제, 없으면 에러 띄우기
	void printAll();
};