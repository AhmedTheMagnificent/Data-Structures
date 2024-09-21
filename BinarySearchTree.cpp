#include <iostream>

using namespace std;

struct node{
    int value;
    node *left;
    node *right;
    node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST{
private:
    node *root;
    node *insert(int val, node *root){
        if(root == nullptr){
            return new node(val);
        }
        else{
            if(val < root->value){
                root->left = insert(val, root->left); 
            }
            else{
                root->right = insert(val, root->right);
            }
        }
        return root;
    }

    void inOrderTraversal(node *root){
        if(root == nullptr){
            return;
        }
        inOrderTraversal(root->left);
        cout << root->value << endl;
        inOrderTraversal(root->right);
    }

    void preOrderTraversal(node *root){
        if(root == nullptr){
            return;
        }
        cout << root->value << endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void postOrderTraversal(node *root){
        if(root == nullptr){
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->value << endl;
    }

public:
    BST(void){
        root = nullptr;
    }

    void insert(int val){
        root = insert(val, root);
    }

    void inOrderTraversal(void){
        inOrderTraversal(root);
    }

    void preOrderTraversal(void){
        preOrderTraversal(root);
    }

    void postOrderTraversal(void){
        postOrderTraversal(root);
    }
    
};

int main() {
    BST bst;

    // Insert nodes into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal: " << endl;
    bst.inOrderTraversal();
    cout << "Pre-order traversal: " << endl;
    bst.preOrderTraversal();
    cout << "Post-order traversal: " << endl;
    bst.postOrderTraversal();

    return 0;
}