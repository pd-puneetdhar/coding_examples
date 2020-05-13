#include <iostream> 
#include <memory>
#include "assert.h"

class foo {
    public: 
    void bar() { assert(num != 0); num++; std::cout << "num = " << num << std::endl;}
    private: 
    int num = 0;
    
    public: 
    foo() = delete;
    foo(int n): num(n) {}
};

using foo_t = std::shared_ptr<foo>;
using foo_w = std::weak_ptr<foo>;

void copy_shared_ptr( foo_t temp) {
    temp->bar();
}

int main () {
    
    foo_w my_foo_w; 
    {  
        foo_t my_foo_t = std::make_shared<foo> (5);
        my_foo_t->bar();
        my_foo_w = my_foo_t;
        std::cout << " count = " << my_foo_w.use_count() << std::endl;
        auto p = my_foo_w.lock();
        std::cout << " count = " << my_foo_w.use_count() << std::endl;
        p->bar();
        
        copy_shared_ptr(my_foo_t);
    }
    
    std::cout << " count = " << my_foo_w.use_count() << std::endl;
    my_foo_w.lock();
    std::cout << " count = " << my_foo_w.use_count() << std::endl;
     
    
    
}
    
/* OUTPUT
num = 6
 count = 1
 count = 2
num = 7
num = 8
 count = 0
 count = 0


*/
