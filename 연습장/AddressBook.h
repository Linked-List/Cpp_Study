#include <iostream>

class AddressBook{
    private:
    float average;

    public:
    float setAverage(People *people,int num){
        int sum=0;
        for(int i=0;i<num;i++){
            sum += people[i].getAge();
        }
        this->average = ((float)sum/num);
        return this->average;
    }
};