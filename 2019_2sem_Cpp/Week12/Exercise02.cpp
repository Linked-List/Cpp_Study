#include <iostream>
#include <cstring>

using namespace std;

class UD_Manip{
private:
    int width, precision;
    char fill;

public:
    UD_Manip(int W, int P, char F){
        width = W;
        precision = P;
        fill = F;
    }
    friend ostream& operator <<(ostream&, UD_Manip);
};

ostream& operator <<(ostream& out, UD_Manip manip){
    out.width(manip.width);
    out.precision(manip.precision);
    out.fill(manip.fill);
    out << flush;

    return out;
}

UD_Manip setwpf(int w, int p, char f){
    return UD_Manip(w,p,f);
}

int main(){
    cout << setwpf(10,5,'#') << 28.66565544;

    return 0;
}