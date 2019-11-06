#include "MyString.h"
#include <iostream>

MyString::MyString(){
    string_content = nullptr;
    string_length = 0;
    memory_capacity = 0;
}
MyString::MyString(const char* str){
    int i=0;
    while(str[i] != '\0')
        i++;
    string_content = new char[i];
    string_length = i;
    memory_capacity = i;
    for(int j=0;j<=i;j++)
        string_content[j] = str[j];
}
MyString::MyString(const MyString& str){
    int i=0;
    while(str.string_content[i] != '\0')
        i++;
    string_content = new char[i];
    string_length = i;
    memory_capacity = i;
    for(int j=0;j<=i;j++)
        string_content[j] = str.string_content[j];
}
MyString::~MyString(){
    if(string_content != nullptr)
        delete[] string_content;
}

void MyString::setString(const char* str){
    if(string_content != nullptr)
        delete[] string_content;
    int i=0;
    while(str[i] != '\0')
        i++;
    string_content = new char[i+1];
    string_length = i+1;
    memory_capacity = i+1;
    for(int j=0;j<=i;j++)
        string_content[j] = str[j];
}

MyString MyString::getMyString() const{
    return *this;
}
char* MyString::getString() const{
    return this->string_content;
}
int MyString::length() const{
    return this->string_length;
}
int MyString::capacity() const{
    return this->memory_capacity;
}
void MyString::reserve(int size){
    if(size < this->memory_capacity)
        return;
    char* newstr = new char[memory_capacity=size];
    for(int i=0;i<string_length;i++)
        newstr[i] = string_content[i];
    for(int i=string_length;i<memory_capacity;i++)
        newstr[i] = 0;
    delete[] string_content;
    string_content = newstr;
}

void MyString::println() const{
    for(int i=0;i<string_length;i++)
        std::cout << string_content[i];
    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str){
    setString(str.string_content);
    return *this;
}
MyString& MyString::assign(const char* str){
    setString(str);
    return *this;
}

char MyString::at(int i) const{
    if(i>string_length-1)
        return 0;
    return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str){
    if(memory_capacity < string_length+str.string_length)
        reserve(string_length+str.string_length);
    for(int i=loc+str.string_length;i<string_length+str.string_length;i++)
        string_content[i] = string_content[i-str.string_length];
    for(int i=0;i<str.string_length;i++)
        string_content[i+loc] = str.string_content[i];
    string_length += str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char* str){
    int strsize = 0;
    while(str[strsize] != '\0')
        strsize++;
    if(memory_capacity < string_length+strsize)
        reserve(strsize+string_length);
    for(int i=loc+strsize;i<string_length+strsize;i++)
        string_content[i] = string_content[i-strsize];
    for(int i=0;i<strsize;i++)
        string_content[i+loc] = str[i];
    string_length += strsize;
    return *this;
}

int MyString::find(int find_from, const MyString& str) const{
    for(int i = find_from;i<string_length-str.string_length;i++){
        if(string_content[i] == str.string_content[0]){
            int j = 1;
            for(;j<str.string_length;j++)
                if(string_content[i+j] != str.string_content[j])
                    break;
            if(j==str.string_length)
                return i;
        }
    }
    return -1;
}
int MyString::find(int find_from, const char* str) const{
    int strsize = 0;
    while(str[strsize] != '\0')
        strsize++;

    for(int i = find_from;i<string_length-strsize;i++){
        if(string_content[i] == str[0]){
            int j = 1;
            for(;j<strsize;j++)
                if(string_content[i+j] != str[j])
                    break;
            if(j==strsize)
                return i;
        }
    }
    return -1;
}

MyString& MyString::erase(int loc, int num){
    for(int i=0;i<string_length;i++){
        if(loc+i+num > string_length)
            break;
        string_content[loc+i] = string_content[loc+num+i];
    }
    string_length -= num;
}