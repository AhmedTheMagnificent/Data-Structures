#include <iostream>

using namespace std;

struct node{
    int value;
    node *next;
    node *prev;
    node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList{
private:
    node *head;
    node *tail;
public:
    DoublyLinkedList(void){
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int val){
        node *newnode = new node(val);
        if(!head){
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void insertAtEnd(int val){
        node *newnode = new node(val);
        if(!tail){
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
    }

    void display(){
        for(node *temp = head; temp != nullptr; temp = temp->next){
            cout << temp->value << " ";
        }
        cout << endl;
    }
};