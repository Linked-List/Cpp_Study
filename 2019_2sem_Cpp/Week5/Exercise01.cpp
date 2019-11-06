#include <iostream>

using namespace std;

class Task{
private:
    static unsigned n;
public:
    Task(){
        n++;
    }
    ~Task(){
        n--;
    }
    void CountN(){
        cout << n << endl;
    }
};

unsigned Task::n=0;

int main(){
    Task a;
    Task b;
    Task c;
    a.CountN();
    b.CountN();
    c.CountN();
    return 0;
}