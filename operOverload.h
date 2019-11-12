#include <iostream>

class MyClass{
private:
    int myNum;
    int arr[10];

public:
    MyClass(); // MyClass a; 혹은 new MyClass()로 호출할때 불림

    // 복사생성자
    // =
    MyClass(const MyClass& op);
    void operator=(const MyClass& op);

    // 변환생성자
    // Explicit
    MyClass(int op);
    MyClass(int* op);
    operator int();
    //MyClass 2 type?

    // + - * / %
    // > < == != 
    // && || !는 안하는거 추천
    // += -= *= /= %=
    // ++ --
    MyClass operator+(const MyClass& op); // 결과값이있다.
    bool operator==(const MyClass& op); // 보통 비교연산은 bool반환이죠?
    MyClass& operator+=(const MyClass& op);
    MyClass operator++();
    MyClass operator++(int);

    // []
    // ( )
    int& operator[](const int index);
    int operator[](const int index) const;
    void operator()(int num, int num2, int num3);

    // <<
    // >>
    friend std::ostream& operator<<(std::ostream& out, const MyClass& op);
    friend std::istream& operator>>(std::istream& in, MyClass& op);

// template

// R-value Reference + 이동생성자

};