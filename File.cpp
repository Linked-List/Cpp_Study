#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream ofs;
    ofs.open("text.txt");

    ofs << "DDD" << endl;
    ofs.close();
}