#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class stepws2{
private:
    static string fill;

public:
    stepws2(string fill){
        if(fill == "")
            stepws2::fill = "";
        else
            stepws2::fill += fill;
    }

    friend ostream& operator<<(ostream&, stepws2);
};

string stepws2::fill = "";

ostream& operator<<(ostream& out, stepws2 man){
    out << stepws2::fill;
    return out;
}

ostream& stepws(ostream& out){
    static int myWidth = 1;
    for(int i=0;i<myWidth;i++)
        out << ' ';
    myWidth++;
    return out;
}

int main(){
    cout << 10 << endl;
    cout << stepws << 20 << endl;
    cout << stepws << 30 << endl;
    cout << stepws << 40 << endl;
    cout << 50 << endl;
    cout << stepws << 60 << endl;
    cout << stepws << 70 << endl;

    cout << 10 << endl;
    cout << stepws2("#") << 20 << endl;
    cout << stepws2("#") << 30 << endl;
    cout << stepws2("#") << 40 << endl;
    cout << stepws2("") << 50 << endl;
    cout << stepws2("*") << 60 << endl;
    cout << stepws2("$") << 70 << endl;

    return 0;
}