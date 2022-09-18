#include <iostream>

using namespace std;

// Interface (Abstract Class with pure virtual function)
class Logger {
    public:
        virtual ~Logger(){};
        virtual void log() const = 0;
};

class ConsoleLogger : public Logger {
    public:
        void log() const override{
            cout << "Console Logger" << "\n";
        }
};

class XMLLogger : public Logger {
    public:
        void log() const override{
            cout << "XML Logger" << "\n";
        }
};

class LoggerFactory{
    public:
        virtual ~LoggerFactory(){};
        virtual Logger* getLogger() const = 0;
};

class ConsoleFactory : public LoggerFactory{
    public:
        Logger* getLogger() const override{
            return new ConsoleLogger();
        }
};

class XMLFactory : public LoggerFactory{
    public:
        Logger* getLogger() const override{
            return new XMLLogger();
        }
};

int main(){
    LoggerFactory* loggerFactory = new ConsoleFactory();
    loggerFactory->getLogger()->log();

    LoggerFactory* xmlFactory = new XMLFactory();
    xmlFactory->getLogger()->log();

    return 0;
}
