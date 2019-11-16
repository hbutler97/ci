#include "graph.h"

GraphCreator::GraphCreator(int numb_nodes, std::string node_string):
  m_numb_nodes(numb_nodes),
  m_input_string(node_string),
  m_root(NULL)
{
  locateColons();
  getNodeStrings();
  getNodeValues();
  getChildren();
  checkChildren();
  createMap();
}

void GraphCreator::checkChildren(void) {

  for(auto x: m_map) {
    std::vector<int>* children = x.second;
    for(int i = 0; i < children->size(); i++) {
      if(m_map.find(children->at(i)) == m_map.end()) {
	  std::cout << "Node: " << children->at(i) << " not in graph" << std::endl;
	  exit(EXIT_FAILURE);
	}
    }
  }
}

void GraphCreator::resetVisit(void) {
  for(auto x: m_node_map)
    x.second->setNodeState(Node::UNVISITED);
  
}
void GraphCreator::locateColons(void) {
  int pos = -1;
  do {
    pos = m_input_string.find(":", pos + 1);
    if(pos != std::string::npos)
      m_colons.push_back(pos);
  } while(pos != std::string::npos);

}

void GraphCreator::getNodeStrings(void) {
  for(int i = 0; i < m_colons.size() ; i++) {
      m_node_strings.push_back(m_input_string.substr(m_colons[i], m_colons[i+1] - m_colons[i]));
  }
}

void GraphCreator::getNodeValues(void) {
  for(auto x: m_node_strings) {
    std::string str = x;
    str.erase(0,1);
    m_node_values.push_back(std::stoi(str.substr(0, str.find(","))));
  }
}

void GraphCreator::createMap(void) {
  
  for(auto it: m_map) 
    m_node_map.insert(std::make_pair(it.first, new Node(it.first)));
  
  for(auto it: m_map) {
    if(m_root == NULL) 
      m_root = m_node_map[it.first];

    Node * node = m_node_map[it.first];
    std::vector<int> *children = it.second;
    
    for(int i = 0; i < children->size(); i++){
      node->addChild(m_node_map[children->at(i)]);
    }
  }


  for(auto y: m_node_map) {
    auto m = y.second->getChildren();
  }
}
void GraphCreator::setRoot(int value){
  if (m_node_map.find(value) == m_node_map.end()){
    std::cout << "Root Not found" << std::endl;
    exit(EXIT_FAILURE);
  }
  m_root = m_node_map.find(value)->second;
}
void GraphCreator::getChildren(void) {
  std::vector<int> commas;
  
  int pos = 0;
  
  for(int z = 0; z < m_node_strings.size(); z++){
    std::string str = m_node_strings[z];
    
    pos = -1;
    do {
      pos = str.find(",", pos + 1);
      if(pos != std::string::npos)
	commas.push_back(pos);
    } while(pos != std::string::npos);

    std::vector<int> *children = new std::vector<int>();
    
    for(int i = 0; i < commas.size();i++) {
      std::string str2 = str.substr(commas[i], commas[i+1] - commas[i]);
      str2.erase(0,1);
      children->push_back(std::stoi(str2));
    }
    
    m_map.insert(std::make_pair(m_node_values[z], children));
    commas.clear();
  }
}
void TreeNode::print_tree(TreeNode *node) {
  print_tree(node, 0);
}

void TreeNode::print_tree(TreeNode *node, int space) {
  if(node == NULL)
    return;

  space += m_count;
  print_tree(node->getRightChild(), space);
  std::cout << std::endl;
  for(int i = m_count; i < space; i++)
    std::cout << " ";
  std::cout << node->getData() << "\n";
  print_tree(node->getLeftChild(), space);
}

void TreeNode::printTree(TreeNode *node) {
  std::deque<TreeNode *> queue;
  
  queue.push_back(node);
  while(!queue.empty()) {
    size_t size = queue.size();
    for(auto x: queue) {
      std::cout << x->getData();
      std::cout << " ";
      if(x->getLeftChild() != NULL)
	queue.push_back(x->getLeftChild());
      if(x->getRightChild() != NULL)
	queue.push_back(x->getRightChild());
    }
    std::cout << std::endl;
    for(int i = 0; i < size; i++)
      queue.pop_front();
  }
}
