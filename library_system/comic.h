#include "document.h"

class Comic : public Document {
    private:
        char *_author;      // author of a comic
        int _issue;         // issue number of a comic

    public:
        /* Constructor and Destructor */
        Comic(const char *title, const char *author, int issue, int year, int quantity);
        ~Comic();

        document_type getDocumentType();
        void print();

        /* getters, setters */
        void updateAuthor(const char *newAuthor);
        void updateIssue(int newIssue);
        char *getAuthor();
        int getIssue();
};
