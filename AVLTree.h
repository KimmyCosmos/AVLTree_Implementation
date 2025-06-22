#pragma once
#include <string>

#include "Node.h"

class AVLTree{
  private:
    Node *root;
    void visualizeTree(const Node* subtree, int indent=0) const;
  public:
    AVLTree();

    // TURD: These two are required functions
    void insert(const std::string&);
    int balanceFactor(Node*);
    // TURD: You also need this to pass the test
    // TURD: It does an in-order traversal and
    // TURD: prints out all the data keys and their
    // TURD: balance factors.  It should be const
    // TURD: E.g. alpha(0), bravo(-1), charlie(0), hotel(1), india(1), ...
    void printBalanceFactors() const;

    // TURD: These may be helpful (but you can delete)
    bool search(const std::string&); 
    std::string largest() const;
    std::string smallest() const;
    int height(const std::string&) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    
    // TURD: I've written this one for you.  It just shows parts of the tree
    // TURD: Good for debugging as you go.  You make delete or keep
    void visualizeTree() const { visualizeTree(root); }
};
