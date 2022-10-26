#include "novel.h"

/*Novel class constructor, inherited from the document*/
Novel::Novel(const char *title, const char *author, int year, int quantity){
    updateYear(year);
    updateQuantity(quantity);
    _title = (char*) malloc((strlen(title)+1) * sizeof(char));
    if (_title == NULL) {
        exit(-1);
    }
    strcpy(_title, title);
    _author = (char*) malloc((strlen(author)+1) * sizeof(char));
    if (_author == NULL){
        exit(-1);
    }
    strcpy(_author, author);
}

/*Novel class destructor*/
Novel::~Novel(){
    free(_title);
    free(_author);
}

/*getter for the type of the document. Returns DOC_NOVEL*/
document_type Novel::getDocType(){
    return DOC_NOVEL;
}

/*Print function to print  out the title, name of  author, year, and quantity*/
void Novel::print(){
    cout << "Novel, title: " << _title <<
            ", author: " << _author << 
            ", year: " << _year << 
            ", quantity: " << _quantity << "\n";
}

/*Setting the name of the author of the novel*/
void Novel::updateAuthor(const char *newAuthor){
    free(_author);
    _author = (char*) malloc((strlen(newAuthor)+1) * sizeof(char));
    if(_author == NULL){
        exit(-1);
    } 
    strcpy(_author, newAuthor);
}

/*getter for the name of the author of the novel*/
char* Novel::getAuthor(){
    return _author;
}
