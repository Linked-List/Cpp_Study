#include "operOverload.h"
#include <iostream>

// 귀찮아서 정의파일 안나눔 알아서 보셈.

void func(const MyClass& op){
    std::cout << "MyClass type 함수 호출" << std::endl;
}
void func2(int op){
    std::cout << "int type 함수 호출" << std::endl;
}

int main(){
    std::cout << "1-1. MyClass a; 변수선언" << std::endl;
    MyClass a; // 기본생성자가 불리는 모습
    std::cout << "1-2. MyClass* ptr = new MyClass;" << std::endl;
    MyClass* ptr = new MyClass; // 같은 결과를 보임
    delete ptr;

    std::cout << "2-1. 3개 짜리 클래스 배열 선언" << std::endl;
    MyClass b[3]; // 만드는 순간 바로 생성자가 불리는 모습.
    std::cout << "2-2. new를 이용해 배열 동적할당" << std::endl;
    ptr = new MyClass[3]; // 완전히 같은 결과를 보임
    delete[] ptr;

    std::cout << "3-1. 복사생성자 호출방식1 - MyClass c(a)" << std::endl;
    a.setMyNum(10); // 테스트하기위해 멤버변수값 변경
    MyClass c(a);
    std::cout << "3-2. 복사생성자 호출방식2 - MyClass d = a (초기화방식)" << std::endl;
    MyClass d = a;
    std::cout << "3-3. =연산자 호출 - MyClass e; e = a; (3-2와 비슷해보이지만 다르다.)" << std::endl;
    MyClass e;
    e = a;

    std::cout << "4. 변환생성자 호출 - 해당 타입에 해당하는 생성자가 존재하면 알아서 바꿔줌" << std::endl;
    std::cout << "4-1. 초기화 단계의 호출 - 해당 타입의 생성자를 그냥 부름" << std::endl;
    MyClass f(1);
    MyClass g = 1;
    MyClass h = static_cast<MyClass>(1);
    std::cout << "4-2. 그외 단계의 호출 - 해당 생성자로 임시 객체를 만든 다음에 대입시킨다." << std::endl;
    static_cast<MyClass>(1); // 강제 형변환의 가능
    func(1); // 자동 형변환도 가능. (막으려면 생성자앞에 explicit 선언)
    
    std::cout << "4-3. 클래스간에도 가능하나? - 가능하다." << std::endl;
    MyClass2 aa;
    aa.myNum=10;
    MyClass i = aa; // 초기화 단계의 호출
    static_cast<MyClass>(aa); // 강제형변환
    func(aa); // 자동형변환

    std::cout << "4-4. 변환 연산자" << std::endl;
    (int)i; // C스타일 강제형변환
    static_cast<int>(i); // C++스타일 형변환
    func2(i); // 자동형변환
    
    std::cout << "4-5. 이또한 클래스간 가능?" << std::endl;
    static_cast<MyClass2>(i); // 가능하다.

    std::cout << "5. 사칙/논리 연산 오버로딩" << std::endl;
    std::cout << "5-1. + - * / % 관련" << std::endl;
    h + i;
    // h + 10;
    // 이는 우리가 만든 operator int()의 정의로 인해서 int + int로 봐야할지.
    // myClass + myClass로 봐야할지 몰라서 컴파일에러가 난다.
    h + static_cast<MyClass>(10); // 모호함은 없애면 될일!
    // 다른방법은 explicit operator int()로 모호함을 또 해결하면된다.
    std::cout << "5-2. < > == != <= >= 관련" << std::endl;
    h < i;
    std::cout << "5-3. += -= *= /= %= 등 관련" << std::endl;
    std::cout << (h += i).getMyNum() << std::endl; // return타입을 줬기때문에 이런 행위도 가능
    std::cout << "5-4. 증감연산자" << std::endl;
    std::cout << "Original : " << h.getMyNum() << std::endl;
    std::cout << (++h).getMyNum() << std::endl;
    std::cout << (h++).getMyNum() << std::endl;
    
    std::cout << "5-5. 배열연산자" << std::endl;
    h[0] = 10;
    const MyClass& p2 = h;
    p2[0];
    std::cout << "5-6. 함수연산자" << std::endl;
    h(10,20,30); // 매개변수는 형식을 내맘대로 바꿀수있다.
    // C++에서 이걸 이용해 Java의 Comparator를 구현한다.
    // C++ Functor 검색

    std::cout << "6-1. IO연산자" << std::endl;
    std::cin >> h;
    std::cout << h << std::endl; // 잘 들어간 모습

    /*
    추가설명
    어떠한 연산으로 나온 결과 객체는 임시값이다.
    예) int num = 1+2; 여기서 3이 임시값이다.
    이 임시은 보통 오른쪽에 항상 오기때문에 R-Value라고 부른다.
    사용이 종료되면 없어지는 값이다.
    즉 사용을 계속하면 안없앨수가 있다. 이를 잡아주는 방식이 두가지이다.
    const int& / 좌측값 int type과, 우측값 int type 모두를 참조할수있다.
    int&& / 우측값만 지정해서 참조한다. (좌측값이 오면 오류남)
    다만 전자의 경우 const이기때문에 값을 변경하지 못한다.

    이걸 왜 알아야하냐.
    return type이 MyClass이면 반환된 그 시점에는 저장이 안되있기때문에 R-Value이다.
    a+(b+c)를 하면 b+c의 값이 임시값으로 a의 operator+의 인자로 전달된다.
    따라서 operator+(int& a)로 정의하면 에러가 납니다.
    -> operator+(const int& a)로 정의하거나 r-value를 위한 operator+(int&& a)를 추가로 정의해야한다.
    */
    int myNum = 1;
    const int& p = 10+20;
    const int& p3 = myNum;
    int&& p4 = 10; // 이것또한 우측값이다.
    //int&& p5 = myNum; 에러
    p4++; // 이 임시값을 변경도 가능하다. **10이라는 리터럴을 바꾸는게 아니다.**
    std::cout << "리터럴 10 : " << 10 << std::endl;
    std::cout << "임시값 p4 증가 : " << p4 << std::endl;


    // 메모리할당해제 연산자 new delete 오버로딩
    std::cout << "7-1. 정의해놓은 new 함수 사용 시도" << std::endl;
    MyClass* z = new MyClass;
    z->setMyNum(50);
    std::cout << "z의 주솟값 : " << reinterpret_cast<long>(z) << std::endl;
    std::cout << "내가 만든 임의메모리 주솟값 : " << reinterpret_cast<long>(myFramePool) << std::endl;
    std::cout << "일치하는 모습을 보임" << std::endl;
    std::cout << "z1저장해놨다가 값 사용 : " << z->getMyNum() << std::endl;
    std::cout << "7-2. delete 함수 사용" << std::endl;
    delete z;
    
    std::cout << "7-3. 배열도 잘 되는가?" << std::endl;
    z = new MyClass[5];
    std::cout << "z의 주솟값 : " << reinterpret_cast<long>(z) << std::endl;
    std::cout << "내가 만든 임의메모리 주솟값 : " << reinterpret_cast<long>(myFramePool) << std::endl;
    delete[] z;
    std::cout << "응 안돼~ new[] delete[] 다시 정의해야하는데 안배워서 따로 안함" << std::endl;
    
    return 0;
}