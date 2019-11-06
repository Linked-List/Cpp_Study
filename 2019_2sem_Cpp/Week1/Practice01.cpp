#include <iostream>

class Triangle{
private:
    int width;
    int height;

public:
    void setTri(int width, int height){
        this->width = width;
        this->height = height;
    }
    double area(){
        return (double)width*height/2;
    }
};

class TriCalculator{
public:
    double TriAdd(Triangle& a, Triangle& b){
        return a.area()+b.area();
    }
    double TriMul(Triangle& a, Triangle& b){
        return a.area()*b.area();
    }
    double TriMin(Triangle& a, Triangle& b){
        double result = a.area()-b.area();
        return result<0 ? -result : result;
    }
};

int main(){
    Triangle A;
    A.setTri(10, 5);
    Triangle B;
    B.setTri(2,9);

    TriCalculator cal;

    std::cout << "µÎ »ï°¢ÇüÀÇ ÇÕÀº " << cal.TriAdd(A,B) << std::endl;
    std::cout << "µÎ »ï°¢ÇüÀÇ °öÀº " << cal.TriMul(A,B) << std::endl;
    std::cout << "µÎ »ï°¢ÇüÀÇ »¬¼ÀÀº " << cal.TriMin(A,B) << std::endl;
    return 0;
}