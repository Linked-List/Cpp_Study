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
    friend Complex operator+(const Complex &c1, const Complex &c2)
    {
        Complex temp(c1.real + c2.real, c1.imag + c2.imag);
        return temp;
    }
    friend Complex operator-(const Complex &c1, const Complex &c2)
    {
        Complex temp(c1.real - c2.real, c1.imag - c2.imag);
        return temp;
    }
    friend Complex operator*(const Complex &c1, const Complex &c2)
    {
        Complex temp(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
        return temp;
    }
    friend Complex operator/(const Complex &c1, const Complex &c2)
    {
        Complex temp((c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag),
                     (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag));
        return temp;
    }
    void print()
    {
        cout << real << " " << imag << endl;
    }
};

int main()
{
    Complex a(0), b(4.3, -8.2), c(1.1, 2.3);

    a = b + 5.1;
    a.print();
    a = 5.1 + b;
    a.print();
    a = b - 1.1;
    a.print();
    a = b * c;
    a.print();
    a = b / c;
    a.print();
    return 0;
}