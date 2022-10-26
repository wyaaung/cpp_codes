#include <vector>

#include "document.h"

class Library {
    private:
        /* Holds all documents in the library */
        vector<Document *> _docs;

    public:
        Library();

        /* print the entire library on the standard output, one line per document,
        * in the order they were inserted in the library, using the print()
        * methods implemented by the document objects */
        void print();

        /* Dump the library in CSV format in a file, the format is: 1 line per
        * file:
        * <document type>,<title>,<author>,<issue>,<year>,<quantity>*/
        int dumpCSV(const char *filename);

        /* search for a document in the library, based on the title, assuming 
        a title identify uniquely a document in the library*/
        Document *searchDocument(const char *title);

        /* Add/delete a document to/from the library, return 0 on success and
        * something else on failure.  */
        int addDocument(Document *d);
        int delDocument(const char *title);

        /* Count the number of document of a given type present in the library */
        int countDocumentOfType(document_type t);

        /* Borrow/return documents, return 0 on success, something else on
        * failure */
        int borrowDoc(const char *title);
        int returnDoc(const char *title);
};
