#include <iostream>

using namespace std;

ostream& point(ostream& out){
    return cout << "***";
}

ostream& rightarrow(ostream& out){
    return out <<"--->";
}

ostream& alert(ostream& out){
    return out << "\a";
}

int main(){
    cout << "alert" << alert << endl;
    cout << "C" << rightarrow << "C++" << endl;
    cout << point << "VS code" << point << endl;

    return 0;
}