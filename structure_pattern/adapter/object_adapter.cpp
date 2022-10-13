#include <iostream>

using namespace std;

class Framework{
    public:
        virtual void add(int item) = 0;

        virtual ~Framework(){};
};

class OldAPI {
    public:
        void addItem(int item) {
            cout << "Old API addItem " << item << "\n";
        }
};

class ObjectAdapter : public Framework{
    protected:
        OldAPI *oldApi = new OldAPI();

    public:
        void add(int item) override {
            oldApi->addItem(item);
        }
};

int main(int argc, char const *argv[]){

    Framework *framework = new ObjectAdapter();
    framework->add(30);
    
    delete framework;
    
    return 0;
}