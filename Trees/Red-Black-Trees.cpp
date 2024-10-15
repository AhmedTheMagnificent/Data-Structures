#include <iostream>

using namespace std;

struct node{
    int value;
    string color;
    node *left;
    node *right;
    node *parent;
    node(int val) : value(val), color("RED"), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree{
private:
    node *root;
    node *NIL;
    node *insert(int val, node *root){
        if(root == nullptr){
            return new node(val);
        }
        else{
            if(val < root->value){
                root->left = insert(val, root->left);
                root->left->parent = root;
            } else{
                root->right = insert(val, root->right);
                root->right->parent = root;
            }
        }
        root = fixViolations(root);
        return root;
    }

    node *fixViolations(node *root){
        node *parent = nullptr;
        node *grandparent = nullptr;
        while(root->color == "RED" && root->parent->color == "RED"){
            parent = root->parent;
            grandparent = parent->parent;
            if(parent == grandparent->right){
                node *uncle = grandparent->left;

                if(uncle != nullptr && uncle->color == "RED"){
                    grandparent->color = "RED";
                    parent->color = "BLACK";
                    uncle->color = "BLACK";
                    root = grandparent;
                }

                else if(root == parent->right && uncle->color == "BLACK"){
                    
                }
            }
            else{
                node *uncle = grandparent->right;
                if(uncle != nullptr && uncle->color == "RED"){
                    grandparent->color = "RED";
                    parent->color = "BLACK";
                    uncle->color = "BLACK";
                    root = grandparent;
                }
            }
        }
    }

    void leftRotate(node *x){
        node *y = x->right;
        x->right = y->left;
        if(y->left != NIL){
            y->left->parent = x;
        }
        
    }

public:
    RedBlackTree(void){
        root = nullptr;
    }

    void insert(int val){
        root = insert(val, root);
        root->color = "BLACK";
    }
};