#include <iostream>

using namespace std;

class Singleton{
    protected:
        static Singleton* singleton_;
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

Singleton *Singleton::get_instance(){
    if (singleton_ == nullptr){
        singleton_ = new Singleton();
    }
    
    return singleton_;
}

int main(){
    Singleton* s1 = s1->get_instance();
    Singleton* s2 = s2->get_instance();

    bool check = s1 == s2;

    cout << (check ? "True" : "False") << "\n";
    
    return 0;
}
