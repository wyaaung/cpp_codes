#include <iostream>

using namespace std;

// Interface (Abstract Class with pure virtual function)
class Logger {
    public:
        virtual void log();
};

class ConsoleLogger : public Logger {
    public:
        void log(){
            cout << "Console Logger" << "\n";
        }
};

class XMLLogger : public Logger {
    public:
        void log(){
            cout << "XML Logger" << "\n";
        }
};

class LoggerFactory{
    public:
        virtual Logger getLogger();
};

