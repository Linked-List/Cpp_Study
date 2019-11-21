#include "IntDeque.h"

IntDeque::IntDeque(){};
void IntDeque::push_front(int x){
    arr.push_front(x);
}
void IntDeque::push_back(int x){
    arr.push_back(x);
}
int IntDeque::pop_front(){
    if(arr.size() == 0)
        return -1;
    int x = arr.front();
    arr.pop_front();
    return x;
}
int IntDeque::pop_back(){
    if(arr.size() == 0)
        return -1;
    int x = arr.back();
    arr.pop_back();
    return x;
}
int IntDeque::size() const{
    return arr.size();
}
bool IntDeque::empty() const{
    return arr.empty();
}
int IntDeque::front() const{
    if(arr.size() == 0)
        return -1;
    return arr.front();
}
int IntDeque::back() const{
    if(arr.size() == 0)
        return -1;
    return arr.back();
}