#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

using namespace std;

/* The different types of documents stored in the library */
typedef enum {
    DOC_NOVEL,
    DOC_COMIC,
    DOC_MAGAZINE
} document_type;

class Document {
    protected:
        string _title;   // document title
        int _year;      // year of publication
        int _quantity;  // quantity held in the library
                        // borrow (-1) and return (-1)
    public:
        virtual document_type getDocumentType() = 0;

        virtual void print() = 0;

        /* Setters and Getters */
        void updateTitle(string newTitle);
        void updateYear(int newYear);
        void updateQuantity(int newQuantity);
        string getTitle();
        int getYear();
        int getQuantity();

        /* Used when someone tries to borrow a document, should return 0 on success
     * and something else on failure */
        int borrowDoc();

        /* Used when someone returns a document */
        void returnDoc();

        /* Virtual Destructor */
        virtual ~Document(){};
};

#endif  /* DOCUMENT_H */
