#include "library.h"

Library::Library(){
}

/* print the entire library on the standard output, one line per document,
 * in the order they were inserted in the library, using the print()
 * methods implemented by the document objects */
void Library::print(){
    for (Document* doc: _docs){
          doc->print();
    }
}

/* Dump the library in CSV format in a file, the format is: 1 line per
* file:
* <document type>,<title>,<author>,<issue>,<year>,<quantity>*/
int Library::dumpCSV(const char *filename){
    fstream fout;

    if (_docs.size() >= 1){
        fout.open(filename,  ios::out | ios::app);
        for (Document* doc: _docs){
            if (doc->getDocumentType() == DOC_NOVEL){
                Novel* novel = (Novel *) doc;
                fout << "novel," << novel->getTitle() << 
                "," << novel->getAuthor() << ",," 
                << novel->getYear() <<"," << 
                novel->getQuantity() << "\n";
            }
            else if(doc->getDocumentType() == DOC_COMIC){
                Comic* comic = (Comic *) doc;
                fout << "comic," << comic->getTitle() << "," 
                << comic->getAuthor() << "," 
                << comic->getIssue() << "," 
                << comic->getYear() <<"," 
                << comic->getQuantity() << "\n";
            }
            else if (doc->getDocumentType() == DOC_MAGAZINE){
                Magazine* magazine = (Magazine *) doc;
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
Document* Library::searchDocument(const char *title){
      for (Document* doc: _docs){
        if (strcmp(doc->getTitle(),title) == 0){
              return doc;
        }
      }
      return NULL;
}

/* Adding a document to the library, return 0 on success and
 * something else on failure.  */
int Library::addDocument(Document  *d){
      if (d != NULL){
        _docs.push_back(d);
        return 0;
      }
      return -1;
}

/* Deleting a document to the library, return 0 on success and
 * something else on failure.  */
int Library::delDocument(const char *title){
      for (int i=0; i < _docs.size(); i++){
        if (strcmp(_docs.at(i)->getTitle(),title) == 0){
              _docs.erase(_docs.begin() + i);
              return 0;
        }
      }
    return -1;
}

/* Count the number of document of a given type present in the library */
int Library::countDocumentOfType(document_type t){
    int count  = 0;
      for (Document* doc: _docs){
        if (doc->getDocumentType()  == t){
              count += 1;
        }
      }
      return count;
}

/* Borrowing documents, return 0 on success, something else on
 * failure */
int Library::borrowDoc(const char *title){
      for (Document* doc: _docs){
        if (strcmp(doc->getTitle(),title) == 0){
              return doc->borrowDoc();
        }
      }
      return -1;
}

/* Returning documents, return 0 on success, something else on
 * failure */
int Library::returnDoc(const char *title){
      for (Document* doc: _docs){
        if (strcmp(doc->getTitle(),title) == 0){
              doc->returnDoc();
              return 0;
        }
      }
      return -1;
}
