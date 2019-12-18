#pragma once

#include <iostream>

#define MAX_FRAME_SIZE 20

class MyClass2
{
public:
    int myNum;
};

class MyClass
{
private:
    int myNum;
    int arr[10];

public:
    MyClass()
    {
        std::cout << "기본생성자 호출" << std::endl;
        myNum = 0;
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    } // MyClass a; 혹은 new MyClass()로 호출할때 불림

    // 복사생성자
    MyClass(const MyClass &op)
    {
        std::cout << "복사생성자 호출" << std::endl;
        myNum = op.myNum;
        for (int i = 0; i < 10; i++)
            arr[i] = op.arr[i];
    }
    // = 연산자
    void operator=(const MyClass &op)
    {
        std::cout << "=연산자 호출" << std::endl;
        myNum = op.myNum;
        for (int i = 0; i < 10; i++)
            arr[i] = op.arr[i];
    }

    // 변환생성자
    // Explicit
    MyClass(const int &op)
    {
        std::cout << "int 타입생성자 혹은 변환생성자 호출" << std::endl;
        myNum = op;
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    }
    MyClass(const MyClass2 &op)
    {
        std::cout << "MyClass2 타입생성자 혹은 변환생성자 호출" << std::endl;
        myNum = op.myNum;
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    }
    // 변환연산자 - 왜 리턴타입이 없을까? 리턴타입이 함수이름이자너
    // 여기또한 explicit 선언가능
    operator int()
    {
        std::cout << "(int) 변환연산자 호출" << std::endl;
        return myNum;
    }
    operator MyClass2()
    {
        std::cout << "(MyClass2) 변환연산자 호출" << std::endl;
        MyClass2 a;
        a.myNum = this->myNum;
        return a;
    }

    // + - * / %
    // 왼쪽 놈이 함수 operator+를 호출하고, 매개변수로 오른쪽놈이 들어감.
    MyClass operator+(const MyClass &op)
    {
        MyClass t;
        t.myNum = myNum + op.myNum;
        std::cout << "operator+ 호출" << std::endl;
        return t;
    }
    // > < == != <= >=
    // && || !는 안하는거 추천
    // 사용방식은 위와 똑같은데, 보통 반환형이 bool이라서 그냥 나눠봤다.
    bool operator<(const MyClass &op)
    {
        std::cout << "operator< 호출" << std::endl;
        return myNum < op.myNum;
    }

    // += -= *= /= %=
    // 일단 사칙연산과의 차이점으로는, 함수 호출하는 애의 값 자체를 바꾼다.
    // =관련 연산자는 void로 해도되고 MyClass&로 해도된다.
    // 전후의 차이는 a = (b = c) 같은것이 가능하냐 이다(void는 안됨).
    MyClass &operator+=(const MyClass &op)
    {
        std::cout << "operator+= 호출" << std::endl;
        myNum += op.myNum;
        for (int i = 0; i < 10; i++)
            arr[i] += op.arr[i];
        return *(this);
    }

    // ++ --
    // (int)부분은 의미가 있는 타입이 아니라, 그냥 문법이다. 헷갈리지 말기
    MyClass &operator++()
    {
        std::cout << "전위연산++ 호출" << std::endl;
        myNum++;
        return *(this);
    }
    const MyClass operator++(int)
    {
        std::cout << "후위연산++ 호출" << std::endl;
        MyClass a = *this; // 나를 기준으로 임시객체 만들어놓고.
        myNum++;
        // 원래껀 올리고 임시객체를 반환한다.
        return a;
    } // 추가 연산못하게 const선언

    // []
    int &operator[](const int index)
    {
        std::cout << "일반변수로 []호출" << std::endl;
        return arr[index];
    }
    const int operator[](const int index) const
    { // 뒤에 있는 const의 차이
        std::cout << "Const 객체로 []호출" << std::endl;
        return arr[index];
    }
    // ( )
    void operator()(int n1, int n2, int n3)
    {
        std::cout << "operator() 호출 " << n1 << " " << n2 << " " << n3 << std::endl;
    }

    // << , >>
    // friend함수는 내 클래스의 private을 건드릴수있는 함수
    // friend 클래스는 그 범위를 클래스로 확장해줌
    // Top-level Function이므로 맨밑에 따로 정의함
    friend std::ostream &operator<<(std::ostream &out, const MyClass &op);
    friend std::istream &operator>>(std::istream &in, MyClass &op);

    void* operator new(size_t size); // 정의는 밑에
    void operator delete(void*);

    void setMyNum(int num)
    {
        this->myNum = num;
    }
    int getMyNum() const
    {
        return myNum;
    }
};

std::ostream &operator<<(std::ostream &out, const MyClass &op)
{
    out << "operator<< 호출 : " << op.myNum; // cout이 아니라 매개변수 out인것에 주의
    return out;
}
std::istream &operator>>(std::istream &in, MyClass &op)
{
    std::cout << "operator>> 호출" << std::endl;
    in >> op.myNum;
    return in;
}

// 전역변수로 메모리 풀 만들기
unsigned char myFramePool[sizeof(MyClass)*MAX_FRAME_SIZE] = {0,};
bool myFrameOccupied[MAX_FRAME_SIZE] = {0,};

void* MyClass::operator new(size_t size){
    for(int i=0;i<MAX_FRAME_SIZE;i++){
        if(!myFrameOccupied[i]){
            myFrameOccupied[i] = true; // 할당해줬다고 표시
            std::cout << "Occupied One Memory" << std::endl;
            return reinterpret_cast<MyClass*>(myFramePool)+i; // 시작주소 반환
        }
    }
    throw "Out of Space";
    return NULL;
}

void MyClass::operator delete(void* address){
    int index = (reinterpret_cast<long>(address) - reinterpret_cast<long>(myFramePool))/sizeof(MyClass);
    myFrameOccupied[index] = false; // 메모리 0으로 초기화할 필요없음
    std::cout << "Deleted One Memory" << std::endl;
    return;
}