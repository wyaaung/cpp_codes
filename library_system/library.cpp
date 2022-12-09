#include "library.h"

Library::Library(){
}

/* print the entire library on the standard output, one line per document,
 * in the order they were inserted in the library, using the print()
 * methods implemented by the document objects */
void Library::print(){
    for (unique_ptr < Document > & doc: _docs){
          doc->print();
    }
}

/* Dump the library in CSV format in a file, the format is: 1 line per
* file:
* <document type>,<title>,<author>,<issue>,<year>,<quantity>*/
int Library::dumpCSV(string filename){
    fstream fout;

    if (_docs.size() >= 1){
        fout.open(filename,  ios::out | ios::app);
        for (unique_ptr < Document > & doc: _docs){
            if (doc->getDocumentType() == DOC_NOVEL){
                Novel * novel = dynamic_cast < Novel * > (doc.release());
                fout << "novel," << novel->getTitle() << 
                "," << novel->getAuthor() << ",," 
                << novel->getYear() <<"," << 
                novel->getQuantity() << "\n";
            }
            else if(doc->getDocumentType() == DOC_COMIC){
                Comic * comic = dynamic_cast < Comic * > (doc.release());
                fout << "comic," << comic->getTitle() << "," 
                << comic->getAuthor() << "," 
                << comic->getIssue() << "," 
                << comic->getYear() <<"," 
                << comic->getQuantity() << "\n";
            }
            else if (doc->getDocumentType() == DOC_MAGAZINE){
                Magazine * magazine = dynamic_cast < Magazine * > (doc.release());
                fout << "magazine," << magazine->getTitle() << ",," 
                << magazine->getIssue() << "," 
                << magazine->getYear() <<"," 
                << magazine->getQuantity() << "\n";
            }
        }
        fout.close();
        return 0;
      }
    return -1;
}

/* search for a document in the library, based on the title. We assume that
 * a title identify uniquely a document in the library, i.e. there cannote
 * be 2 documents with the same title Returns a pointer to the document if
 * found, NULL otherwise */
Document* Library::searchDocument(string title){
    for (unique_ptr < Document > & doc: _docs){
        if (doc -> getTitle() == title){
            return doc.get();
        }
    }
    return NULL;
}

/* Adding a document to the library, return 0 on success and
 * something else on failure.  */
int Library::addDocument(unique_ptr<Document> & document){
    if (document != NULL){
        _docs.push_back(move(document));
        return 0;
    }
    return -1;
}


/* Adding a document with its type, title, author, year, quantity to the library, return 0 on success and
 * something else on failure.
 */
int Library::addDocument(document_type type, string title, string author,
      int issue, int year, int quantity) {
      unique_ptr < Document > document;
      switch (type) {
            case DOC_NOVEL: {
                  document = make_unique < Novel > (title, author, year, quantity);
                  break;
            }

            case DOC_COMIC: {
                  document = make_unique < Comic > (title, author, issue, year, quantity);
                  break;
            }

            case DOC_MAGAZINE: {
                  document = make_unique < Magazine > (title, issue, year, quantity);
                  break;
            }

            default:
                  return -1;
      }
      return addDocument(document);
}

/* Deleting a document to the library, return 0 on success and
 * something else on failure.  */
int Library::delDocument(string title){
    for (int i=0; i < _docs.size(); i++){
        if (_docs.at(i) -> getTitle() == title){
            _docs.erase(_docs.begin() + i);
            return 0;
        }
    }
    return -1;
}

/* Count the number of document of a given type present in the library */
int Library::countDocumentOfType(document_type type){
    int count  = 0;
    for (unique_ptr < Document > & doc: _docs){
        if (doc->getDocumentType() == type){
            count += 1;
        }
    }
    return count;
}

/* Borrowing documents, return 0 on success, something else on
 * failure */
int Library::borrowDoc(string title){
    for (unique_ptr < Document > & doc: _docs){
        if (doc->getTitle() == title){
            return doc->borrowDoc();
        }
    }
    return -1;
}

/* Returning documents, return 0 on success, something else on
 * failure */
int Library::returnDoc(string title){
    for (std::unique_ptr < Document > & doc: _docs) {
        if (doc -> getTitle() == title) {
            doc -> returnDoc();
            return 0;
        }
    }
    return -1;
}
