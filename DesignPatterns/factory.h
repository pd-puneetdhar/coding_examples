#pragma once
#include <assert.h>
#include <iostream>>

namespace factory_patter {
    /**************************
     * FACTORY Design Pattern *
     **************************/
    using namespace std;

    //Object Library 
    enum e_object_type {
        e_object_type_a ,
        e_object_type_b ,
        e_object_type_c
    };

    class object_base {
    public:
        void object_method( ) {
            cout << __FUNCTION__ << endl;
        }
    };

    class object_a : public object_base {
    public:
        void object_method( ) {
            object_base::object_method( );
            cout << __FUNCTION__ << endl;
        }

    };

    class object_b : public object_base {
    public:
        void object_method( ) {
            object_base::object_method( );
            cout << __FUNCTION__ << endl;
        }

    };

    class object_c : public object_base {
    public:
        void object_method( ) {
            object_base::object_method( );
            cout << __FUNCTION__ << endl;
        }

    };

    class object_factory {
    public:
        static object_base* Create( e_object_type type );
    };

    object_base* object_factory::Create( e_object_type type ) {

        object_base* obj_ptr = nullptr;
        switch ( type ) {
        case e_object_type_a:
            obj_ptr = new object_a( );
            break;
        case e_object_type_b:
            obj_ptr = new object_b( );
            break;
        case e_object_type_c:
            obj_ptr = new object_c( );
            break;
        default:
            assert( 0 );
        }

        return obj_ptr;
    }


    //User side

    class library_user {
    public:
        library_user( ) {
            e_object_type type = e_object_type_a;
            library_obj = object_factory::Create( type );
        }

        ~library_user( ) {
            if ( library_obj ) {
                delete[ ] library_obj;
                library_obj = NULL;
            }
        }

        object_base* user_method_to_get_object_ptr( ) {
            return library_obj;
        }
    private:
        object_base* library_obj;

    };

    void test_factory_design_pattern( ) {

        library_user* user = new library_user( );
        object_base* obj = user->user_method_to_get_object_ptr( );
        return;
    }
}