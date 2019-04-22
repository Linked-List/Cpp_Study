#include "People.h"

int People::created = 0;

People::People() : People("",0)
{

}

People::People(string name) : People(name,0)
{
}

People::People(string name, int age) : name(name), age(age)
{
	created++;
}


People::~People()
{
	if(name.length()!=0){
		cout << name << "님이 세상을 떠나셨습니다." << endl;
	}
	created--;
}

void People::setAge(int age)
{
	this->age = age;
}

int People::countCreated()
{
	return created;
}
