#include <iostream>
#include <cassert>

class stack
{
private:
    int sp;
    int max;
    int *data;

public:
    stack(int sz) : sp(0), max(sz), data(new int[sz]) {}

    ~stack() { delete[] data; }

    void push(int d)
    {
        assert(sp < max);
        data[sp++] = d;
    }

    void pop()
    {
        assert(sp > 0);
        --sp;
    }

    bool empty() const { return sp == 0; }

    int top() const
    {
        assert(sp > 0);
        return data[sp - 1];
    }
    int size() const { return sp; }
    void dump(std::ostream &os) const;
    stack(const stack &s) : max(s.max), sp(s.sp), data(new int[s.max])
    {
        for (int i = 0; i < sp; ++i)
        {
            data[i] = s.data[i];
        }
    }
};

void stack::dump(std::ostream &os) const
{
    os << "max=" << max << ", ";
    os << "sp=" << sp << ", ";
    os << "data=(";
    for (int i = 0; i < sp; i++)
        os << data[i] << " ";
    os << ")\n";
}
