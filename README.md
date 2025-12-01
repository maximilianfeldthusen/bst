
# Binary Search Tree (BST) in C++

This code implements a **Binary Search Tree (BST)** in C++, which supports insertion, deletion, and inorder traversal.

## 1. **Node Structure:**

```cpp
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

Node: This is the structure that represents each node in the binary search tree.


key: The integer value stored in the node.


left and right: Pointers to the left and right child nodes of the current node.


The constructor Node(int value) initializes the key with the given value and sets both left and right pointers to nullptr.


2. BinarySearchTree Class:
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int key);
    void deleteNode(int key);
    void inorder();
private:
    Node* root;
    Node* insertRec(Node* node, int key);
    Node* deleteRec(Node* root, int key);
    Node* minValueNode(Node* node);
    void inorderRec(Node* node);
};

BinarySearchTree (BST): This class represents the binary search tree itself.


root: A pointer to the root of the tree.


The constructor initializes root to nullptr (empty tree).


Public methods:


insert(int key): Inserts a new node with the given key into the tree.


deleteNode(int key): Deletes the node with the given key from the tree.


inorder(): Prints the tree’s nodes in inorder (left, root, right) traversal order.


Private methods:


insertRec(Node* node, int key): Recursively inserts a new node into the tree.


deleteRec(Node* root, int key): Recursively deletes a node from the tree.


minValueNode(Node* node): Finds the node with the smallest key (used for node deletion).


inorderRec(Node* node): Recursively prints the tree in inorder traversal.


3. Insertion (insertRec):
Node* insertRec(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);  // Create a new node if we've found a null position.
    }

    if (key < node->key) {
        node->left = insertRec(node->left, key);  // Recurse on the left subtree if key is smaller.
    } else if (key > node->key) {
        node->right = insertRec(node->right, key);  // Recurse on the right subtree if key is larger.
    }
    // If key == node->key, we do nothing to avoid duplicates.

    return node;
}

The method insertRec recursively finds the appropriate position for the new node in the BST based on the key.


If the key is smaller than the current node's key, it goes to the left child; if larger, it goes to the right child.


If the key is equal to an existing node's key, it does nothing (to avoid duplicates).


4. Deletion (deleteRec):
Node* deleteRec(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    // Recursively search for the node to delete.
    if (key < root->key) {
        root->left = deleteRec(root->left, key);
    } else if (key > root->key) {
        root->right = deleteRec(root->right, key);
    } else {  // Node to be deleted is found.
        // Node with one or no children.
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
        root->key = temp->key;  // Replace root's key with inorder successor's key.
        root->right = deleteRec(root->right, temp->key);  // Delete the inorder successor.
    }
    return root;
}

This method recursively searches for the node to be deleted.


If the node has one or no children, it is deleted directly.


If the node has two children, the node is replaced by its inorder successor (the smallest node in its right subtree), and then the inorder successor is deleted recursively.


5. Finding Minimum Node (minValueNode):
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

This function finds the node with the minimum key in a given subtree by traversing left until it reaches the leftmost node.


6. Inorder Traversal (inorderRec):
void inorderRec(Node* node) {
    if (node != nullptr) {
        inorderRec(node->left);  // Traverse left subtree.
        std::cout << node->key << " ";  // Visit node.
        inorderRec(node->right);  // Traverse right subtree.
    }
}

This method recursively performs an inorder traversal of the tree, printing each node’s key in order.


7. Main Function:
int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal of the BST: ";
    bst.inorder();

    std::cout << "Delete 20" << std::endl;
    bst.deleteNode(20);
    std::cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    std::cout << "Delete 30" << std::endl;
    bst.deleteNode(30);
    std::cout << "Inorder traversal after deleting 30: ";
    bst.inorder();

    std::cout << "Delete 50" << std::endl;
    bst.deleteNode(50);
    std::cout << "Inorder traversal after deleting 50: ";
    bst.inorder();

    return 0;
}

Inserting Nodes: It inserts several values into the tree (50, 30, 20, 40, 70, 60, 80).


Inorder Traversal: After insertion, it prints the tree in inorder.


Deleting Nodes: The program deletes nodes with keys 20, 30, and 50, and prints the tree after each deletion.


Output:
Inorder traversal of the BST: 20 30 40 50 60 70 80
Delete 20
Inorder traversal after deleting 20: 30 40 50 60 70 80
Delete 30
Inorder traversal after deleting 30: 40 50 60 70 80
Delete 50
Inorder traversal after deleting 50: 40 60 70 80

Summary:
The code defines a Binary Search Tree (BST) with functions for inserting, deleting, and traversing the tree in inorder.


The tree is implemented using a Node structure to store integer values and pointers to left and right children.


Deletion is handled with special cases for nodes with no children, one child, or two children (by replacing the node with its inorder successor).


The inorder function prints the keys in ascending order.


