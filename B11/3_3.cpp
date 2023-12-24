#include <iostream>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex &operator=(const Complex &c)
    {
        real = c.real;
        imag = c.imag;
        return *this;
    }

    Complex operator+(const Complex &c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex &operator+=(const Complex &c)
    {
        real += c.real;
        imag += c.imag;
        return *this;
    }

    double re() const { return real; }
    double im() const { return imag; }
};

int main()
{
    Complex a(3.0, 4.0), b(1.0, 2.0), c;
    std::cout << "初期状態:\n";
    std::cout << "a: " << a.re() << " + " << a.im() << "i" << std::endl;
    std::cout << "b: " << b.re() << " + " << b.im() << "i" << std::endl;

    a = b;
    std::cout << "bをaに代入後:" << std::endl;
    std::cout << "a: " << a.re() << " + " << a.im() << "i" << std::endl;

    c = a + b;
    std::cout << "足し算後 (c = a + b):" << std::endl;
    std::cout << "c: " << c.re() << " + " << c.im() << "i" << std::endl;

    a = Complex(3.0, 4.0); 
    c = a += b;
    std::cout << "+= 操作後 (a += b):" << std::endl;
    std::cout << "a: " << a.re() << " + " << a.im() << "i" << std::endl;
}

