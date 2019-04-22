#pragma once
#include <iostream>
#include <string>
using namespace std;

class People
{
private:
	static int created;
	int age;
	string name;

public:
	People();
	People(string name);
	People(string name, int age);
	~People();
	void setAge(int age);
	static int countCreated();
	int getAge() {
		return age;
	}
};

