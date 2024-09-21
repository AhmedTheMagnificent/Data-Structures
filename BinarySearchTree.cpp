#include <iostream>

using namespace std;

struct node{
    int value;
    node *left;
    node *right;
    node *parent;
    node(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
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
                root->left->parent = root;
            }
            else{
                root->right = insert(val, root->right);
                root->right->parent = root;
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

    node *deleteNode(int val, node *root){
        if(root == nullptr){
            return root;
        }
        else if(val < root->value){
            root->left = deleteNode(val, root->left);
        }
        else if(val > root->value){
            root->right = deleteNode(val, root->right);
        }
        else{
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr){
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                node *temp = root->left;
                delete root;
                return temp;
            }
            else{
                return root;
            }
        }
    }

    int min(node *root){
        if(root->left == nullptr){
            return root->value;
        }
        else{
            return min(root->left);
        }
    }

    int max(node *root){
        if(root->right == nullptr){
            return root->value;
        }
        else{
            return max(root->right);
        }
    }

    int predecessor(int val, node *root){
        return 2;
    }

    int height(node *root){
        if(root == nullptr){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return std::max(left, right) + 1;
    }

    int depth(int val, node *root){
        if(root == nullptr){
            return -1;
        } else if(val < root->value){
            return depth(val, root->left) + 1;
        } else if(val > root->value){
            return depth(val, root->right) + 1;
        } else{
            return 0;
        }
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

    void deleteNode(int val){
        root = deleteNode(val, root);
    }

    int min(void){
        if(root == nullptr){
            throw runtime_error("Tree is empty");
        }
        return min(root);
    }

    int max(void){
        if(root == nullptr){
            throw runtime_error("Tree is empty");
        }
        return max(root);
    }

    int predecessor(int val){
        if(root == nullptr){
            throw runtime_error("Tree is empty");
        }
        return predecessor(val, root);
    }

    int height(){
        if(root == nullptr){
            throw runtime_error("Tree is empty");
        }
        return height(root);
    }
    
    int depth(int val){
        if(root == nullptr){
            throw runtime_error("Tree is empty");
        }
        return depth(val, root);
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
    bst.insert(35);

    cout << "In-order traversal: " << endl;
    bst.inOrderTraversal();
    cout << "Pre-order traversal: " << endl;
    bst.preOrderTraversal();
    cout << "Post-order traversal: " << endl;
    bst.postOrderTraversal();
    cout << "Minimum value: " << bst.min() << endl;
    cout << "Maximum value: " << bst.max() << endl;
    cout << "Height of the tree: " << bst.height() << endl;

    return 0;
}