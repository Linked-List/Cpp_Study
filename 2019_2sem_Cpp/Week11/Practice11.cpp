#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define CHPERLINE 52 // result 한줄에 표현하는 길이

using namespace std;

void printInt(ostream& out, char operat, string op1, string op2, int result, int lineNum){
    int start_pos = lineNum*(CHPERLINE+1);
    out.seekp(start_pos, ios_base::beg);

    out.width(6);
    out.setf(ios_base::left, ios_base::adjustfield);
    out << op1 << operat << ' ';
    out.width(6);
    out << op2 << '=';

    out.width(15);
    out.unsetf(ios_base::left);
    out.setf(ios_base::dec,ios_base::basefield);
    out << "dec : " + to_string(result);

    out.setf(ios_base::oct,ios_base::basefield);
    out.setf(ios_base::showbase);        
    out << " oct : ";
    out.width(4);
    out << setfill('0') << result;

    out << " hex : ";
    out.width(4);
    out.setf(ios_base::hex, ios_base::basefield);
    out.setf(ios_base::internal, ios_base::adjustfield);
    out << result;

    out << setfill(' '); // reset Original Fill
}
void printDouble(ostream& out, char operat, string op1, string op2, double result, int lineNum){
        int start_pos = lineNum*(CHPERLINE+1);
        out.seekp(start_pos, ios_base::beg);

        out.width(6);
        out.setf(ios_base::left, ios_base::adjustfield);
        out << op1 << operat << ' ';
        out.width(6);
        out << op2 << '=';

        out.width(37);
        out.unsetf(ios_base::left);
        out << result;
}

int main(){
    ifstream ifs("calculation.txt");
    ofstream ofs("result.txt");

    char operat;
    string op1, op2;

    int numOfLines; // 문제의 갯수 카운트
    string buf;
    for(numOfLines=0;getline(ifs,buf);numOfLines++){
        ofs.width(CHPERLINE); // 덮어써지는 특성을 이용해서 빈칸을 개수만큼채움
        ofs << '\n';
    }
    ifs.close();
    ifs.open("calculation.txt");
    // ifs.seekg(0,ios_base::beg); 이 코드가 안되서 어쩔수 없이 닫고 다시염

    for(int i=1;ifs >> operat >> op1 >> op2;i++){
        int n1 = stoi(op1,nullptr,0); // 진법 알아서 해석
        int n2 = stoi(op2,nullptr,0);
        switch(operat){
            case '+':
                printInt(ofs,operat,op1,op2,n1+n2,numOfLines-i);
                break;
            case '-':
                printInt(ofs,operat,op1,op2,n1-n2,numOfLines-i);
                break;
            case '*':
                printInt(ofs,operat,op1,op2,n1*n2,numOfLines-i);
                break;
            case '/':
                printDouble(ofs,operat,op1,op2,static_cast<double>(n1)/n2,numOfLines-i);
                break;
            default:
                ofs.seekp((numOfLines-i)*(CHPERLINE+1),ios_base::beg);
                ofs << "It is Wrong!";
        }
    }
    ifs.close();
    ofs.close();
}