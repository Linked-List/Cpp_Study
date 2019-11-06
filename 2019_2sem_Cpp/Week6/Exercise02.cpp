#include <iostream>
#include <string>
using namespace std;

class Base{
    string s;

public:
    Base() : s("Base") {cout << "Base Class" << endl; }
    void what() { cout << s << endl; }
};
class Derived : public Base{
    string s;

public:
    Derived() : s("Derived"), Base() { cout << "Derived Class" << endl; }
    void what() { cout << s << endl; }
};
int main(){
    Base p;
    Derived c;
    Base* p_p = &p;

    Derived* p_c = static_cast<Derived*>(p_p);
    // Derived* p_c = dynamic_cast<Derived*>(p_p);
    // class is Not polymorphic -> virtual 메소드 없음
    p_c->what(); // 어느쪽이든 결국 여기서 에러나와서 프로그램 종료됨
    return 0;
}