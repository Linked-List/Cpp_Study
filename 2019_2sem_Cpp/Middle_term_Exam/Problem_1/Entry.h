#pragma once

#include <string>

class Entry {
private:
	std::string key; // 단어
	char* value; // 의미

public:
	Entry();
	Entry(std::string key, char* value);
	void setKey(std::string key);
	void setValue(char* value);
	std::string getKey();
	char* getValue();
	~Entry(); // 메모리누수 방지용 소멸자
};