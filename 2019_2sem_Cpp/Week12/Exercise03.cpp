#include <iostream>
#include <iomanip>
using namespace std;

template<class Typ, class charT, class traits = char_traits<charT>>
struct omanip{
    Typ n;
    void (*f)(basic_ostream<charT,traits>&,Typ);
    omanip(void(*f1)(basic_ostream<charT,traits>&,Typ),Typ n1) :f(f1),n(n1){}
};

template <class charT, class traits, class Typ>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const omanip<Typ,charT>& sman){
    (sman.f)(os,sman.n);
    return os;
}

void bell_ringer(ostream& os, int n){
    for(int i=0;i<n;i++) os << "\a";
}

omanip<int, char> bell(int n){
    return omanip<int, char>(bell_ringer, n);
}

int main(){
    cout << bell(10) << endl;
    return 0;
}