#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class myManip{
private:
    static string fill;

public:
    myManip(string fill){
        if(fill == "")
            myManip::fill = "";
        else
            myManip::fill += fill;
    }

    friend ostream& operator<<(ostream&, myManip);
};

string myManip::fill = "";

ostream& stepws(ostream& out){
    static int myWidth = 1;
    for(int i=0;i<myWidth;i++)
        out << ' ';
    myWidth++;
    return out;
}

myManip stepws(string fill){
    return myManip(fill);
}

ostream& operator<<(ostream& out, myManip man){
    out << myManip::fill;
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
    cout << stepws("#") << 20 << endl;
    cout << stepws("#") << 30 << endl;
    cout << stepws("#") << 40 << endl;
    cout << stepws("") << 50 << endl;
    cout << stepws("*") << 60 << endl;
    cout << stepws("$") << 70 << endl;

    return 0;
}