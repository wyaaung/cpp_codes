#include "comic.h"

/*Comic class constructor, inherited from the document*/
Comic::Comic(string title, string author, int issue, int year, int quantity) {
    updateTitle(title);
    updateAuthor(author);
    updateIssue(issue);
    updateYear(year);
    updateQuantity(quantity);
}

/*Comic class destructor*/
Comic::~Comic(){
    _author.erase();
    _title.erase();
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
void Comic::updateAuthor(string newAuthor){
    _author = newAuthor;
}

/*Setting the issue of the comic*/
void Comic::updateIssue(int newIssue){
    _issue = newIssue;
}

/*getter for the name of the author of the comic*/
string Comic::getAuthor(){
    return _author;
}

/*getter for the issue of the comic*/
int Comic::getIssue(){
    return _issue;
}
