#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r) : real(r), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex operator+(const Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex &c)
    {
        return Complex(real - c.real, imag - c.imag);
    }
    void print()
    {
        cout << real << " " << imag << endl;
    }
};

int main()
{
    Complex c1(0), c2(1.0, 2.0), c3(2.0, 3.0);

    c1 = c2 + c3;
    c1.print();

    c1 = c3 - c2;
    c1.print();
    return 0;
}