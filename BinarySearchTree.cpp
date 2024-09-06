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

    cout << "In-order traversal: ";
    bst.inOrderTraversal();

    return 0;
}