#include <iostream>
#include <assert.h>

class stack
{
private:
    int* data;
    int max;
    int sp;

public:
    void push(int);
    void pop();
    bool empty() const;
    int top() const;
    int size() const;
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

stack::stack(int size)
{
    sp = 0;
    max = size;
    data = new int[max];
    std::cout << "配列のサイズ: " << max << std::endl;
}

stack::~stack()
{
    delete[] data;
}

int main(void)
{
    stack s(100);                       
    s.push(5);                          
    s.push(8);                         
    s.push(9);                          
    std::cout << s.top() << std::endl; 
    s.pop();                            
    std::cout << s.top() << std::endl;  
    s.pop();                           
    s.push(3);                          
    std::cout << s.size() << std::endl; 
    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}