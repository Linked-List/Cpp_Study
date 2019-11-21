#include <iostream>
#include <cctype>
#include <stack>

using namespace std;

int main(){
    const string prompt = "Enter an algebraic expression: ";
    const char lparen = '(';
    const char rparen = ')';
    stack<char> s;
    string buf;

    cout << prompt << endl;
    getline(cin, buf);

    for(int i=0;i<buf.length();i++){
        if(!isspace(buf[i]))
            s.push(buf[i]);
    }
    cout << "OG expression: " << buf << endl;

    cout << "Expression in reverse: ";

    while(!s.empty()){
        char t = s.top();
        s.pop();

        if(t == lparen) t = rparen;
        else if(t == rparen) t = lparen;

        cout << t;
    }
    cout << endl;
    return 0;
}