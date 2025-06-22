# AVL Tree Implementation (C++)

This project implements an AVL Tree in C++. The AVL Tree automatically balances itself using rotations after insertions to ensure optimal search time. The tree supports string insertion, balance factor printing (in-order), and provides a menu-driven interface for interaction.

This project was completed as part of a data structures and algorithms course.

## Technologies
- C++
- Standard Template Library (STL)

## Key concepts
- AVL Tree (self-balancing binary search tree)
- Tree rotations (left, right, left-right, right-left)
- In-order traversal with balance factor reporting
- Pointer-based dynamic data structures

## How to compile and run

### Compile
```
g++ main.cpp AVLTree.cpp Node.cpp -o avl_tree_program
```

### Run
```
./avl_tree_program
```

Example usage with input file:
```
./avl_tree_program < test_inputs/test1.in
```

The program provides a menu:
- `1` to insert a string
- `2` to print in-order balance factors
- `3` to quit

## What I learned
- Implementing AVL Tree insertions with balancing rotations
- Calculating and printing node balance factors
- Managing dynamic memory in tree structures
- Building a menu-driven test interface
