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

int main(){
    Stack s;
    s.push(3);
    s.push(53);
    s.push(45);
    s.display();
    int i = s.pop();
    s.push(123);
    s.display();
}