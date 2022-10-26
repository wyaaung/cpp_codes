#include "document.h"

class Novel : public Document {
    private:
        char *_author;      // author of a novel

    public:
        /* Constructor and Destructor */
        Novel(const char *title, const char *author, int year, int quantity);
        ~Novel();

        document_type getDocType();
        void print();

        /* getters and setters */
        void updateAuthor(const char *newAuthor);
        char *getAuthor();
};
