#include <iostream>

using namespace std;

struct node {
    int value;
    string color;
    node *left;
    node *right;
    node *parent;
    node(int val) : value(val), color("RED"), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    node *root;
    node *NIL;

    node *insert(int val, node *root) {
        if (root == nullptr) {
            return new node(val);
        } else {
            if (val < root->value) {
                root->left = insert(val, root->left);
                root->left->parent = root;
            } else {
                root->right = insert(val, root->right);
                root->right->parent = root;
            }
        }
        root = fixViolations(root);
        return root;
    }

    node *fixViolations(node *root) {
        node *parent = nullptr;
        node *grandparent = nullptr;
        while (root->color == "RED" && root->parent->color == "RED") {
            parent = root->parent;
            grandparent = parent->parent;
            if (parent == grandparent->right) {
                node *uncle = grandparent->left;

                if (uncle != nullptr && uncle->color == "RED") {
                    grandparent->color = "RED";
                    parent->color = "BLACK";
                    uncle->color = "BLACK";
                    root = grandparent;
                } else {
                    if (root == parent->left) {
                        rightRotate(parent);
                        root = parent;
                        parent = root->parent;
                    }
                    parent->color = "BLACK";
                    grandparent->color = "RED";
                    rightRotate(grandparent);
                }
            } else {
                node *uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == "RED") {
                    grandparent->color = "RED";
                    parent->color = "BLACK";
                    uncle->color = "BLACK";
                    root = grandparent;
                }
            }
        }
        return root;
    }

    void leftRotate(node *x) {
        node *y = x->right;
        x->right = y->left;
        if (y->left != NIL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(node *x) {
        node *y = x->left;
        x->left = y->right;
        if (y->right != NIL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->right = x;
        x->parent = y;
    }

    void inOrderTraversal(node *root) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->value << " (" << root->color << ") " << endl;
        inOrderTraversal(root->right);
    }

public:
    RedBlackTree(void) {
        root = nullptr;
        NIL = new node(0); // Sentinel NIL node
        NIL->color = "BLACK"; // NIL is always black
    }

    void insert(int val) {
        root = insert(val, root);
        root->color = "BLACK";
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
    }
};

int main() {
    RedBlackTree rbTree;
    rbTree.insert(10);
    rbTree.insert(20);
    rbTree.insert(30);
    rbTree.insert(15);
    rbTree.insert(25);

    cout << "In-order Traversal of the Red-Black Tree:" << endl;
    rbTree.inOrderTraversal();

    return 0;
}
