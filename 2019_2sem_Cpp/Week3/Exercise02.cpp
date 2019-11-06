#include <iostream>

using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& setValues(int i){
    return vals[i];
}

void swap(int& a, int& b){
    int t;
    t=a; a=b; b=t;
}

int main(){
    int i=7, j=3;
    cout << "Call by reference" << endl;
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    swap(i,j);
    cout << "i = " << i << endl;
    cout << "j = " << j << endl << endl;

    cout << "return by reference" << endl;
    cout << "Value before change" << endl;
    for(int i=0;i<5;i++){
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    setValues(1) = 20.23;
    setValues(3) = 70.8;
    cout << "Value after change" << endl;
    for(int i=0;i<5;i++){
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    return 0;
}