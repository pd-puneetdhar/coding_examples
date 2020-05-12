#include <iostream> 
#include <memory>
#include "assert.h"

class foo {
    public: 
    void bar() { assert(num != 0); }
    private: 
    int num = 0;
    
    public: 
    foo() = delete;
    foo(int n): num(n) {}
};

using foo_t = std::shared_ptr<foo>;
using foo_w = std::weak_ptr<foo>;

int main () {
    
    foo_t my_foo_t = std::make_shared<foo> (5);
    foo_w my_foo_w = my_foo_t;
    foo_w my_foo_w2 = my_foo_t;
    foo_w my_foo_w3 = my_foo_w; 
    
    
    
}
    
