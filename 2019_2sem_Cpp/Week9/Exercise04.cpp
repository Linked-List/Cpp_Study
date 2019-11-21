#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

int main(){
    const int howMany = 8;
    int i;
    priority_queue<int> nums;

    srand(time(0));
    for(int i=0;i<howMany;i++){
        int next = rand();
        cout << next << endl;
        nums.push(next);
    }
    cout << "\n*** Priority by value: " <<endl;
    for(int i=0;i<howMany;i++){
        cout << nums.top() << endl;
        nums.pop();
    }
    return 0;
}