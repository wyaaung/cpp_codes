#include "novel.h"

/*Novel class constructor, inherited from the document*/
Novel::Novel(const char *title, const char *author, int year, int quantity){
    updateYear(year);
    updateQuantity(quantity);
    updateTitle(title);
    updateAuthor(author);
}

/*Novel class destructor*/
Novel::~Novel(){
    _author.erase();
    _title.erase();
}

/*getter for the type of the document. Returns DOC_NOVEL*/
document_type Novel::getDocumentType(){
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
void Novel::updateAuthor(string newAuthor){
    _author = newAuthor;
}

/*getter for the name of the author of the novel*/
string Novel::getAuthor(){
    return _author;
}
