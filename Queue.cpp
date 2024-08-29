#include <iostream>

using namespace std;

struct node{
    int value;
    node *next;
    node(int val) : value(val), next(nullptr) {}
};

class Queue{
private:
    node *head;
    node *tail;
public:
    Queue() {
        head = tail = nullptr;
    }

    void enqueue(int val){
        node *newnode = new node(val);
        if (tail == nullptr){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    int dequeue(){
        if (head == nullptr){
            throw runtime_error("Queue is empty");
        }
        else{
            int val = head->value;
            node *temp = head;
            head = head->next;
            delete temp;
            if(head == nullptr){
                tail = nullptr;
            }
            return val;
        }
    }

    bool isEmpty(){
        return head == nullptr;
    }

    int size(){
        int count = 0;
        for(node *temp = head; temp != nullptr; temp = temp->next){
            count++;
        }
        return count;
    }

    void clear(){
        while(!this->isEmpty()){
            this->dequeue();
        }
    }

    void display(){
        for(node *temp = head; temp != nullptr; temp = temp->next){
            cout << temp->value << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    cout << q.isEmpty() << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.isEmpty() << endl;
    q.enqueue(6);
    cout << q.size() << endl;
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    cout << q.size() << endl;
    q.clear();
    q.isEmpty();
}