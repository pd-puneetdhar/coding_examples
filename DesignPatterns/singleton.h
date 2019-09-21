#pragma once
namespace singleton_pattern {
    //LIBRARY
    class singleton {
    private:
        //Lazy instantiation, singleton instance will not be created until and unless requested by user code
        static singleton* singleton_object;

    private:
        singleton( ) { }

    public:
        //Problem with having static functions is that multiple threads could call this library function conccurently
        static singleton* getInstance( ) {
            if ( singleton_object == nullptr ) {
                //Generally the lazy instantion is used with Singleton
                singleton_object = new singleton( );
            }
            return singleton_object;
        }
    };

    //USER
    class library_user {

    };

}