#include <iostream>

using namespace std;

class HousePlan{
    public:
        virtual void setBasement(string basement) = 0;
        virtual void setStructure(string structure) = 0;
        virtual void setRoof(string roof) = 0;
        virtual void setInterior(string interior) = 0;
};

class House : public HousePlan{
    private:
        string basement;
        string structure;
        string roof;
        string interior;

    public:
        void setBasement(string basement) override {
            this->basement = basement;
        }

        void setStructure(string structure) override {
            this->structure = structure;
        }
        
        void setRoof(string roof) override {
            this->roof = roof;
        }

        void setInterior(string interior) override {
            this->interior = interior;
        }
};

class HouseBuilder {
    public:
        virtual void buildBasement() = 0;
        virtual void buildStructure() = 0;
        virtual void buildRoof() = 0;
        virtual void buildInterior() = 0;
        virtual House *getHouse() = 0;
};

class CustomHouseBuilder : public HouseBuilder {
    private:
        House *house;

    public:

        CustomHouseBuilder(){
            this->house = new House();
        }

        void buildBasement() override {
            house->setBasement("Custom Basement");
        }

        void buildStructure() override {
            house->setStructure("Custom Structure");
        }

        void buildRoof() override {
            house->setRoof("Custom Roof");
        }

        void buildInterior() override {
            house->setInterior("Custom Interior");
        }

        House *getHouse() override {
            return this->house;
        }
};

class Engineer {
    private:
        HouseBuilder *houseBuilder;

    public:
        Engineer(HouseBuilder *&houseBuilder){
            this->houseBuilder = houseBuilder;
        }

        House *getHouse(){
            return this->houseBuilder->getHouse();
        }

        void constructHouse(){
            this->houseBuilder->buildBasement();
            this->houseBuilder->buildStructure();
            this->houseBuilder->buildInterior();
            this->houseBuilder->buildRoof();
        }
};


int main(){

    HouseBuilder *builder = new CustomHouseBuilder();

    Engineer *engineer = new Engineer(builder);

    engineer->constructHouse();

    House *house = engineer->getHouse();

    cout << "Builder Constructed: " << house << "\n";

    return 0;
}
