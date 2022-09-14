#include "singleton.h"

using namespace std;

int main(){
    Singleton *s1 = Singleton.get_instance();
    Singleton *s2 = Singleton.get_instance();

    bool check = s1 == s2;

    cout << check ? "True" : "False" << "\n";
    
    return 0;
}