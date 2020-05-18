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
    ~foo() { std::cout << __FUNCTION__ << std::endl; }
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

class foo_container {
    public: 
    foo_t temp = std::make_shared<foo>(5);
    
    foo_container() {
        std::cout << "temp use count = " << temp.use_count() << std::endl;
    }
};
    

int main () {
    
    foo_container* temp_fc = new foo_container();
    delete temp_fc;
    
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
    
