/*
Route between Nodes: Given a directed graph, design an algorithm to find out 
whether there is a route between two nodes
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
Node *node_root = NULL;
void findNodedfs(Node * node, int value);
void findNodebfs(Node * node, int value);
bool findPath(int begin, int end);
int main(int argc, char *argv[]) {

  std::string input_string;
  int numb_nodes, begin_int, end_int;
  
  try {
    TCLAP::CmdLine *cmd = new TCLAP::CmdLine("Usage",
					     ' ',
					     "1.0");
    TCLAP::ValueArg<int>  nodes("n",
				"node",
				"Number of Nodes",
				true,
				0,
				"Integer",
				*cmd,
				NULL);


    TCLAP::ValueArg<int>  begin ("b",
				 "begin",
				 "First Node to find",
				 true,
				 0,
				 "Integer",
				 *cmd,
				 NULL);


    TCLAP::ValueArg<int>  end ("e",
			       "end",
			       "Second Node to Find",
			       true,
				0,
			       "Integer",
			       *cmd,
			       NULL);

    
    TCLAP::UnlabeledValueArg<std::string>  input("InputString",
						 "NodeString",
						 true,
						 "",
						 "Node String",
						 *cmd,
						 NULL);
    cmd->parse( argc, argv );
    input_string = input.getValue();
    numb_nodes = nodes.getValue();
    begin_int = begin.getValue();
    end_int = end.getValue();
  } catch (TCLAP::ArgException &e)  // catch any exceptions
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE); }

  
  Graph *graph = new Graph(numb_nodes, input_string);
  graph->resetGraph();
  Node * root = graph->getRoot();
  graph->setRoot(begin_int);
  root = graph->getRoot();
  findNodedfs(root, end_int);
  graph->resetGraph();
  findNodebfs(root, end_int);
   
}

void findNodebfs(Node * node, int value) {
  std::queue<Node*> queue;

  if(node == NULL) {
    std::cout << " input node is null " << std::endl;
    exit(EXIT_FAILURE);
  }

  queue.push(node);
  while(!queue.empty()){
    Node * node = queue.front();
    if(node->getData() == value) {
      std::cout << "found " << node->getData() << std::endl;
      return;
      
    }
    else {
      for(auto x : node->getChildren()) {
      	if(x->getNodeState() != Node::VISITED)
      	  queue.push(x);
      }
    queue.pop();
    }
    node->setNodeState(Node::VISITED);
  }
}
  
 
void findNodedfs(Node * node, int value) {

  if(node == NULL) {
    std::cout << " input node is null " << std::endl;
    exit(EXIT_FAILURE);
  }

  if(node->getData() == value) {
    std::cout << " found node " << node->getData() << std::endl;
    node_root = node;
  }
  node->setNodeState(Node::VISITED);
  
  for(auto x: node->getChildren()) {
    if(x->getNodeState() != Node::VISITED)
     findNodedfs(x, value);
  }
}
