#include <iostream> 
#include <memory>
#include "assert.h"

class foo {
    public: 
    int get_num() { return num; }
    void bar() { assert(num != 0); num++; std::cout << "foo_bar:: num = " << num << std::endl;}
    private: 
    int num = 0;
    
    public: 
    foo() = delete;
    foo(int n): num(n) {}
};

using foo_t = std::shared_ptr<foo>;
using foo_w = std::weak_ptr<foo>;


class foo_dash {
    public: 
    void foo_dash_bar() { assert(num != 0); num++; std::cout << "foo_dash_bar:: num = " << num << std::endl;}
    private: 
    int num = 0;
    
    public: 
    foo_dash() = delete;
    foo_dash(foo_t temp): num(temp->get_num()) {} //constructor with shared pointer argument 
};

void copy_shared_ptr( foo_t temp) {
    temp->bar();
}

int main () {
    
    foo_w my_foo_w; 
    {  
        foo_t my_foo_t = std::make_shared<foo> (5);
        //test foo_dash constructor
        std::shared_ptr<foo_dash> temp_foo_dash = std::make_shared<foo_dash>(my_foo_t);
        temp_foo_dash->foo_dash_bar();
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

/*foo_dash_bar:: num = 6
foo_bar:: num = 6
 count = 1
 count = 2
foo_bar:: num = 7
foo_bar:: num = 8
 count = 0
 count = 0


*/
