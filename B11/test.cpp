#include <iostream>
#include <cassert>

class stack {
private:
    int sp;
    int max;
    int *data;

public:
    stack(int sz) : sp(0), max(sz), data(new int[max]) {}
    ~stack() { delete[] data; }

    void push(int d) {
        assert(sp < max);  // sp should be less than max to avoid overflow
        data[sp++] = d;
    }

    void pop() {
        assert(sp > 0);
        --sp;
    }

    bool empty() const { return sp == 0; }
    int top() const { return data[sp - 1]; }
    int size() const { return sp; }

    void dump(std::ostream &os) const {
        os << "max=" << max << ", ";
        os << "sp=" << sp << ", ";
        os << "data=(";
        for (int i = 0; i < sp; i++)
            os << data[i] << " ";
        os << ")\n";
    }

    // Corrected copy constructor
    stack(const stack &s) : max(s.max), sp(s.sp), data(new int[max]) {
        for (int i = 0; i < sp; ++i) {
            data[i] = s.data[i];
        }
    }

    // Assignment operator not implemented, needed for proper copy-assignment
    stack &operator=(const stack &) = delete;
};

// Modified plus function to take references
stack plus(const stack &s1, const stack &s2) {
    int sz = s1.size() + s2.size();
    stack tmp(sz), s(sz);

    // Use local copies to avoid modifying original stacks
    stack copy1 = s1, copy2 = s2;

    while (!copy2.empty()) {
        tmp.push(copy2.top());
        copy2.pop();
    }

    while (!copy1.empty()) {
        tmp.push(copy1.top());
        copy1.pop();
    }

    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }

    return s;
}

int main() {
    stack s1(5);
    stack s2(5);
    stack s(10);

    s1.push(1);
    s1.push(3);
    s1.push(5);
    s2.push(2);
    s2.push(4);
    s2.push(6);

    s = plus(s1, s2);

    s1.dump(std::cout);
    s2.dump(std::cout);
    s.dump(std::cout);

    return 0;
}
