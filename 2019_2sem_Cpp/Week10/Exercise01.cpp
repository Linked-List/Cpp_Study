#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end){
    while(begin != end){
        cout << "[" << *begin << "] ";
        begin++;
    }
    cout << endl;
}

struct is_odd{
    int num_delete;

    is_odd() : num_delete(0){}

    bool operator()(const int& i){
        if(num_delete >= 2) return false;

        if(i%2==1){
            num_delete++;
            return true;
        }
        return false;
    }
};

int main(){
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    cout << "original vector" << endl;
    print(vec.begin(), vec.end());

    cout << "erase 2 odd elements" << endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
    print(vec.begin(),vec.end());

    return 0;
}