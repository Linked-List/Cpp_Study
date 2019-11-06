#include <iostream>
#include <exception>

using namespace std;

const int MaxSize = 1000;
float arr[MaxSize];
enum out_of_bounds{underflow, overflow};

float& access(int i){
    if(i<0) throw underflow;
    if(i>=MaxSize) throw overflow;
    return arr[i];
}
void g(int i){
    try{
        float val = access(i);
    }catch(out_of_bounds t){
        if(t == underflow){
            cerr << "arr : underflow...aborting\n";
            exit(EXIT_FAILURE);
        }
        if(t == overflow){
            cerr << "arr : overflow...aborting\n";
            exit(EXIT_FAILURE);
        }
    }
    cout << "arr[" << i << "]" << endl;
}
int main(){
    int i;
    cin >> i;
    g(i);
    return 0;
}