#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    char name[20];
    int age;
    int phoneNum;

    int teamNum;

    ofstream fOut("Info.txt");

    cout << "The number of team members : ";
    cin >> teamNum;
    if(fOut.is_open()){
        fOut << "Name" << setw(10) << "Age" << setw(22) << "Phone" << endl;
        for(int i=teamNum;i>0;i--){
            cout << "Name : ";
            cin >> name;
            cout << "Age : ";
            cin >> age;
            cout << "phoneNumber : ";
            cin >> phoneNum;
            cout << "\n";
            fOut << name << setw(10) << age << setw(22) << phoneNum << endl;
        }
        fOut.close();
        return 0;
    }
}