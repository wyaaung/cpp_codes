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

        ~Singleton(){};

        static Singleton *getInstance();
};

Singleton* Singleton::singleton = NULL;

Singleton *Singleton::getInstance(){
    if (singleton == NULL){
        singleton = new Singleton();
    }
    
    return singleton;
}

Singleton::Singleton(){}

int main(){
    Singleton* s1 = s1->getInstance();
    Singleton* s2 = s2->getInstance();

    bool check = s1 == s2;

    cout << (check ? "They are the same object." : "They are not the same object.") << "\n";
    
    return 0;
}
