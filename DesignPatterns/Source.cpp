using namespace std;

enum object_type {
    object_type_a, 
    object_type_b,
    object_type_c
};

class object_base_class {
public: 
    virtual void object_method( ) = 0;
    static object_base_class* Create( objType type );
};

class object_of_type_a : public object_base_class {
public: 
    void object_method( ) {
        cout << __FUNCTION__ << " object_of_type_a " << endl;
    }
};


