#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <memory>

class Base1 {
    protected:
    int i = 0;
    public:
    virtual ~Base1() {}
    virtual int f() { return ++i; }
};

class Base2 {
    protected:
    int j = 0;
    public:
    virtual ~Base2() {}
    virtual int g() { return ++j; }
};

class Derived : public Base1, public Base2 {
};

int main() {
    {
        Derived d;
        Derived* p = &d;
        std::cout << "Derived: " << (void*)(p) << 
                     " Base1: " << (void*)(static_cast<Base1*>(p)) <<
                     " Base2: " << (void*)(static_cast<Base2*>(p)) << std::endl;

        std::cout<<sizeof(d)<<"\n";
        Base1 b1;
        Base2 b2;
        std::cout<<sizeof(b1)<<"\n";
        std::cout<<sizeof(b2)<<"\n";
    }
    {
        Derived* p = nullptr;
        std::cout << "Derived: " << (void*)(p) << 
                     " Base1: " << (void*)(static_cast<Base1*>(p)) <<
                     " Base2: " << (void*)(static_cast<Base2*>(p)) << std::endl;
    }
}