/*
Is Unique:  Implement an algorithm to determine if a string has all unique charaters.  What if if you cannot use additional data structures
 */
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include "tclap/CmdLine.h"

bool present[128];



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


  std::cout << input_string << std::endl;

  int buffer = 128;
  bool bool_vector[buffer]{false};

  bool duplicate = false;

  for(int i = 0; i < input_string.length() && !duplicate; i++){
    if(bool_vector[(int)input_string[i]])
      duplicate = true;
    else
      bool_vector[(int)input_string[i]] = true;
  }

  std::string dup = (duplicate)?"yes":"no";
  std::cout << dup << std::endl;
}
  
