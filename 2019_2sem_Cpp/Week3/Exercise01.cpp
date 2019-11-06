#include <iostream>
using namespace std;

int main(){
    int i;

    const int* p = new int(10);
    //*p = 20;
    int* q = const_cast<int*>(p);
    *q = 20;

    int int_val = 123;
    float float_val = static_cast<float>(int_val);

    float f = -6.9072;
    int a = 100;

    cout << *p << *q << endl << endl; // p였지만, *p가 문맥상 맞는것같아 수정함
    cout << float_val << endl << endl;

    unsigned char* t = reinterpret_cast<unsigned char*>(&f);
    cout << hex;
    for(int i=0;i<sizeof(float);i++)
        cout << static_cast<int>(t[i]) << "\n";
    return 0;
}