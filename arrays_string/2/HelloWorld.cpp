/*
Check Permutation: Given two strings decide if one is a permutaiton of the other
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
    
    TCLAP::UnlabeledValueArg<std::string>  input2("InputString2",
						  "unlabeled test",
						  true,
						  " ",
						  "nameString",
						  *cmd, NULL);
    cmd->parse( argc, argv );
    input_string = input.getValue();
    input_string2 = input2.getValue();
    
  } catch (TCLAP::ArgException &e)  // catch any exceptions
    { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; exit(EXIT_FAILURE); }


  std::cout << input_string << " " << input_string2 << std::endl;
  bool is_permute = (input_string.length() ==input_string2.length());

  if(is_permute) {
   
    std::unordered_map<char, unsigned int>  map1, map2;
    for(std::size_t i = 0; i < input_string.length(); i++){
      if(map1.find(input_string[i]) == map1.end())
	map1.insert(std::make_pair<char&, unsigned int>(input_string[i], 1));
      else
	map1[input_string[i]] += 1;

      if(map2.find(input_string2[i]) == map2.end())
	map2.insert(std::make_pair<char&, unsigned int>(input_string2[i], 1));
      else
	map2[input_string2[i]] += 1;
    }


    std::unordered_map<char, unsigned int>::iterator it = map1.begin();

    
    while (it != map1.end() && is_permute){
      char key = it->first;
      if(map1[key] != map2[key])
	is_permute = false;
      it++;
    }

  }

  std::string result = (is_permute)?"yes":"no";
  
  std::cout << result << std::endl;
  
}
  
