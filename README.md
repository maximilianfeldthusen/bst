


# Binary Search Tree (BST) in C++

This document provides a detailed explanation of a C++ implementation of a **Binary Search Tree (BST)** supporting **insertion**, **deletion**, and **inorder traversal**.

---

## 1. Node Structure

```cpp
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};
````

### Explanation

* **Node**: Represents each element in the BST.
* **key**: The integer value stored in the node.
* **left / right**: Pointers to the left and right child nodes.
* The constructor initializes `left` and `right` to `nullptr`.

---

## 2. `BinarySearchTree` Class

```cpp
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
```

### Explanation

* **root**: Pointer to the root of the BST.
* Constructor sets `root` to `nullptr`, representing an empty tree.

### Public Methods

* **insert(int key)** — Inserts a new key.
* **deleteNode(int key)** — Deletes a node with the given key.
* **inorder()** — Prints the keys in inorder traversal (left → root → right).

### Private Methods

* **insertRec(...)** — Helper for recursive insertion.
* **deleteRec(...)** — Helper for recursive deletion.
* **minValueNode(...)** — Returns the node with the smallest key in a subtree.
* **inorderRec(...)** — Helper for inorder traversal.

---

## 3. Insertion (`insertRec`)

```cpp
Node* insertRec(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insertRec(node->left, key);
    } else if (key > node->key) {
        node->right = insertRec(node->right, key);
    }

    return node;
}
```

### Behavior

* Recursively finds the correct position based on BST rules.
* Inserts the new key in the left or right subtree.
* If the key already exists, insertion is skipped to avoid duplicates.

---

## 4. Deletion (`deleteRec`)

```cpp
Node* deleteRec(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteRec(root->left, key);
    } else if (key > root->key) {
        root->right = deleteRec(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteRec(root->right, temp->key);
    }
    return root;
}
```

### Deletion Cases

1. **No children** → delete node.
2. **One child** → replace node with its child.
3. **Two children**:

   * Find the **inorder successor** (smallest in right subtree).
   * Replace node’s value with successor’s key.
   * Delete successor recursively.

---

## 5. Finding Minimum Node

```cpp
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}
```

### Behavior

* Moves left until reaching the smallest element in the subtree.

---

## 6. Inorder Traversal

```cpp
void inorderRec(Node* node) {
    if (node != nullptr) {
        inorderRec(node->left);
        std::cout << node->key << " ";
        inorderRec(node->right);
    }
}
```

### Behavior

* Prints tree nodes in **ascending order**.

---

## 7. Main Function

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

### What the program does

* Inserts values: **50, 30, 20, 40, 70, 60, 80**
* Displays inorder traversal.
* Deletes **20**, **30**, **50**, showing the updated BST after each deletion.

---

## Output

```
Inorder traversal of the BST: 20 30 40 50 60 70 80
Delete 20
Inorder traversal after deleting 20: 30 40 50 60 70 80
Delete 30
Inorder traversal after deleting 30: 40 50 60 70 80
Delete 50
Inorder traversal after deleting 50: 40 60 70 80
```

---

## Summary

* Implements a **Binary Search Tree** with insertion, deletion, and inorder traversal.
* Uses a node structure with `key`, `left`, and `right` pointers.
* Handles deletion for:

  * Nodes with **0**, **1**, or **2** children.
* Inorder traversal prints values in **ascending order**.

---

```
```
