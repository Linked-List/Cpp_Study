#pragma once

#include "ExtEntry.h"

class MDictionary {
private:
	ExtEntry extEntries[100];
	int size;

public:
	MDictionary();
	ExtEntry* find(std::string key); // 없으면 null반환 및 에러띄우기
	ExtEntry** find(char* value); // 없으면 null반환 및 에러띄우기
	ExtEntry*insert(std::string key, char* value); // key가 존재하지 않으면 Entry추가 있으면, 뜻 추가
	std::string deletion(std::string key); // 없으면 에러띄우기
};
