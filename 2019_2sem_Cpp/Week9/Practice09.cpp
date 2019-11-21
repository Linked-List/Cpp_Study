#include "IntDeque.h"
#include <iostream>
#include <string>

int main(){
    IntDeque deq;
    int num;
    std::cin >> num;
    for(int i=0;i<num;i++){
        std::string command;
        int tmp;
        std::cin >> command;

        if(command == "push_back"){
            std::cin >> tmp;
            deq.push_back(tmp);
        }else if(command == "push_front"){
            std::cin >> tmp;
            deq.push_front(tmp);
        }else if(command == "front")
            std::cout << deq.front() << std::endl;
        else if(command == "back")
            std::cout << deq.back() << std::endl;
        else if(command == "size")
            std::cout << deq.size() << std::endl;
        else if(command == "pop_front")
            std::cout << deq.pop_front() << std::endl;
        else if(command == "pop_back")
            std::cout << deq.pop_back() << std::endl;
        else if(command == "empty")
            std::cout << deq.empty() << std::endl;
        else
            std::cout << "Wrong Command" << std::endl;
    }
}