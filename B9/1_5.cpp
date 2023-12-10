#include <iostream>
#include <assert.h>

class stack
{
private:
    int *data;
    int max;
    int sp;

public:
    void push(int);
    void pop();
    bool empty() const;
    int top() const;
    int size() const;
    friend bool equal(stack const &s1, stack const &s2);
    stack(int size);
    ~stack();
};

void stack::push(int n)
{
    assert(sp < max);
    data[sp++] = n;
}

void stack::pop()
{
    assert(sp > 0);
    --sp;
}

bool stack::empty() const
{
    return sp == 0;
}

int stack::top() const
{
    return data[sp - 1];
}

int stack::size() const
{
    return sp;
}

bool equal(stack const &s1, stack const &s2)
{
    bool eq = true; // 等しければ eq=true, そうでなければ eq=false
    if (s1.sp != s2.sp)
        eq = false; // データ数が違えば等しくない
    else
    {
        for (int j = 0; j < s1.sp && eq; j++)
        {
            if (s1.data[j] != s2.data[j])
                eq = false;
            // データが一つでも一致しなければ等しくない
        }
    }
    return eq;
}

stack::stack(int size)
{
    max = size;
    data = new int[max];
    sp = 0;
}

stack::~stack()
{
    delete[] data;
}

int main(void)
{
    stack s1(100);
    stack s2(100);
    s1.push(5);
    s1.push(8);
    s1.push(9);
    s2.push(5);
    s2.push(8);
    s2.push(9);
    std::cout << equal(s1,s2) << std::endl;
    s2.pop();
    std::cout << equal(s1,s2) << std::endl;
    return 0;
}