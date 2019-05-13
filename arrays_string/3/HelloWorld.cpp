/*
URLify: Wrate a method to replace all spaces in a string with %20.  You may assume that the string has sufficuent space at the end to hold the additional charaters, and that you are givent the true length of the string.
Example:
input:  "Mr John Smith    ", 13
output: "Mr%20John%20Smith"
 */
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include "tclap/CmdLine.h"




std::string urlify(std::string const &input, int numb);

int main(int argc, char *argv[]) {

  std::string input_string, input_string2;
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

  int original_length = input_string.size();
  size_t spaces = std::count(input_string.begin(), input_string.end(), ' ');
  input_string.append((spaces * 3) - spaces, ' ');
  std::cout << urlify(input_string,  original_length) << std::endl;
}
  
std::string urlify(std::string const &input, int numb) {
  std::string urlstring;
  urlstring.append(input.size(), '*');
  int new_index = input.size() -1;
  int old_index = numb-1;

  for(old_index; old_index >= 0; old_index--) {
    if(input[old_index] == ' ') {
      urlstring.replace(new_index, 1, "0");
      new_index = new_index - 1;
      urlstring.replace(new_index, 1,  "2");
      new_index = new_index - 1;
      urlstring.replace(new_index, 1, "%");
      new_index = new_index - 1;
    } else {
      urlstring.replace(new_index, 1, input.substr(old_index,1));
      new_index = new_index - 1;
      
    }
    
  }
  
  return urlstring;
}
