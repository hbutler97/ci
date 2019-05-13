/*
Delete Middle Node: Implement and algorith to delete a node in the middle of a singlely linked list
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

//Current input assumes a string of numbers and each number is a node... eg..
//"233" 2->3->3
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
  void deleteNode(int index) {
    if(index == 0) {
      std::cout << "Goal is not to delete the root node" << std::endl;
      exit(EXIT_FAILURE);
    }
    Node *pt = m_head;
    for(int i = 0; i < index - 2; i++){ //go find the element just priot to the one you want to delete
      pt = pt->getNext();
      if(pt == NULL) {
	std::cout << "Index is not in the middle of the list" << std::endl;
	exit(EXIT_FAILURE);
      }
    }
    Node *temp = pt->getNext();
    pt->setNext(temp->getNext());
    delete temp;
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

int main(int argc, char *argv[]) {

  std::string input_string;
  unsigned int kth_element;
  try {
    TCLAP::CmdLine *cmd = new TCLAP::CmdLine("Usage",
					     ' ',
					     "1.0");
    


    TCLAP::UnlabeledValueArg<std::string>  input("InputString",
						 "unlabeled test",
						 true,
						 " ",
						 "nameString",
						 *cmd, NULL);

    TCLAP::UnlabeledValueArg<unsigned int>  kth("kth",
						 "kth",
						 true,
						 0,
						 "kthelement",
						 *cmd, NULL);

    cmd->parse( argc, argv );
    input_string = input.getValue(); //node string
    kth_element = kth.getValue();  //element to delete in that string
    
  } catch (TCLAP::ArgException &e)  // catch any exceptions
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE); }

  
     
  Linked_list list;
  list.addNode(input_string);
  list.printNodes();
  list.deleteNode(kth_element);
  list.printNodes();
}
  
