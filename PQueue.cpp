/*Mir Hossain
Implementation file for Priority_Queue
*/
//using namespace std;
#include "PQueue.h"

//Default constructor
priorityQueue::priorityQueue(){

  front = NULL;
  back = NULL;

}

//Displays the priorityQueue
void priorityQueue::display(){
  node *buffer;
  buffer = front;
  if(front == NULL){
    std::cout << "Empty Queue" << std::endl; //Safety Check
  }

  else{
    std::cout << "Queue Display" << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "Priority Value | Value" << std::endl;

    while (buffer != NULL){ //traverse through the set of data
      std::cout << buffer -> priority << "              |" << buffer -> data << std::endl; //just for formatting could've been done better
      buffer = buffer -> next;
    }
  }
}

//Adds an item to the back of the queue
void priorityQueue::enqueue(int priority, std::string item){

  node *bufferData, *queue;

  bufferData = new node;
  bufferData -> data = item;
  bufferData -> priority = priority; //Keeping memory for items in Queue

  if(front == NULL || priority < front -> priority){ //If theres nothing front of queue
    bufferData -> next = front;
    front = bufferData;
  }

  else{
    queue = front;
    while(queue -> next != NULL && queue -> next -> priority <= priority) //Makes sure if the queue isn't empty and orders by priority
      queue = queue -> next;
      bufferData -> next = queue -> next;
      queue -> next = bufferData; //adds a new element
  }
}

//Gets rid of an element from the back of the queue
void priorityQueue::dequeue(){

    node *buffer;
    if(front == NULL){
      std::cout << "Empty Queue" << std::endl;
    }

    else{
      buffer = front;
      std::cout << "Dequeued: " << buffer -> data << std::endl;
      front = front -> next; //Makes next element the new front
      delete buffer; //delete the front
    }
}

priorityQueue::~priorityQueue(){

}

void priorityQueue::peekfront(){

  node *buffer = front;
  std::cout << std::endl << "First Element: " << buffer -> data;

}
