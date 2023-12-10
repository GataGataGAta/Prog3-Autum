#include <iostream>

class Complex
{
private:
    double real; // 実部
    double imag; // 虚部
public:
    Complex()
    {
        real = 0.0;
        imag = 0.0;
    }
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }
    Complex(double r)
    {
        real = r;
        imag = 0.0;
    }
    double re() const { return real; }  // 実部を取り出す
    double im() const { return imag; }  // 虚部を取り出す
    void set_re(double r) { real = r; } // 実部を設定
    void set_im(double i) { imag = i; } // 虚部を設定
    void print(std::ostream &os) const
    { // 出力
        os << real << "+" << imag << "i";
    }
};

int main(void)
{
    Complex a;
    a.set_re(1.11);
    a.set_im(2.22);
    Complex b(3.33, 4.44);
    Complex c;
    c = Complex(9.99, 88.88);
    a.print(std::cout);std::cout << std::endl;
    b.print(std::cout);std::cout << std::endl;
    c.print(std::cout);std::cout << std::endl;
    c = a;
    c.print(std::cout);std::cout << std::endl;
    double r;
    std::cout << "実部を入力してください: ";
    std::cin >> r;
    Complex d(r);
    d.print(std::cout);std::cout << std::endl;
    
    return 0;
}