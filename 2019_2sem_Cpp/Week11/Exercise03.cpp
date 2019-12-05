#include <iostream>

using namespace std;

int main(){
    int val;
    bool ok;
    string line;
    cout << hex;
    for(;;){
        cout << "Enter an integer(negative to quit) : ";
        ok = true;
        cin >> val;
        if(!cin){
            cout << "Bad input. Redo.";
            cin.clear();
            getline(cin, line);
            ok = false;
        }
        if(ok){
            if(val<0) break;
        }
        else{
            cout << val << '\n';
        }
    }
    return 0;
}