#include <iostream>

using namespace std;

struct node{
    int value;
    node *next;
    node(int val) : value(val), next(nullptr) {}
};

class Stack{
private:
    node *top;
public:
    Stack(){
        top = nullptr;
    }

    void push(int val){
        node *newnode = new node(val);
        newnode->next = top;
        top = newnode;
    }

    int pop(){
        if(top == nullptr){
            return -1;
        }
        else{
            int val = top->value;
            node *temp = top;
            top = top->next;
            delete temp;
            return val;
        }
    }

    int peek(){
        if(top == nullptr){
            return -1;
        }
        else{
            return top->value;
        }
    }

    void display(){
        for(node *temp = top; temp != nullptr; temp = temp->next){
            cout << temp->value << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    // Push elements onto the stack
    s.push(3);
    s.push(53);
    s.push(45);

    // Display the current state of the stack
    cout << "Stack after pushing elements: ";
    s.display();

    // Pop an element from the stack
    int poppedValue = s.pop();
    cout << "Popped value: " << poppedValue << endl;

    // Push another element onto the stack
    s.push(123);

    // Display the state of the stack after popping and pushing
    cout << "Stack after popping and pushing: ";
    s.display();

    return 0;
}

/*
    A stack is a data structure that follows the Last-In-First-Out (LIFO) principle.
    It means that the last element added to the stack will be the first one to be removed.

    The primary operations of a stack are:
    
    1. push(int val):
        - Adds an element to the top of the stack.
        - Time Complexity: O(1)

    2. pop():
        - Removes and returns the top element from the stack.
        - Returns -1 if the stack is empty.
        - Time Complexity: O(1)

    3. peek():
        - Returns the top element without removing it from the stack.
        - Returns -1 if the stack is empty.
        - Time Complexity: O(1)

    4. display():
        - Displays all the elements in the stack from top to bottom.
        - Time Complexity: O(n)
*/
