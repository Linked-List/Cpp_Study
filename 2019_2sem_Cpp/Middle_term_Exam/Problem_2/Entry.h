#pragma once

#include <string>

class Entry {
private:
	std::string key; // 단어뜻
	char* value; // 의미

public:
	Entry();
	Entry(std::string key, char* value);
	void setKey(std::string key);
	void setValue(char* value);
	std::string getKey();
	char* getValue();
	~Entry(); // 메모리 누수 해결용 소멸자
};