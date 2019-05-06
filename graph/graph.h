#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include "tclap/CmdLine.h"



class Node {
public:
  enum NODE_STATE {VISITED, UNVISITED, VISITING};
  Node(int data){m_data=data; m_node_state = UNVISITED;};
  int getData(void){return m_data;};
  void addChild(Node *child){m_children.push_back(child);};
  std::vector<Node *> getChildren(void){return m_children;};
  void setNodeState(NODE_STATE state){m_node_state = state;};
  NODE_STATE getNodeState(void){return m_node_state;};
private:
  int m_data;
  std::vector<Node *> m_children;
  NODE_STATE m_node_state;
};

class GraphCreator {
 public:
  GraphCreator(int numb_nodes, std::string node_string);
  Node * getRoot(void){return m_root;};
  void resetVisit(void);
  void setRoot(int value);
 private:
  int m_numb_nodes;
  std::string m_input_string;
  std::vector<int> m_colons;
  std::vector<std::string> m_node_strings;
  std::vector<int> m_node_values;
  std::unordered_map<int, std::vector<int>*> m_map;
  std::unordered_map<int, Node*> m_node_map;
  Node * m_root;
  void locateColons(void);
  void getNodeStrings(void);
  void getNodeValues(void);
  void getChildren(void);
  void createMap(void);
  void checkChildren(void);
  
  
};
//Graph string representation
//Node Value:child1, child2, child2: Node Value: child1, child2, child3
class Graph {
  public:
  Graph(int numb_nodes, std::string node_string) {
     m_graph_creator = new GraphCreator(numb_nodes, node_string);
  }
  void resetGraph(void){m_graph_creator->resetVisit();};
  Node * getRoot(void){m_graph_creator->getRoot();};
  void setRoot(int value){m_graph_creator->setRoot(value);};
  private:
  GraphCreator * m_graph_creator;
};
