#include <iostream>

using namespace std;

struct node{
    int value;
    node *left;
    node *right;
    node *parent;
    node(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinarySearchTree{
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
                int predecessor = max(root->left);
                root->value = predecessor;
                root->left = deleteNode(predecessor, root->left);
            }
        }
        return root;
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
        node *nodeptr = search(val, root);
        if(nodeptr->left != nullptr){
            return max(nodeptr->left);
        }
        node *predecessor = nullptr;
        node *ancestor = root;
        while(ancestor != nodeptr){
            if(nodeptr->value > ancestor->value){
                predecessor = ancestor;
                ancestor = ancestor->right;
            } else{
                ancestor = ancestor->left;
            }
        }
        if (predecessor == nullptr){
            throw runtime_error("No predecessor exists for the given value");
        }
        return predecessor->value;
    }

    int successor(int val, node *root){
        node *nodeptr = search(val, root);
        if(nodeptr->right != nullptr){
            return min(nodeptr->right);
        }
        node *successor = nullptr;
        node *ancestor = root;
        while(ancestor != nodeptr){
            if(nodeptr->value < ancestor->value){
                successor = ancestor;
                ancestor = ancestor->left;
            } else{
                ancestor = ancestor->right;
            }
        }
        if(successor == nullptr){
            throw runtime_error("No successor exists for the given value");
        }
        return successor->value;
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

    node *search(int val, node *root){
        if(root == nullptr){
            return nullptr;
        }
        if(val < root->value){
            return search(val, root->left);
        }
        else if(val > root->value){
            return search(val, root->right);
        }
        else{
            return root;
        }        
    }

public:
    BinarySearchTree(void){
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

    int successor(int val){
        if(root == nullptr){
            throw runtime_error("Tree is empty");
        }
        return successor(val, root);
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
    // Create the Binary Search Tree
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);

    // Perform In-order Traversal
    cout << "In-Order Traversal:" << endl;
    bst.inOrderTraversal();
    cout << endl;

    // Perform Pre-order Traversal
    cout << "Pre-Order Traversal:" << endl;
    bst.preOrderTraversal();
    cout << endl;

    // Perform Post-order Traversal
    cout << "Post-Order Traversal:" << endl;
    bst.postOrderTraversal();
    cout << endl;

    // Find the minimum value in the tree
    cout << "Minimum value in the tree: " << bst.min() << endl;

    // Find the maximum value in the tree
    cout << "Maximum value in the tree: " << bst.max() << endl;

    // Find the predecessor of 15
    try {
        cout << "Predecessor of 15: " << bst.predecessor(15) << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    // Find the successor of 15
    try {
        cout << "Successor of 15: " << bst.successor(15) << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    // Find the predecessor of 20
    try {
        cout << "Predecessor of 20: " << bst.predecessor(20) << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    // Find the successor of 20
    try {
        cout << "Successor of 20: " << bst.successor(20) << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    // Calculate the height of the tree
    cout << "Height of the tree: " << bst.height() << endl;

    // Calculate the depth of a node with value 25
    cout << "Depth of node with value 25: " << bst.depth(25) << endl;

    // Delete a node (with two children)
    cout << "Deleting node with value 30" << endl;
    bst.deleteNode(30);

    // In-order traversal after deletion
    cout << "In-Order Traversal after deletion:" << endl;
    bst.inOrderTraversal();
    cout << endl;

    return 0;
}

/*
    A Binary Search Tree (BST) is a data structure where each node has at most two children, 
    and for each node, the left child's value is less than the node's value, while the right child's value is greater.
    
    The primary operations of a binary search tree are:

    1. insert(int val):
        - Adds a new node with the given value to the BST.
        - Traverses the tree to maintain the BST property (left < root < right).
        - Time Complexity: O(log n) on average, O(n) in the worst case (unbalanced tree).

    2. deleteNode(int val):
        - Removes a node with the given value from the BST.
        - Handles three cases: 
            1. Node has no children (leaf node).
            2. Node has one child.
            3. Node has two children (replace with predecessor or successor).
        - Time Complexity: O(log n) on average, O(n) in the worst case.

    3. search(int val):
        - Searches for a node with the given value in the BST.
        - Traverses left or right depending on whether the value is smaller or larger than the current node.
        - Time Complexity: O(log n) on average, O(n) in the worst case.

    4. min():
        - Returns the minimum value in the BST.
        - Traverses the leftmost path of the tree to find the smallest node.
        - Time Complexity: O(log n) on average, O(n) in the worst case.

    5. max():
        - Returns the maximum value in the BST.
        - Traverses the rightmost path of the tree to find the largest node.
        - Time Complexity: O(log n) on average, O(n) in the worst case.

    6. inOrderTraversal():
        - Traverses the BST in an in-order manner (left-root-right).
        - Displays the values of the nodes in sorted order.
        - Time Complexity: O(n), where n is the number of nodes.

    7. preOrderTraversal():
        - Traverses the BST in a pre-order manner (root-left-right).
        - Displays the values of the nodes in the order of node creation.
        - Time Complexity: O(n).

    8. postOrderTraversal():
        - Traverses the BST in a post-order manner (left-right-root).
        - Displays the values of the nodes after visiting the subtrees.
        - Time Complexity: O(n).

    9. height():
        - Returns the height of the BST.
        - Height is the length of the longest path from the root to any leaf.
        - Time Complexity: O(n) for an unbalanced tree.

    10. predecessor(int val):
        - Returns the predecessor of the given value in the BST (the largest value smaller than val).
        - If the node has a left child, finds the max in the left subtree.
        - Time Complexity: O(log n) on average, O(n) in the worst case.

    11. successor(int val):
        - Returns the successor of the given value in the BST (the smallest value greater than val).
        - If the node has a right child, finds the min in the right subtree.
        - Time Complexity: O(log n) on average, O(n) in the worst case.
*/

