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

        void reverse();

        void push(int); // inserts a new node on the front of the list.

        void append(int);

        void print_list();

        void delete_node(int);

        void delete_node_recursive(int);

        void delete_nth_node(int);

        int get_count();

        int get_count(int);

        int get_count_loop();

        bool search(int);

        bool has_loop();

        Node* get_nth_node(int);

        Node* get_nth_from_last(int);

        Node* get_middle_node();
};


void SinglyLinkedList::reverse(){
    Node* prev = NULL;
    Node* current = head;
    Node* next;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void SinglyLinkedList::push(int new_value){
    Node* new_node = new Node();

    new_node->value = new_value;

    new_node->next = head;

    head = new_node;
    
    return;
}

void SinglyLinkedList::append(int value){
    Node* new_node = new Node();

    if (head == NULL){
        head = new_node;
        return;
    }

    Node* last_node = head;
    while (last_node->next != NULL){
        last_node = last_node->next;
    }

    last_node->next = new_node;

    return;
}

void SinglyLinkedList::print_list(){
    Node* temp = head;

    if (head == NULL) {
        cout << "List empty" << "\n";
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "\n";
}

void SinglyLinkedList::delete_node(int value){
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->value == value){
        *head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->value != value){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        return;
    }

    prev->next = temp->next;

    delete temp;
}

void SinglyLinkedList::delete_node_recursive(int value, Node*& node = head){
    if (head == NULL) {
        cout << "List empty" << "\n";
        return;
    }

    if (head->value == value){
        Node* temp = head;
        head = head->next;
        delete(temp);
        return;
    }

    delete_node_recursive(value, node->next);
}

void SinglyLinkedList::delete_nth_node(int position){
    Node* temp = head;
    Node* prev = NULL;

    if (position == 1){
        *head == head->next;
        free(temp);
        return;
    }
    
    int count = 0;
    while (temp != NULL && count < position){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int SinglyLinkedList::get_count(){
    int count = 0;

    Node* temp = head;

    while (temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

int SinglyLinkedList::get_count(int value){
    int count = 0;

    Node* temp = head;

    while (temp != NULL){
        if (temp->value == value){
            count++;
        }
        temp = temp->next;
    }

    return count;
}

int SinglyLinkedList::get_count_loop(){
    if (head == NULL){
        return 0;
    }

    Node* slow_ptr = head, fast_ptr = head;

    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr){
            int count = 1;
            slow_ptr = slow_ptr->next;

            while (slow_ptr != fast_ptr){
                count++;
                slow_ptr = slow_ptr->next;
            }

            return count;
        }
    }

    return 0;
}

bool SinglyLinkedList::search(int value){
    Node* current = head;

    while (current != NULL){
        if (current->value == value){
            return true;
        }
    }

    return false;
}

bool SinglyLinkedList::has_loop(){
    // Floyd's Cycle-Finding Algorithm
    Node* slow_ptr = head, fast_ptr = head;

    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        
        if (slow_ptr == fast_ptr){
            return true;
        }
    }

    return false;
}

Node* SinglyLinkedList::get_nth_node(int position){
    Node* current = head;

    int count = 0;
    while (current != NULL){
        if (count == position){
            return current;
        }
        count++;
        current = current->next;
    }

    return NULL;
}

Node* SinglyLinkedList::get_nth_from_last(int position){
    if (head == NULL){
        cout << "List is empty" << "\n";
        return;
    }

    Node* main_ptr = head;
    Node* ref_ptr = head;

    for (int i = 0; i < position; i++){
        ref_ptr = ref_ptr->next;
        if (ref_ptr == NULL){
            cout << position 
                 << " is greater than number of nodes in the list"
                 << "\n";
            
            return;
        }
    }

    while (ref_ptr != NULL && ref_ptr->next != NULL){
        ref_ptr = ref_ptr->next;
        main_ptr = main_ptr->next;
    }

    return main_ptr;
}

Node* SinglyLinkedList::get_middle_node(){
    if (head == NULL){
        return head;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    return slow_ptr;
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