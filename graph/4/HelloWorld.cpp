/*
Minimal Tree: Given a sorted array with unique integer elements, write an algorithm to create a binary tree with minimal heigth
 */
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <queue>
#include "tclap/CmdLine.h"
#include "graph.h"
#include <algorithm>

TreeNode * createBST(std::vector<unsigned int>& vector);
TreeNode * createBST(std::vector<unsigned int>& vector, int start, int end);
int treeHeight(TreeNode * root);
bool isBalanced(TreeNode * root);

int treeHeight(TreeNode * root){
  if(root == NULL)
    return 0;
  return 1 + std::max(treeHeight(root->getLeftChild()),
		      treeHeight(root->getRightChild()));
}
bool isBalanced(TreeNode *root) {
  bool balanced = false;

  if(root == NULL)
    return true;
  if((abs(treeHeight(root->getLeftChild())-
	  treeHeight(root->getRightChild())) <= 1) &&
     isBalanced(root->getLeftChild()) &&
     isBalanced(root->getRightChild())) {
    return true;
  }

  return false;
  
}
int main(int argc, char *argv[]) {

  unsigned int number = 0;

  try {
    TCLAP::CmdLine *cmd = new TCLAP::CmdLine("Usage",
					     ' ',
					     "1.0");
    
    TCLAP::ValueArg<unsigned int>  input("i",
					 "Input",
					 "Array Depth",
					 true,
					 1,
					 "integer",
					 *cmd,
					 NULL);
   
    cmd->parse( argc, argv );
    number = input.getValue();
    
  } catch (TCLAP::ArgException &e)  // catch any exceptions
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE); }

  std::vector<unsigned int> vector;
  
  for(int i = 0; i < number; i++)
    vector.push_back(i);

  TreeNode * root = createBST(vector);
  root->print_tree(root);
  std::cout << "tree height: " << treeHeight(root) << std::endl;
  std::string balanced = (isBalanced(root))?"true":"false";
  std::cout << "Balanced: " << balanced << std::endl; 
}

TreeNode * createBST(std::vector<unsigned int>& vector) {
  return createBST(vector, 0, vector.size() - 1);
}

TreeNode * createBST(std::vector<unsigned int>& vector, int start, int end) {
  int mid = start + (end - start) / 2;

  if(end < start) {
    return NULL;
  }
 
  TreeNode * node = new TreeNode(vector[mid]);
  node->addLeftChild(createBST(vector, start, mid - 1));
  node->addRightChild(createBST(vector, mid + 1, end));
  return node;
}
