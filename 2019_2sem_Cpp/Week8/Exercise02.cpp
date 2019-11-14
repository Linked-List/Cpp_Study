#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Clock{
public:
    Clock(int = 12, int = 0, int = 0);
    Clock tick();
    friend ostream& operator<<(ostream&, const Clock&);
    Clock operator++(); // ++c
    Clock operator++(int); // c++
private:
    int hour;
    int min;
    int ap;
};

Clock::Clock(int h, int m, int ap_f){
    hour = h; min = m; ap = ap_f;
}
Clock Clock::tick(){
    ++min;
    if(min==60){hour++; min = 0;}
    if(hour==13) hour = 1;
    if(hour==12 && min==0) ap = !ap;
    return *this;
}
Clock Clock::operator++(){
    return tick();
}
Clock Clock::operator++(int){
    Clock c = *this; tick();
    return c;
}
ostream& operator<<(ostream& out, const Clock& c){
    out << setfill('0')<<setw(2)<<c.hour<<':'<<setw(2)<<c.min;
    if(c.ap) out << " PM";
    else out << " AM";
    return out;
}
int main(){
    Clock c, d; // default: 12:00 AM
    c = d++;
    cout << "Clock c: " << c << '\n';
    cout << "Clock d: " << d << '\n';
    return 0;
}
