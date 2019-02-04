/*
Mir Hossain
Driver File for Project 3
This project is just a simple priority queue. The implementations are all on
PQueue.cpp and the class is located in PQueue.h
*/
//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
#include "PQueue.h"

int main(){

  priorityQueue testObject;
  std::cout << "This program is testing a priority queue data structure" << std::endl << "All varibles are static" << std::endl;
  std::cout << std::endl;
  //Using static members to test implementations
  testObject.enqueue(1,"a");
  testObject.enqueue(3,"b");
  testObject.enqueue(5,"i");
  testObject.enqueue(4,"g");
  testObject.enqueue(2,"a");
  testObject.enqueue(6,"i");
  testObject.enqueue(7,"l");
//abigail


  testObject.display();

  std::cout << std::endl;
  std::cout << "Test peekfront";
  testObject.peekfront();
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "Test dequeue" << std::endl;
  for(int i = 0; i < 3; i ++){
  testObject.dequeue();
  }
  std::cout << std::endl;
  testObject.display();

  return 0;
}
