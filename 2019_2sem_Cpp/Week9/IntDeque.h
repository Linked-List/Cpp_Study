#include <list>

class IntDeque{
private:
    std::list<int> arr;

public:
    IntDeque();
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    int size() const;
    bool empty() const;
    int front() const;
    int back() const;
};