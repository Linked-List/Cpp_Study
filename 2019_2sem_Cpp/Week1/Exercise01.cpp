#include <iostream>

class Rectangle{
private:
    int width;
    int length;

public:
    void setRect(int w, int l){
        width = w;
        length = l;
    }
    int calcArea(){
        return width*length;
    }
};

int main(){
    Rectangle rec;
    rec.setRect(10,20);
    int area = rec.calcArea();

    printf("rectangle Area is %d\n",area);
}