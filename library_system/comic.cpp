#include "comic.h"

/*Comic class constructor, inherited from the document*/
Comic::Comic(const char *title, const char *author, int issue, int year, int quantity){
    _title = (char*) malloc((strlen(title)+1) * sizeof(char));
    if(_title == NULL){
        exit(-1);
    } 
    strcpy(_title, title);
    _author = (char*) malloc((strlen(author)+1) * sizeof(char));
    if(_author == NULL){
        exit(-1);
    } 
    strcpy(_author, author);
    updateIssue(issue);
    updateYear(year);
    updateQuantity(quantity);
}

/*Comic class destructor*/
Comic::~Comic(){
    free(_title);
    free(_author);
}

/*getter for the type of the document. Returns DOC_COMIC*/
document_type Comic::getDocumentType(){
    return DOC_COMIC;
}

/*Print function to print  out the title, name of  author, year, issue, and quantity*/
void Comic::print(){
    cout << "Comic, title: " << _title << 
            ", author: " << _author << 
            ", issue: " << _issue << 
            ", year: " << _year << 
            ", quantity: " << _quantity << "\n";
}

/*Setting the name of the author of the comic*/
void Comic::updateAuthor(const char *newAuthor){
    free(_author);
    /* Dynamic Memory Allocation */
    _author = (char*) malloc((strlen(newAuthor)+1) * sizeof(char));
    if(_author == NULL){
        exit(-1);
    } 
    strcpy(_author, newAuthor);
}

/*Setting the issue of the comic*/
void Comic::updateIssue(int newIssue){
    _issue = newIssue;
}

/*getter for the name of the author of the comic*/
char* Comic::getAuthor(){
    return _author;
}

/*getter for the issue of the comic*/
int Comic::getIssue(){
    return _issue;
}
