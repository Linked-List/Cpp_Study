#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class myManip{
private:
    static int width;
    static string fill;
    string temp = " ";

public:
    myManip operator()(string fill){
        myManip t;
        t.temp = fill;
        if(fill == ""){
            myManip::fill = "";
            myManip::width = 0;
        }else
            myManip::fill += fill;
        return t;
    }

    friend ostream& operator<<(ostream&, myManip);
};

int myManip::width = 1;
string myManip::fill = "";

ostream& operator<<(ostream& out, myManip man){
    if(man.temp == " "){
        for(int i=0;i<myManip::width;i++)
            out << ' ';
        myManip::fill += " ";
    }else{
        out << myManip::fill;
    }
    myManip::width++;
    return out;
}

int main(){
    myManip stepws;

    cout << 10 << endl;
    cout << stepws << 20 << endl;
    cout << stepws << 30 << endl;
    cout << stepws << 40 << endl;
    cout << 50 << endl;
    cout << stepws << 60 << endl;
    cout << stepws << 70 << endl;

    cout << stepws(""); // ÃÊ±âÈ­

    cout << 10 << endl;
    cout << stepws("#") << 20 << endl;
    cout << stepws("#") << 30 << endl;
    cout << stepws("#") << 40 << endl;
    cout << stepws("") << 50 << endl;
    cout << stepws("*") << 60 << endl;
    cout << stepws("$") << 70 << endl;

    return 0;
}