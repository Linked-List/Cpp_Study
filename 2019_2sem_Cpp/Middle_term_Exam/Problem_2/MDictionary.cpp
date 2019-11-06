#include "MDictionary.h"
#include <iostream>

MDictionary::MDictionary() : size(0) {}

ExtEntry *MDictionary::find(std::string key)
{
	for (int i = 0; i < size; i++)
		if (key == extEntries[i].getKey())
			return &extEntries[i];
	std::cout << "[ERROR] key not found" << std::endl;
	return nullptr;
}

ExtEntry **MDictionary::find(char *value)
{
	ExtEntry *temp[100];
	int foundNum = 0;

	for (int i = 0; i < size; i++)
	{
		std::string v = extEntries[i].getValues();
		if (v.find(value) != -1)
			temp[foundNum++] = &extEntries[i];
	}

	if (foundNum == 0)
	{
		std::cout << "[ERROR] value not found" << std::endl;
		return nullptr;
	}
	else
	{
		ExtEntry **foundValue = new ExtEntry *[foundNum];
		for (int i = 0; i < foundNum; i++)
			foundValue[i] = temp[i];
		return foundValue;
	}
}

ExtEntry *MDictionary::insert(std::string key, char *value)
{
	for (int i = 0; i < size; i++)
	{
		if (key == extEntries[i].getKey())
		{
			extEntries[i].addValue(value);
			return &extEntries[i];
		}
	}
	//extEntries[size] = ExtEntry(key, value);
	// 메모리 누수 방지하려고 코드바꿈
	extEntries[size].setKey(key);
	extEntries[size].setValues(value);
	return &extEntries[size++];
}

std::string MDictionary::deletion(std::string key)
{
	for (int i = 0; i < size; i++)
	{
		if (extEntries[i].getKey() == key)
		{
			for (int j = i; j < size - 1; j++)
			{
				extEntries[j].setKey(extEntries[j + 1].getKey());
				extEntries[j].setValue(extEntries[j + 1].getValue());
			}
			size--;
			return key;
		}
	}
	std::cout << "[ERROR] Key not found" << std::endl;
	return std::string();
}
