#include "Dictionary.h"
#include <iostream>
Dictionary::Dictionary() : size(0) {}

Entry *Dictionary::find(std::string key)
{
	for (int i = 0; i < size; i++)
		if (key == entries[i].getKey())
			return &entries[i];
	std::cout << "[ERROR] key not found" << std::endl;
	return nullptr;
}

Entry **Dictionary::find(char *value)
{
	Entry *temp[100];
	int foundNum = 0;

	for (int i = 0; i < size; i++)
	{
		std::string v = entries[i].getValue();
		if (v.find(value) != -1)
			temp[foundNum++] = &entries[i];
	}

	if (foundNum == 0)
	{
		std::cout << "[ERROR] value not found" << std::endl;
		return nullptr;
	}
	else
	{
		Entry **foundValue = new Entry *[foundNum];
		for (int i = 0; i < foundNum; i++)
			foundValue[i] = temp[i];
		return foundValue;
	}
}

Entry *Dictionary::insert(std::string key, char *value)
{
	for (int i = 0; i < size; i++)
	{
		if (key == entries[i].getKey())
		{
			std::cout << "[ERROR] Already Exist" << std::endl;
			return nullptr;
		}
	}
	//entries[size] = Entry(key, value);
	// 메모리 누수 방지용으로 코드 변경
	entries[size].setKey(key);
	entries[size].setValue(value);
	return &entries[size++];
}

Entry *Dictionary::modify(std::string key, char *value)
{
	for (int i = 0; i < size; i++)
	{
		if (entries[i].getKey() == key)
		{
			entries[i].setValue(value);
			return &entries[i];
		}
	}
	std::cout << "[ERROR] No key found" << std::endl;
	return nullptr;
}

std::string Dictionary::deletion(std::string key)
{
	for (int i = 0; i < size; i++)
	{
		if (entries[i].getKey() == key)
		{
			for (int j = i; j < size - 1; j++)
			{
				entries[j].setKey(entries[j + 1].getKey());
				entries[j].setValue(entries[j + 1].getValue());
			}
			size--;
			return key;
		}
	}
	std::cout << "[ERROR] Key not found" << std::endl;
	return std::string();
}

void Dictionary::printAll()
{
	for (int i = 0; i < size; i++)
		std::cout << entries[i].getKey() << " : " << entries[i].getValue() << std::endl;
}
