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
    node *insert(int val, node *root){
        if(root == nullptr){
            return new node(val);
        }
        else{
            if(val < root->value){
                root->left = insert(val, root->left);
                root->left->parent = root;
            }
            else{
                root->right = insert(val, root->right);
                root->right->parent = root;
            }
        }
        if(root->parent == "red"){
            
        }
        return root;
    }

public:
    void insert(int val){
        root = insert(val, root);
    }
};