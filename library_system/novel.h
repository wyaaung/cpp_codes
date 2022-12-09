#include "document.h"

class Novel : public Document {
    private:
        string _author;      // author of a novel

    public:
        /* Constructor and Destructor */
        Novel(string title, string author, int year, int quantity);
        ~Novel();

        document_type getDocumentType();
        void print();

        /* getters and setters */
        void updateAuthor(string newAuthor);
        char *getAuthor();
};
