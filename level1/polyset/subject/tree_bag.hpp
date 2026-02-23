#pragma once

#include "bag.hpp"

class tree_bag : virtual public bag {          // tree_bag inherits from bag
protected:
  struct node {                                // node is a struct that contains a pointer to the left and right nodes and an integer value
    node *l;
    node *r;
    int value;
  };
  node *tree;                                   // tree is a pointer to the root node of the tree
                                                // so it is like a linked list but with 2 pointers instead of one

public:
  tree_bag();                                 // constructor
  tree_bag(const tree_bag &);                 // copy constructor
  tree_bag  &operator=(const tree_bag &);     // assignment operator
  ~tree_bag();                                // destructor

  node *extract_tree();                     // this function extracts the tree from the bag and returns it
  void set_tree(node *);                    // we receive a new tree and we replace the current tree with it

  virtual void insert(int);
  virtual void insert(int *array, int size);
  virtual void print() const;
  virtual void clear();

private:
  static void destroy_tree(node *);           // this function destroys the tree
  static void print_node(node *);             // this function prints the tree
  static node *copy_node(node *);             // this function copies the tree
};
