#include "document.h"

/*Setting the title of the document*/
void Document::updateTitle(string newTitle) {
    _title = newTitle;
}

/*Setting the year of the document*/
void Document::updateYear(int newYear){
    _year = newYear;
}

/*Setting the quantity of the document*/
void Document::updateQuantity(int newQuantity){
    _quantity = newQuantity;
}

/*Getter for the title of the document*/
string Document::getTitle(){
    return _title;
}

/*Getter for the year of the document*/
int Document::getYear(){
    return _year;
}

/*Getter for the quantity of the document*/
int Document::getQuantity(){
    return _quantity;
}

/*Function for borrowing the document. reduces the quantity of the document by one.*/
int Document::borrowDoc(){
    if (_quantity > 0){
        updateQuantity(getQuantity() - 1);
        return 0;
    }
    return -1;
}

/*Function for borrowing the document. increases the quantity of the document by one.*/
void Document::returnDoc(){
    updateQuantity(getQuantity() + 1);
}
