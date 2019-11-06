#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    string oprand1;
    string oprand2;
    char op;
    char temp;
    
    ifstream fIn("calculation.txt");

    if(!fIn.is_open()){
        cout << "[ERROR]Can not find File" << endl;
        return 0;
    }

    while(fIn >> oprand1 >> op >> oprand2 >> temp){
        int num1;
        int num2;
        int result;
        if(atoi(oprand1.c_str())==0){
            num1 = strtoul(oprand1.c_str(),nullptr,16);
            num2 = strtoul(oprand2.c_str(),nullptr,16);

            switch(op){
            case '+':
                result = num1+num2;       
                break;
            case '-':
                result = num1-num2;
                break;
            case '*':
                result = num1*num2;
                break;
            }
            cout << showbase << hex << left << setw(7) << num1
                << op << " " << setw(7) << num2 << "="
                << right << setw(7) << result << endl;
        }else{
            num1 = atoi(oprand1.c_str());
            num2 = atoi(oprand2.c_str());

            switch(op){
            case '+':
                result = num1+num2;       
                break;
            case '-':
                result = num1-num2;
                break;
            case '*':
                result = num1*num2;
                break;
            case '/':
                cout << dec << left << setw(7) << num1
                    << op << " " << setw(7) << num2 << "="
                    << right << setw(7) << showpoint << setprecision(3) << (double)num1/num2 << endl;
                continue;
            }
            cout << dec << left << setw(7) << num1
                << op << " " << setw(7) << num2 << "="
                << right << setw(7) << result << endl;
        }


    }
    fIn.close();
    return 0;
}