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
Complex operator+(Complex a, Complex b)
{
    double r = a.re() + b.re();
    double i = a.im() + b.im();
    return Complex(r, i);
}

Complex operator-(Complex a, Complex b)
{
    double r = a.re() - b.re();
    double i = a.im() - b.im();
    return Complex(r, i);
}

Complex operator*(Complex a, Complex b)
{
    double r = a.re() * b.re() - a.im() * b.im();
    double i = a.re() * b.im() + a.im() * b.re();
    return Complex(r, i);
}
std::ostream &operator<<(std::ostream &os, Complex &c)
{
    c.print(os);
    return os;
}

int main(void)
{
    Complex a[3]; // a[0], a[1], a[2] ができる
    a[0] = Complex(1.00, 2.00);
    a[1] = a[0] + Complex(0.00, 1.00);
    Complex *c = &(a[2]); // c は a[2] を指すポインタ
    *c = a[0];            // *c の実体は a[2] となる
    for (int i = 0; i < 3; i++)
        std::cout << a[i] << std::endl;
    Complex *b = new Complex[3]; // 動的な配列の割当て
    for (int i = 0; i < 3; i++)
        b[i] = a[i] + Complex(1.00, 1.00);
    for (int i = 0; i < 3; i++)
        std::cout << b[i] << std::endl;
    delete[] b; // b の解放
    return 0;
}