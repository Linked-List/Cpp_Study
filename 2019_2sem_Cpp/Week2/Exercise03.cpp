#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile("input.txt");
    ofstream oFile("input.txt",ios::app);
    char buf[100];
    string s;
    char ch;

    if(!inFile.is_open()){
        cout << "Can not find file" << endl;
        return 0;
    }
    while(!inFile.eof()){
        getline(inFile, s);
        cout << s << endl;
    }
    inFile.close();
    if(oFile.is_open()){
        cin.getline(buf,100);
        oFile << buf << "\n";
    }
    oFile.close();

    ifstream reinFile("input.txt");
    while(reinFile.get(ch)){
        cout << ch;
    }
    reinFile.close();

    return 0;
}