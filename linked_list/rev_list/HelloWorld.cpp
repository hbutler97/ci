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
#include <unordered_map>
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

void build_list(std::string numbers, Node **head);
void print_list(Node * head);
void rev_list(Node **head);

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

void rev_list(Node **head) {
  std::stack<Node*> list;
  Node *temp = *head;
 
  while(temp != NULL) {
    list.push(temp);
    temp = temp->getNext();
  }

  if(list.empty())
    return;
  
  Node *new_list = list.top();
  Node *node_ptr_old = new_list;
  Node *node_ptr_new = new_list;
  node_ptr_new->setNext(NULL);

  while(!list.empty()) {
    node_ptr_new = list.top();
    node_ptr_old->setNext(node_ptr_new);
    node_ptr_old = node_ptr_new;
    list.pop();
  }
  node_ptr_old->setNext(NULL);
  *head = new_list;
}

int main(int argc, char *argv[]) {

  std::string input_string;  
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
    cmd->parse( argc, argv );
    input_string = input.getValue();
    
  } catch (TCLAP::ArgException &e)  // catch any exceptions
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE); }

  
  
  Node * head = NULL;
  build_list(input_string, &head);
  print_list(head);
  rev_list(&head);
  print_list(head);

}
  
