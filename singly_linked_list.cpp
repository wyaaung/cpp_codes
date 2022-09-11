#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;

        // Default constructor
        Node(){
            value = 0;
            next = NULL;
        }

        // Parameterised Constructor
        Node(int value) {
            this->value = value;
            this->next = NULL;
        }
};


// Singly Linked List
class SinglyLinkedList{
    Node* head;
    
    public:

        SinglyLinkedList() { head = NULL; }
        
        // inserts a new node on the front of the list.
        void push(int);

        void print_list();

        void delete_node(int);


};


void SinglyLinkedList::push(int new_value){
    Node* new_node = new Node();

    new_node->value = new_value;

    new_node->next = head;

    head = new_node;
}

void SinglyLinkedList::print_list(){
    Node* temp = head;

    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    SinglyLinkedList list;
  
    // Inserting nodes
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);

    list.print_list();
}