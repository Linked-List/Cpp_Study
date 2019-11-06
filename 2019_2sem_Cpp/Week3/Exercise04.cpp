#include <iostream>
#include <exception>
using namespace std;

class my_exception : public exception{
public:
    virtual const char* what() const throw(){
        return "My exception happend";
    }
}myex;

int main(){
    try{
        throw myex;
    }
    catch(my_exception& e){
        cout << e.what() << '\n';
    }
    return 0;
}