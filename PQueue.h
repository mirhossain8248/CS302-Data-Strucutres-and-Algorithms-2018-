/*Mir Hossain
Header File for Priority_Queue
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef PQueue_H
#define PQueue_H


struct node{ //This is a substituion to the LinkSortedList
  int priority; //Will be used as a variable to store priority
  std::string data; //Used for data
  struct node *next; //used to point to next item in queue
};


class priorityQueue{
public:
  priorityQueue();
  void enqueue(int priority, std::string item);
  void dequeue();
  void display();
  ~priorityQueue();
  void peekfront();

private:
  node *front;
  node *back;
};

#endif
