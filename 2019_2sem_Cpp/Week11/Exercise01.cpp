#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout.width(7);
    cout << -100 << '\n';

    cout.width(7);
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout << -100 << endl;

    cout.width(7);
    cout << -100 << -100 << '\n';

    cout.unsetf(ios_base::left);
    cout.width(7);
    cout << -100 << '\n';

    cout.width(6);
    cout.setf(ios_base::internal, ios_base::adjustfield);
    cout << setfill('0') << -100 << '\n';
    return 0;
}