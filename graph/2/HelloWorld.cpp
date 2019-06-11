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


TreeNode * createBST(std::vector<unsigned int>& vector);
TreeNode * createBST(std::vector<unsigned int>& vector, int start, int end);
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
  
}

TreeNode * createBST(std::vector<unsigned int>& vector) {
  return createBST(vector, 0, vector.size() - 1);
}

TreeNode * createBST(std::vector<unsigned int>& vector, int start, int end) {
  int mid = start + (end - start) / 2;

  if(end < start) {
    std::cout << "***Bottom: "<< "start: " << start << " mid: " << mid << " end: " << end << std::endl;
    return NULL;
  }
  
 

  TreeNode * node = new TreeNode(vector[mid]);
  std::cout << "Left: "<< "start: " << start << " mid: " << mid << " end: " << end << std::endl;
  node->addLeftChild(createBST(vector, start, mid - 1));
  std::cout << "Right: "<< "start: " << start << " mid: " << mid << " end: " << end << std::endl;
  node->addRightChild(createBST(vector, mid + 1, end));
  return node;
}
