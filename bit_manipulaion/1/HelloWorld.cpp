/*
Remove Dups: Write code to remove duplicates from a unsorted linked list
 */
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include "tclap/CmdLine.h"
#include <bitset>

int main(int argc, char *argv[]) {

  int input_numb(0);  
  try {
    TCLAP::CmdLine *cmd = new TCLAP::CmdLine("Usage",
					     ' ',
					     "1.0");
    
    TCLAP::UnlabeledValueArg<int>  input("numb",
					 "numb",
					 true,
					 16,
					 "numb",
					 *cmd, NULL);
    cmd->parse( argc, argv );
    input_numb = input.getValue();
    
  } catch (TCLAP::ArgException &e)  // catch any exceptions
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE); }
  std::bitset<32> bits(0xAAAAA);
  std::cout << bits << std::endl;
}
  
