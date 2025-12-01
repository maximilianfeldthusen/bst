
#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteNode(int key) {
        root = deleteRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        std::cout << std::endl;
    }

private:
    Node* root;

    Node* insertRec(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {  // Only insert if the key is not equal to the node's key
            node->right = insertRec(node->right, key);
        }
        // If key == node->key, we do nothing to avoid duplicates
        return node;
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
            root->key = temp->key; // Copy the inorder successor's content to this node
            root->right = deleteRec(root->right, temp->key); // Delete the inorder successor
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            std::cout << node->key << " ";
            inorderRec(node->right);
        }
    }
};

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

