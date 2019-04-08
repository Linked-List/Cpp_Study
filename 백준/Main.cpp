#include <iostream>
#include <string>

using namespace std;
int main(){
    int num;
    cin >> num;

    for(int i=1;i<=num;i++){
        for(int k=1;k<=num;k++){
            if(i%2==1){
                cout << "* ";
            }else{
                cout << " *";
            }
        }
        cout << endl;
    }

}