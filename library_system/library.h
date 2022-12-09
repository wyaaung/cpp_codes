#include <vector>
#include <fstream>
#include <memory>

#include "magazine.h"
#include "novel.h"
#include "comic.h"

class Library {
    private:
        /* Holds all documents in the library */
        vector<unique_ptr<Document>> _docs;

    public:
        Library();

        /* print the entire library on the standard output, one line per document,
        * in the order they were inserted in the library, using the print()
        * methods implemented by the document objects */
        void print();

        /* Dump the library in CSV format in a file, the format is: 1 line per
        * file:
        * <document type>,<title>,<author>,<issue>,<year>,<quantity>*/
        int dumpCSV(string filename);

        /* search for a document in the library, based on the title, assuming 
        a title identify uniquely a document in the library*/
        Document *searchDocument(string title);

        /* Add/delete a document to/from the library, return 0 on success and
        * something else on failure.  */
        int addDocument(document_type t, string title, string author, int issue,
                    int year, int quantity);
        int addDocument(unique_ptr<Document> & document);
        int delDocument(string title);

        /* Count the number of document of a given type present in the library */
        int countDocumentOfType(document_type type);

        /* Borrow/return documents, return 0 on success, something else on
        * failure */
        int borrowDoc(string title);
        int returnDoc(string title);
};
