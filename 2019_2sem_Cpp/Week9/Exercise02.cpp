#include <iostream>
#include <list>
using namespace std;

template <typename T>
void print_list(std::list<T>& lst){
    cout << "[ ";
    for(const auto& elem : lst){
        cout << elem << " ";
    }
    cout << "]" << endl;
}
int main(){
    list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    print_list(lst);

    for(list<int>::iterator itr=lst.begin();itr!=lst.end();++itr){
        if(*itr == 20){
            lst.insert(itr,50);
        }
    }
    print_list(lst);

    for(list<int>::iterator itr = lst.begin();itr!=lst.end();++itr){
        if(*itr == 30){
            lst.erase(itr);
            break;
        }
    }
    print_list(lst);

    return 0;
}