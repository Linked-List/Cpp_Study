#include <iostream>
using namespace std;
class C{
    private:
        int num;
    public:
        void set(int n){
            num = n;
        }
        int get(){
            return num;
        }
};
void f(C& c){
    c.set(-999);
}
C& g(){
    static C c;
    c.set(123);
    return c;
}

int main(){
    C c1, c2;
    f(c1);
    cout << c1.get() << endl;
    c2 = g();
    cout << c2.get() << '\n';
    return 0;
}