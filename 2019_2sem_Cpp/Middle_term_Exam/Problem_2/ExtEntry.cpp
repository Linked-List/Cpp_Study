#include "ExtEntry.h"

ExtEntry::ExtEntry() : Entry() {}

ExtEntry::ExtEntry(std::string key, char *value) : Entry(key, value) {}

void ExtEntry::setKey(std::string key)
{
	Entry::setKey(key);
}

void ExtEntry::setValue(char *value)
{
	std::string v = Entry::getValue();
	int c = v.find("//");
	if (c == -1)
		Entry::setValue(value);
	else
	{
		v.replace(0, c, value);
		Entry::setValue(const_cast<char *>(v.c_str()));
	}
}

void ExtEntry::setValues(char *value)
{
	Entry::setValue(value);
}

void ExtEntry::addValue(char *value)
{
	std::string v = Entry::getValue();
	v += "//" + std::string(value);
	Entry::setValue(const_cast<char *>(v.c_str()));
}

std::string ExtEntry::getKey()
{
	return Entry::getKey();
}

char *ExtEntry::getValue()
{
	std::string v = Entry::getValue();
	int c = v.find("//");
	if (c == -1)
		return Entry::getValue();
	else
	{
		v = v.substr(0, c);
		char *result = new char *[c + 1];
		for (int i = 0; i <= c; i++)
			result[i] = v[i];
		return result;
	}
}

char *ExtEntry::getValues()
{
	return Entry::getValue();
}
