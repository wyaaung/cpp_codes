#include <iostream>

using namespace std;

class Singleton{
    protected:
        static Singleton* singleton;
        /**
         * Constructor in protected.
         */
        Singleton();

    public:
        /**
         * Singletons should not be cloneable.
         */
        Singleton(Singleton &other) = delete;
        /**
         * Singletons should not be assignable.
         */
        void operator=(const Singleton &) = delete;


        static Singleton *get_instance();
};