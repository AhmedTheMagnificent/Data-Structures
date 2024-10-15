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

int main() {
    Queue q;

    // Check if the queue is initially empty
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    // Enqueue elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    // Display the current state of the queue
    cout << "Queue after enqueuing elements: ";
    q.display();

    // Dequeue elements and display the queue
    q.dequeue();
    q.dequeue();
    cout << "Queue after dequeuing two elements: ";
    q.display();

    // Display the size of the queue
    cout << "Current size of the queue: " << q.size() << endl;

    // Clear the queue and check if it's empty
    q.clear();
    cout << "Queue after clearing: " << (q.isEmpty() ? "Empty" : "Not empty") << endl;

    return 0;
}

/*
    A queue is a data structure that follows the First-In-First-Out (FIFO) principle.
    It means that the first element added to the queue will be the first one to be removed.

    The primary operations of a queue are:

    1. enqueue(int val):
        - Adds an element to the end of the queue.
        - Time Complexity: O(1)

    2. dequeue():
        - Removes and returns the front element from the queue.
        - Throws an exception if the queue is empty.
        - Time Complexity: O(1)

    3. isEmpty():
        - Returns true if the queue is empty, otherwise false.
        - Time Complexity: O(1)

    4. size():
        - Returns the number of elements in the queue.
        - Time Complexity: O(n)

    5. clear():
        - Removes all elements from the queue.
        - Time Complexity: O(n)

    6. display():
        - Displays all the elements in the queue from front to rear.
        - Time Complexity: O(n)
*/
