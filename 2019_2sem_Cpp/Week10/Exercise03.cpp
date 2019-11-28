#include <iostream>
using namespace std;

void showWidth(){
    cout.width(10);
    cout << "Hello" << endl;

    cout.width(5);
    cout << 12 << endl;

    cout << '%';
    cout.width(10);
    cout << "Korea/" << "Seoul" << "City" << endl;
}

int main(){
    showWidth();
    cout << endl;

    cout.fill('-');
    showWidth();
    cout << endl;

    cout.precision(5);
    cout << 11. / 3. << endl;

    return 0;
}