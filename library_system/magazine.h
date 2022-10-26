#include "document.h"

class Magazine : public Document {
    private:
        int _issue;     // issue number of a magazine
    public:
        /* Constructor and Destructor */
        Magazine(const char *title, int issue, int year, int quantity);
        ~Magazine();

        document_type getDocType();
        void print();

        /* getters, setters */
        void updateIssue(int newIssue);
        int getIssue();
};
