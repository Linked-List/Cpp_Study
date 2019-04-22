#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"
using namespace std;

int main(){
    List list;
    List list2;
    list.add("건국대학교");
    list.add("대한민국");
    list.add("서울시");
    list.fileSave();

    list2.fileLoad();
    list2.printAll();
    return 0;
}