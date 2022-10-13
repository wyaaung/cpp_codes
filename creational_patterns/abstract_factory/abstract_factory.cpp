#include <iostream>

using namespace std;

// Related to Factory Method Design
// Factory Method Design -> Hide the object creation of a class
// Abstract Factory Method Design -> Hide the object creation of a family of classes

class Button{
    public:
        virtual ~Button(){};
        virtual void print() const = 0;
};

class WindowsButton : public Button{
    public:
        void print() const override{
            cout << "Windows Button" << "\n";
        }
};

class MacintoshButton : public Button{
    public:
        void print() const override{
            cout << "Macintosh Button" << "\n";
        }
};

class Label{
    public:
        virtual ~Label(){};
        virtual void print() const = 0;
};

class WindowsLabel : public Label{
    public:
        void print() const override{
            cout << "Windows Label" << "\n";
        }
};

class MacintoshLabel : public Label{
    public:
        void print() const override{
            cout << "Macintosh Label" << "\n";
        }
};

class GUIBuilder {
    public:
        virtual Button  *createButton() const = 0;
        virtual Label *createLabel() const = 0;

        virtual ~GUIBuilder(){};
};

class WindowsGUIBuilder : public GUIBuilder{
    public:
        Button *createButton() const override{
            return new WindowsButton();
        }

        Label *createLabel() const override{
            return new WindowsLabel();
        }
};

class MacintoshGUIBuilder : public GUIBuilder{
    public:
        Button *createButton() const override{
            return new MacintoshButton();
        }

        Label *createLabel() const override{
            return new MacintoshLabel();
        }
};


int main(int argc, char const *argv[]){
    GUIBuilder *gui = new WindowsGUIBuilder();
    gui->createButton()->print();
    gui->createLabel()->print();

    delete gui;

    return 0;
}