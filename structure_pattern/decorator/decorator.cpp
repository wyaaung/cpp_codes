#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Decorator Pattern is used to attach new behaviors 
 * to objects by placing these objects inside special wrapper objects that contain the behaviors.
 * 
 * Extending a class is the first thing that comes to mind when you need to alter an object’s behavior. 
 * However, inheritance has several serious caveats that you need to be aware of.
 * 
 * Inheritance is static. You can’t alter the behavior of an existing object at runtime. 
 * You can only replace the whole object with another one that’s created from a different subclass.
 * 
 * Subclasses can have just one parent class.
 * In most languages, inheritance doesn’t let a class inherit behaviors of multiple classes at the same time.
 */

class DataSource {
    protected:
        string data;

    public:
        virtual void writeData(string data) = 0;

        virtual string readData() const = 0;

        virtual ~DataSource(){};
};

class FileDataSource : public DataSource {
    protected:
        string filename;

    public:
        FileDataSource(string filename) {
            this->filename = filename;
        }

        void writeData(string data) override {
            this->data = data;
        }

        string readData() const override {
            return this->data;
        }
};

class Modifier : public DataSource {
    protected:
        DataSource *dataSource;

    public:
        Modifier(DataSource *&dataSource) {
            this->dataSource = dataSource;
        }

        void writeData(string data) override{
            this->dataSource->writeData(data);
        }

        string readData() const override {
            return this->dataSource->readData();
        }
};

class Encryption : public Modifier {
    public:
        Encryption(DataSource *&dataSource) : Modifier(dataSource) {};

        void writeData(string data) override{
            this->dataSource->writeData(
                "Encryption (" + data + ")"
                );
        }

        string readData() const override {
            return this->dataSource->readData();
        }
};

class Compression : public Modifier {
    public:
        Compression(DataSource *&dataSource) : Modifier(dataSource) {};

        void writeData(string data) override{
            this->dataSource->writeData(
                "Compression (" + data + ")"
                );
        }

        string readData() const override {
            return this->dataSource->readData();
        }
};


int main(int argc, char const *argv[]){
    DataSource *simple = new FileDataSource("File One");

    Modifier *encryption = new Encryption(simple);
    Modifier *compression = new Compression(simple);

    encryption->writeData("SAMPLE DATA");
    compression->writeData(encryption->readData());

    cout << compression->readData() << "\n";

    delete compression;
    delete encryption;
    delete simple;
    
    return 0;
}
