#include <iostream>

using namespace std;

struct node{
    int value;
    node *next;
    node(int val) : value(val), next(nullptr) {}
};

class SinglyLinkedList{
private:
    node *head;
public:
    SinglyLinkedList(void){
        head = nullptr;
    }

    void insertAtBeginning(int val){
        node *newnode = new node(val);
        if(!head){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }

    void insertAtEnd(int val){
        node *newnode = new node(val);
        if(!head){
            head = newnode;
        }
        else{
            node *nodeptr = head;
            while(nodeptr->next){
                nodeptr = nodeptr->next;
            }
            nodeptr->next = newnode;
        }
    }

    void insertAt(int n, int val){
        int pos = 0;
        if(n == 0){
            insertAtBeginning(val);
        }
        node *nodeptr = head;
        node *newnode = new node(val);
        while(pos < n - 1){
            pos++;
            nodeptr = nodeptr->next;
        }
        newnode->next = nodeptr->next;
        nodeptr->next = newnode;
    }

    void reverse(void){
        node *prev, *curr, *next;
        prev = next = nullptr;
        curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display(void){
        for(node *temp = head; temp != nullptr; temp = temp->next){
            cout << temp->value << " ";
        }
        cout << endl;
    }
};

int main(){
    SinglyLinkedList L1;
    L1.insertAtEnd(1000);
    L1.insertAtBeginning(1);
    L1.insertAtBeginning(4);
    L1.insertAtBeginning(5);
    L1.insertAtBeginning(6);
    L1.insertAtBeginning(7);
    L1.insertAtEnd(2);
    L1.display();
    L1.insertAtEnd(3);
    L1.insertAtEnd(4);
    L1.insertAt(4, 99);
    L1.insertAt(8, 1000);
    L1.display();
    L1.reverse();
    L1.display();
}