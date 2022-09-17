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

Singleton* Singleton::singleton_ = NULL;

Singleton *Singleton::get_instance(){
    if (singleton_ == NULL){
        singleton_ = new Singleton();
    }
    
    return singleton_;
}

Singleton::Singleton(){}

int main(){
    Singleton* s1 = s1->get_instance();
    Singleton* s2 = s2->get_instance();

    bool check = s1 == s2;

    cout << (check ? "They are the same object." : "They are not the same object.") << "\n";
    
    return 0;
}
