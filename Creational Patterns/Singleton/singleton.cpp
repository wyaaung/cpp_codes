#include "singleton.h"

using namespace std;

Singleton *Singleton::get_instance(){
    if (singleton == nullptr){
        singleton = new Singleton();
    }
    
    return singleton;
}
