#include "magazine.h"

/*Magazine class constructor, inherited from the document*/
Magazine::Magazine(string title, int issue, int year, int quantity){
    updateIssue(issue);
    updateYear(year);
    updateQuantity(quantity);
    updateTitle(title);
}

/*Magazine class destructor*/
Magazine::~Magazine(){
    _title.erase();
}

/*getter for the type of the document. Returns DOC_MAGAZINE*/
document_type Magazine::getDocumentType(){
    return DOC_MAGAZINE;
}

/*Print function to print  out the title, year, issue, and quantity*/
void Magazine::print(){
    cout << "Magazine, title: " << getTitle() <<
            ", issue: " << _issue << 
            ", year: " << _year << 
            ", quantity: " << _quantity << "\n";
}

/*Setting the issue of the Magazine*/
void Magazine::updateIssue(int newIssue){
    _issue = newIssue;
}

/*Getter for the issue of the Magazine*/
int Magazine::getIssue(){
    return _issue;
}
