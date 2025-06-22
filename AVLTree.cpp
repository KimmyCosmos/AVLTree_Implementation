#include "AVLTree.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Helper: Compute height recursively
static int computed_height(const Node* subtree) {
    if (subtree == nullptr) return 0;
    return max(computed_height(subtree->left), computed_height(subtree->right)) + 1;
}

AVLTree::AVLTree() : root(nullptr) { }

// Get balance factor of a node
int AVLTree::balanceFactor(Node* node) {
    if (!node) return 0;
    int lh = computed_height(node->left);
    int rh = computed_height(node->right);
    return lh - rh;
}

// Right rotation
static Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

// Left rotation
static Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

// Recursive insert helper
static Node* insertHelper(Node* node, const string& key) {
    if (node == nullptr) return new Node(key);

    if (key < node->data)
        node->left = insertHelper(node->left, key);
    else if (key > node->data)
        node->right = insertHelper(node->right, key);
    else {
        ++node->count; // Duplicate key, increment count
        return node;
    }

    int bf = computed_height(node->left) - computed_height(node->right);

    // Left heavy
    if (bf > 1) {
        if (key < node->left->data) {
            // Left Left case
            return rotateRight(node);
        } else if (key > node->left->data) {
            // Left Right case
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    // Right heavy
    if (bf < -1) {
        if (key > node->right->data) {
            // Right Right case
            return rotateLeft(node);
        } else if (key < node->right->data) {
            // Right Left case
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
    // Node is balanced
    return node;
}

// Public insert function
void AVLTree::insert(const string& key) {
    root = insertHelper(root, key);
}

// Print balance factors (in-order, always prints comma/space after each node)
static void printBalanceFactorsHelper(const Node* node) {
    if (!node) return;
    printBalanceFactorsHelper(node->left);
    cout << node->data << "(" << (computed_height(node->left) - computed_height(node->right)) << "), ";
    printBalanceFactorsHelper(node->right);
}

void AVLTree::printBalanceFactors() const {
    printBalanceFactorsHelper(root);
    cout << endl;
}

// Optional: visualizeTree function can stay as is.
void AVLTree::visualizeTree(const Node* subtree, int indent) const {
    for(int i=0; i<indent; ++i) cout << ' ';
    if (subtree == nullptr) {
        cout << "-empty-" << endl;
    } else {
        cout << subtree->data << ' ' << '(' << (computed_height(subtree->left)-computed_height(subtree->right)) << ')' << endl;
        visualizeTree(subtree->left, indent+4);
        visualizeTree(subtree->right, indent+4);
    }
}