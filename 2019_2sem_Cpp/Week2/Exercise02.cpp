#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int i=91;

    cout << "i = " << i << " (dec)" << endl;
    cout << "i = " << oct << i << " (oct)" << endl;
    cout << "i = " << hex << i << " (hex)" << endl;
    cout << "i = " << i << " (hex)" << endl;
    cout << "i = " << dec << i << " (dec)" << endl << endl;

    for(int k=1;k<=1000;k*=10)
        cout << setw(6) << k << '\n';
    cout << "\n";

    cout << setw(6);
    for(int k=1;k<=1000;k*=10)
        cout << k << '\n';
    cout << "\n";

    int a = 5, b = 43, c = 104;
    cout << left << setw(10) << "Karen"
        << right << setw(6) << a << '\n';
    cout << left << setw(10) << "Ben"
        << right << setw(6) << b << '\n';
    cout << left << setw(10) << "Prtricia"
        << right << setw(6) << c << '\n';
    cout << "\n";

    float a1 = 1.05, b1 = 10.15, c1 = 200.87;
    cout << setfill('*') << setprecision(2);
    cout << setw(10) << a1 << '\n';
    cout << setw(10) << b1 << '\n';
    cout << setw(10) << c1 << '\n';
    cout << "\n";

    char c2;
    cin >> noskipws;
    while(cin >> c2) cout << c2;

    return 0;
    
}