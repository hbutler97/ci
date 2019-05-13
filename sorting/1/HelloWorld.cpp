/*
Route between Nodes: Given a directed graph, design an algorithm to find out 
whether there is a route between two nodes
 */
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <queue>
#include "tclap/CmdLine.h"

std::vector<int> array;
void loadarray(void);
void bubblesort(void);
void mergesort(void);
void merge(std::vector<int> *array, std::vector<int> *temp, int low, int middle, int high);
void mergesort(std::vector<int> *array, std::vector<int> *temp, int low,int high);
void printarray(void);
void printarray(void) {
  for(auto x: array)
    std::cout << x << std::endl;

  std::cout << std::endl;
}
void loadarray(void) {
  for(int i = 10; i > 0; i--)
    array.push_back(i);
}
void bubblesort(void) {
  int size = array.size();
  for(int i = 0; i < size; i++) {
    for (int k = 0; k < size; k++) {
      if(array[k] > array[k+1]) {
	int temp = array[k+1];
	array[k + 1] = array[k];
	array[k] = temp;
      }
    }
    printarray();
    
  }
}
void mergesort(void) {
  
  std::vector<int>*temp = new std::vector<int>(array.size());
  mergesort(&array,temp, 0, array.size()-1);
}
void merge(std::vector<int> *array, std::vector<int> *temp, int low, int middle, int high){
  for(int i = low; i < high; i++) {
    temp->at(i) = array->at(i);
  }

  int helperleft = low;
  int helperright = middle + 1;
  int current = low;

  while(helperleft <= middle && helperright <= high){
    if(temp->at(helperleft) < temp->at(helperright)) {
      array->at(current) = temp->at(helperleft);
      helperleft++;
    }
    else {
      array->at(current) = temp->at(helperright);
      helperright++;
    }
    current++;
  }

  int remaining = middle - helperleft;
  for(int i = 0; i < remaining; i++) {
    array->at(current + i) = temp->at(helperleft+i);
  }
  /*
  while(helperleft <= middle) {
   array->at(current) = temp->at(helperleft);
    current++;
    helperleft++;
  }
  while(helperright <= high) {
    array->at(current) = temp->at(helperright);
    current++;
    helperright++;
    }*/
}

void mergesort(std::vector<int> *array,std::vector<int> *temp, int low,  int high) {
  
  int middle = low + (high - low)/2;
  //  std::cout << "low: " << low << std::endl;
  //std::cout << "Middle: " << middle << std::endl;
  //std::cout << "High: " << high << std::endl;
 
  if(low < high) {
    mergesort(array, temp, low, middle);
    mergesort(array, temp,  middle + 1, high);
    merge(array, temp, low, middle, high);
  }
  return;
  // exit(0);
}

int main(int argc, char *argv[]) {

  loadarray();
  printarray();
  mergesort();
  printarray();
  
}
