/*
Stack Min: Design a stack that has push, pop and min.  all should operate O(1).
 */
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include "tclap/CmdLine.h"
#include <algorithm>


class Stack {
public:
  Stack():
    m_depth(0),
    m_pointer(0),
    m_min_location(0){};
  Stack(const Stack&) = delete;
  ~Stack(){};
  void push(unsigned int value){
    if(m_pointer == m_depth){
      int p_depth = m_depth;
      m_depth += 10;
      m_buffer.resize(m_depth);
      m_min_state.resize(m_depth);
      std::fill(m_buffer.begin() + p_depth, m_buffer.end(), 0);
      std::fill(m_min_state.begin() + p_depth, m_min_state.end(), 0);
      m_depth = m_buffer.size();
    }
    
    m_buffer[m_pointer] = value;
    m_min_location = (m_buffer[m_min_location] < m_buffer[m_pointer])?m_min_location:m_pointer;
    m_min_state[m_pointer] = m_min_location; 
    m_pointer += 1;
  };
  unsigned int pop(void){
    m_pointer -= 1;
    unsigned int value = m_buffer[m_pointer];
    return value;
  };
  unsigned int getMin(void){return m_buffer[m_min_state[m_pointer]];};
  size_t getSize(void){return m_pointer;};
private:
  std::vector<unsigned int> m_buffer;
  std::vector<unsigned int> m_min_state;
  int m_depth;
  int m_pointer;
  int m_min_location;
  
};


int main(int argc, char *argv[]) {

  int input_value;  
  try {
    TCLAP::CmdLine *cmd = new TCLAP::CmdLine("Usage",
					     ' ',
					     "1.0");
    
    TCLAP::UnlabeledValueArg<int>  input("InputString",
						 "unlabeled test",
						 true,
						 0,
						 "nameString",
						 *cmd, NULL);
    cmd->parse( argc, argv );
    input_value = input.getValue();
    
  } catch (TCLAP::ArgException &e)  // catch any exceptions
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE); }

  
  Stack stack;

  for(int i = 0; i < input_value; i++)
    stack.push(rand() % input_value);
 
  size_t numb = stack.getSize();
  for(int i = 0; i < numb; i++) {
    std::cout << "Popped Value: " << stack.pop() << std::endl;
    std::cout << "Min: " << stack.getMin() << std::endl;
  }
}
  
