#include <iostream>
#include <cstdlib>

using namespace std;

class InnerClass{
private:
    int* ptr;
    int col;
public:
    InnerClass(int* ptr, int col) : ptr(ptr),col(col){}
    int& operator[](int idx){
        if(idx < 0 || idx>col){
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return ptr[idx];
    }
    int operator[](int idx)const{
        if(idx < 0 || idx>col){
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return ptr[idx];
    }
};

class BoundCheck2DIntArray{
private:
    int* arr;
    int row;
    int col;

    BoundCheck2DIntArray(const BoundCheck2DIntArray&){}
    BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray&){}

public:
    BoundCheck2DIntArray(int row, int col) : row(row), col(col) {
        arr = new int[row*col];
    }
    InnerClass operator[](int idx){
        if(idx<0 || idx>row){
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return InnerClass(arr+(idx*col),col);
    }
    const InnerClass operator[](int idx) const{
        if(idx<0 || idx>row){
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return InnerClass(arr+(idx*col),col);
    }
    int getRow() const{return row;}
    int getCol() const{return col;}
    ~BoundCheck2DIntArray(){delete[] arr;}
};

int main(){
    BoundCheck2DIntArray arr2d(3,4);
    for(int n=0;n<3;n++){
        for(int m=0;m<4;m++){
            arr2d[n][m] = n+m;
        }
    }
    for(int n=0;n<3;n++){
        for(int m=0;m<4;m++){
            cout << arr2d[n][m] << ' ';
        }
        cout << endl;
    }
    return 0;
}