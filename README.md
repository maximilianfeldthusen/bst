## Documentation

### bst

This C++ code implements a Binary Search Tree (BST). A BST is a data structure that maintains a sorted order of elements, allowing for efficient insertion, deletion, and lookup operations. Let's break down the code step by step.

### Code Breakdown

1. **Includes and Struct Definition:**
   ```cpp
   #include <iostream>

   struct Node {
       int key;
       Node* left;
       Node* right;

       Node(int value) : key(value), left(nullptr), right(nullptr) {}
   };
   ```
   - The `#include <iostream>` directive allows the program to use input/output stream objects.
   - The `Node` struct represents a single node in the BST, containing:
     - An integer `key` that holds the node's value.
     - Pointers `left` and `right` that point to the left and right children of the node, respectively.
     - A constructor initializes the `key`, and sets `left` and `right` to `nullptr`.

2. **Binary Search Tree Class:**
   ```cpp
   class BinarySearchTree {
   public:
       BinarySearchTree() : root(nullptr) {}
   ```
   - The `BinarySearchTree` class manages the tree itself. It has a private member `root` that points to the root node of the BST.
   - The constructor initializes `root` to `nullptr`, indicating an empty tree.

3. **Insertion Method:**
   ```cpp
   void insert(int key) {
       root = insertRec(root, key);
   }

   private:
       Node* insertRec(Node* node, int key) {
           if (node == nullptr) {
               return new Node(key);
           }
           if (key < node->key) {
               node->left = insertRec(node->left, key);
           } else {
               node->right = insertRec(node->right, key);
           }
           return node;
       }
   ```
   - The `insert` method is a public interface for adding a new key to the BST and calls the `insertRec` function.
   - The `insertRec` function is a recursive function that:
     - If the `node` is `nullptr`, it creates a new node with the given `key`.
     - If the `key` is less than the current node's key, it attempts to insert the key in the left subtree.
     - Otherwise, it inserts in the right subtree.

4. **Deletion Method:**
   ```cpp
   void deleteNode(int key) {
       root = deleteRec(root, key);
   }

   Node* deleteRec(Node* root, int key) {
       // Base case
       if (root == nullptr) {
           return root;
       }

       // Recursive calls for ancestors of the node to be deleted
       if (key < root->key) {
           root->left = deleteRec(root->left, key);
       } else if (key > root->key) {
           root->right = deleteRec(root->right, key);
       } else {
           // Node with only one child or no child
           // (If the node has only one child or no child)
           if (root->left == nullptr) {
               Node* temp = root->right;
               delete root;
               return temp;
           } else if (root->right == nullptr) {
               Node* temp = root->left;
               delete root;
               return temp;
           }

           // Node with two children: Get the inorder successor
           Node* temp = minValueNode(root->right);
           root->key = temp->key; // Copy the inorder successor's content to this node
           root->right = deleteRec(root->right, temp->key); // Delete the inorder successor
       }
       return root;
   }
   ```
   - The `deleteNode` method provides a public interface for deleting a key from the BST.
   - The `deleteRec` function handles the deletion recursively:
     - It searches for the node to delete.
     - Once found, it handles three cases:
       1. Node with no children (leaf node).
       2. Node with one child.
       3. Node with two children (finds the inorder successor, copies its value, and deletes the successor).

5. **Helper Functions:**
   ```cpp
   Node* minValueNode(Node* node) {
       Node* current = node;
       while (current && current->left != nullptr) {
           current = current->left;
       }
       return current;
   }
   ```
   - This function finds the node with the minimum value in a subtree.

6. **Inorder Traversal:**
   ```cpp
   void inorder() {
       inorderRec(root);
       std::cout << std::endl;
   }

   void inorderRec(Node* node) {
       if (node != nullptr) {
           inorderRec(node->left);
           std::cout << node->key << " ";
           inorderRec(node->right);
       }
   }
   ```
   - The `inorder` method prints the keys of the BST in sorted order.
   - The `inorderRec` function performs a recursive inorder traversal.

7. **Main Function:**
   ```cpp
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
   ```
   - The `main` function creates an instance of `BinarySearchTree`, inserts several keys, and performs inorder traversal to display the keys in sorted order.
   - It also demonstrates the deletion of nodes and shows the tree's state after each deletion.

### Summary
This code provides a basic implementation of a Binary Search Tree with functionalities for insertion, deletion, and inorder traversal. The recursive methods for insertion and deletion are key to maintaining the properties of the BST, ensuring that all left descendants are less than the node and all right descendants are greater.

