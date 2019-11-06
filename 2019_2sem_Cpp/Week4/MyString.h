class MyString{
private:
  char* string_content; //string 내용
  int string_length; // string 길이
  int memory_capacity; // 메모리 크기
public:
  MyString(); //default constructor
  MyString(const char* str); // 문자열 생성자
  MyString(const MyString& str); // 복사 생성자
  ~MyString(); // delete[] string_content


  void setString(const char* str); // String일 경우 set
  
  MyString getMyString() const; //return MyString class
  char* getString() const; //return string_content
  int length() const; // return string length
  int capacity() const; // retrun momory_capacity
  void reserve(int size); // 할당할 문자열 크기 reserve, 예약

  void println() const; // 출력 함수

  // 문자, 문자열 변경
  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const; // i 위치 문자 리턴

  // 문자열 삽입
  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);

  // 문자, 문자열 찾기
  int find(int find_from, const MyString& str) const;
  int find(int find_from, const char* str) const;

  // 삭제
  MyString& erase(int loc, int num);
};