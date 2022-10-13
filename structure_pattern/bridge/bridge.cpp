#include <iostream>

using namespace std;

class DrawingAPI {
    public:
        virtual void drawCircle() const = 0;
        virtual void drawRectangle() const = 0;
        
        virtual ~DrawingAPI(){};
};


class SVGDrawerAPI : public DrawingAPI {
    public:
        void drawCircle() const override {
            cout << "SVG Drawing Circle" << "\n";
        }

        void drawRectangle() const override {
            cout << "SVG Drawing Rectangle" << "\n";
        }
};

class CanvasDrawerAPI : public DrawingAPI {
    public:
        void drawCircle() const override {
            cout << "Canvas Drawing Circle" << "\n";
        }

        void drawRectangle() const override {
            cout << "Canvas Drawing Rectangle" << "\n";
        }
};


class Shape{
    protected:
        DrawingAPI *drawingApi;

    public:
        virtual void draw() = 0;

        Shape(DrawingAPI *&drawingApi){
            this->drawingApi = drawingApi;
        }

        virtual ~Shape(){};
};

class Rectangle : public Shape {
    public:
        Rectangle(DrawingAPI *&drawingApi) : Shape(drawingApi){};

        void draw() override {
            this->drawingApi->drawRectangle();
        }
};

class Circle : public Shape {
    public:
        Circle(DrawingAPI *&drawingApi) : Shape(drawingApi){};

        void draw() override {
            this->drawingApi->drawCircle();
        }
};

int main(int argc, char const *argv[]){
    DrawingAPI *draw = new SVGDrawerAPI();

    Shape *s = new Rectangle(draw);
    s->draw();

    draw = new CanvasDrawerAPI();
    s = new Circle(draw);
    s->draw();

    delete s;
    delete draw;

    return 0;
}