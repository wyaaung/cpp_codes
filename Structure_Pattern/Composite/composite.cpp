#include <iostream>
#include <vector>

using namespace std;

class Employee {
    protected:
        string name;
        int id;

    public:
        virtual ~Employee(){};

        virtual void showDetails() const = 0;
};

class Developer : public Employee {
    protected:
        string position;

    public:
        Developer(string name, int id, string position) {
            this->name = name;
            this->id = id;
            this->position = position;
        }

        void showDetails() const override {
            cout << this->id << "\t\t"
                 << this->name << "\t\t"
                 << this->position << "\n";
        }
};

class Supervisor : public Employee {
    protected:
        string position;

    public:
        Supervisor(string name, int id, string position) {
            this->name = name;
            this->id = id;
            this->position = position;
        }

        void showDetails() const override {
            cout << this->id << "\t\t"
                 << this->name << "\t\t"
                 << this->position << "\n";
        }
};

class Directory : public Employee {
    protected:
        vector<Employee*> employees;

    public:
        ~Directory(){
            for (auto& e : employees){
                delete e;
            }
        }

        void showDetails() const override {
            cout << "Id" << "\t\t"
                 << "Name" << "\t\t"
                 << "Position" << "\n";

            for (auto& e : employees){
                e->showDetails();
            }
        }

        void addEmployee(Employee *e) {
            employees.push_back(e);
        }

        void removeEmployee(Employee *e) {
            remove(employees.begin(), employees.end(), e);
        }
};

int main(){
    Developer *d1 = new Developer("Developer 1", 1, "Developer");
    Developer *d2 = new Developer("Developer 2", 2, "Developer");

    Directory *dir = new Directory();
    dir->addEmployee(d1);
    dir->addEmployee(d2);

    Supervisor *sup1 = new Supervisor("Supervisor 1", 1, "Supervisor");
    Supervisor *sup2 = new Supervisor("Supervisor 2", 2, "Supervisor");

    dir->addEmployee(sup1);
    dir->addEmployee(sup2);

    dir->showDetails(); 

    delete dir;

    return 0;
}
