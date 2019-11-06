#include <iostream>
#include "MyString.h"
using namespace std;

int main() {
    MyString str1("I love this long long string");
    MyString str2("<some string inserted between>");
    MyString str3(str1);
    str1.reserve(30);
    cout << "str1" << endl;
    cout << "Capacity : " << str1.capacity() << endl;
    cout << "String length : " << str1.length() << endl;
    cout << "5th charactor : " << str1.at(5) << endl;
    str1.println();
    cout << endl;

    cout << "str2" << endl;
    cout << "str2" << endl;
    cout << "Capacity : " << str2.capacity() << endl;
    cout << "String length : " << str2.length() << endl;
    cout << "5th charactor : " << str2.at(5) << endl;
    str2.println();
    cout << endl;

    str1.insert(5, str2);
    str1.erase(0, 3);
    cout << "after insertion and erasure" << endl;
    cout << "Capacity : " << str1.capacity() << endl;
    cout << "String length : " << str1.length() << endl;
    str1.println();
    cout << endl;
    
    cout << "copy constructor str3" << endl;
    cout << "Capacity : " << str3.capacity() << endl;
    cout << "String length : " << str3.length() << endl;
    str3.println();
    cout << endl;

    MyString str4;
    str4.setString("this is a very very long string");
    str4.println();
    cout << "find a word <very> in str4" << endl;
    cout << "find 1th <very> in the str4 : "
        << str4.find(0, "very") << endl;
    cout << "find 2th <very> in the str4 : "
        << str4.find(str4.find(0, "very") + 1, "very") << endl;

    return 0;
}