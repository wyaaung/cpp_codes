#include <iostream>
#include <unordered_map>
#include <functional>

using namespace std;

enum Type{
    RECTANGLE = 0,
    CIRCLE
};

class Shape {
    protected:
        string type;

    public:
        virtual ~Shape(){};
        virtual Shape *clone() const = 0; 
        virtual void printShape() const = 0;
};

class Rectangle : public Shape {
    public:
        Rectangle(){
            this->type = "Rectangle Shape";
        }

        Shape *clone() const override {
            return new Rectangle(*this);
        }

        void printShape() const override{
            cout << this->type << "\n";
        }
};

class Circle : public Shape {
    public:
        Circle(){
            this->type = "Circle Shape";
        }

        Shape *clone() const override {
            return new Circle(*this);
        }

        void printShape() const override{
            cout << this->type << "\n";
        }
};

class ShapeFactory {
    private:
        unordered_map<Type, Shape*, hash<int>> prototypes;

    public:
        ShapeFactory(){
            prototypes[Type::RECTANGLE] = new Rectangle();
            prototypes[Type::CIRCLE] = new Circle();
        }

        ~ShapeFactory(){
            delete prototypes[Type::RECTANGLE];
            delete prototypes[Type::CIRCLE];
        }

        Shape *createShape(Type type){
            return prototypes[type]->clone();
        } 
};


int main(int argc, char const *argv[]){
    ShapeFactory *shapeFactory = new ShapeFactory();

    Shape *shape = shapeFactory->createShape(Type::RECTANGLE);
    shape->printShape();

    shape = shapeFactory->createShape(Type::CIRCLE);
    shape->printShape();

    delete shape;
    delete shapeFactory;
    
    return 0;
}