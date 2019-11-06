#include "Entry.h"

Entry::Entry() : key(std::string()), value(nullptr){}

Entry::Entry(std::string key, char * value) : key(key)
{
	int len = std::string(value).length();
	this->value = new char[len + 1];
	for (int i = 0; i <= len; i++)
		this->value[i] = value[i];
}

void Entry::setKey(std::string key)
{
	this->key = key;
}

void Entry::setValue(char * value)
{
	if (this->value != nullptr)
		delete[] this->value;

	int len = std::string(value).length();
	this->value = new char[len + 1];
	for (int i = 0; i <= len; i++)
		this->value[i] = value[i];
}

std::string Entry::getKey()
{
	return key;
}

char * Entry::getValue()
{
	return value;
}

Entry::~Entry()
{
	if(value != nullptr)
		delete[] value;
}
