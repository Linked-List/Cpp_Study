#pragma once

#include "Entry.h"

class ExtEntry : public Entry{
public:
	ExtEntry();
	ExtEntry(std::string key, char* value);
	void setKey(std::string key);
	void setValue(char* value); // 순서상 첫번째 뜻 변경 (구분은 //로한다)
	void setValues(char* value); // 전체 뜻 변경
	void addValue(char* value); // 뜻 추가
	std::string getKey();
	char* getValue(); // 순서상 첫번째 뜻 반환
	char* getValues(); // 전체 뜻 반환
};