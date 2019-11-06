#include <iostream>
#include <string>

using namespace std;

class BC1{
    int x;
public:
    void set_x(float a){x = a;}
};

class BC2{
    int x;
public:
    void set_x(char a){x = a;}
};

class DC : public BC1, public BC2{
    int x;
public:
    void set_x(int a){x = a;}
};
void tester(){
    DC d1;
    d1.set_x(137);
    d1.BC1::set_x(1.23);
    d1.BC2::set_x('c');
}
int main(){
    tester();
    return 0;
}