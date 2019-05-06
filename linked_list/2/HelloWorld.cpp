/*
Remove Dups: Write code to remove duplicates from a unsorted linked list
 */
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stack>
#include "tclap/CmdLine.h"

class Node {
public:
  Node(int data){m_data=data;m_next = NULL;};
  void setData(int data){m_data = data;};
  int getData(void){return m_data;};
  void setNext(Node *next){m_next = next;};
  Node* getNext(void){return m_next;};
private:
  Node * m_next;
  int m_data;
};

class Linked_list {
public:
  Linked_list():m_head(NULL),
		m_length(0),
		m_length_set(false),
		m_kth_node(NULL){};
  void addNode(Node * node){
    if(m_head == NULL){
      m_head = node;
    } else {
      Node * pt = findEnd(m_head);
      pt->setNext(node);
    }
  }
  Node *getKthNode(int node){
    kthElement(m_head, node, 0);
    return m_kth_node;
  }
   void addNode(int value){
    if(m_head == NULL){
      m_head = new Node(value);
    } else {
      Node * pt = findEnd(m_head);
      pt->setNext(new Node(value));
    }
  }
  void addNode(std::string numbers) {
    Node *pt = NULL;
    
    for(int i = 0; i < numbers.length(); i++) {
      std::string::size_type sz;
      int i_dec = std::stoi (numbers.substr(i,1),&sz);
      if(m_head == NULL){
	m_head = new Node(i_dec);
	pt = m_head;
      }
      else{
	pt = findEnd(pt);
	pt->setNext(new Node(i_dec));
      }
    }
  }
  void printNodes() {
    Node *pt = m_head;
    while(pt != NULL) {
      std::cout << pt->getData() <<  " ";
      pt = pt->getNext();
    }
    std::cout << std::endl;
  }
  Node* kthElement(Node *head, int kth, int index) {

 
    if(m_head == NULL)
      return NULL;
  
    if(head->getNext() == NULL){
      m_length = index;
      return head;
    }
    Node *rt_node = kthElement(head->getNext(), kth, index + 1);
    if(index == m_length - kth)
      m_kth_node = head;

  }
  Node *getHead(void){return m_head;};
private:
  Node *m_head;
  Node *m_kth_node;
  int m_length;
  bool m_length_set;
  Node *findEnd(Node * head){
    if(head == NULL)
      return NULL;
    Node *pt = head;
    while (pt->getNext() != NULL)
      pt = pt->getNext();
    return pt;
  }
};

void build_list(std::string numbers, Node **head);
void print_list(Node * head);
Node *find_kth(Node * head, unsigned int kth);
Node *find_kth_recursion(Node * head, int kth, int depth);

void print_list(Node * head){
  Node* pt = head;
  while(pt != NULL){
    std::cout << pt->getData() <<  " ";
    pt = pt->getNext();
  }
  std::cout << std::endl;
}

void build_list(std::string numbers, Node **head){

  Node *end = NULL;
  
  for(int i = 0; i < numbers.length(); i++) {
    std::string::size_type sz;
    int i_dec = std::stoi (numbers.substr(i,1),&sz);

    if(i == 0){
      *head = new Node(i_dec);
      end = *head;
    }else {
      end->setNext(new Node(i_dec));
      end = end->getNext();
    }
  }
}

int main(int argc, char *argv[]) {

  std::string input_string;
  unsigned int kth_element;
  try {
    TCLAP::CmdLine *cmd = new TCLAP::CmdLine("Usage",
					     ' ',
					     "1.0");
    

    TCLAP::UnlabeledValueArg<unsigned int>  kth("kth",
						 "kth",
						 true,
						 0,
						 "kthelement",
						 *cmd, NULL);

    TCLAP::UnlabeledValueArg<std::string>  input("InputString",
						 "unlabeled test",
						 true,
						 " ",
						 "nameString",
						 *cmd, NULL);
    cmd->parse( argc, argv );
    input_string = input.getValue();
    kth_element = kth.getValue();
    
  } catch (TCLAP::ArgException &e)  // catch any exceptions
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE); }

  
  
  Node * head = NULL;
  build_list(input_string, &head);
    
   
  Linked_list list;
  list.addNode(input_string);
  list.printNodes();
  Node * node = list.getKthNode(3);
  std::cout << node->getData() << std::endl;
}
  
