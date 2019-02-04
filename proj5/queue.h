/*
Mir Hossain
Proj5
Implementation of Queue
*/

#ifndef Queue_H
#define Queue_H


#include<iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
};

class Queue{

public:
  Queue();
  void push(const int n);
  int pop();
  void display();
  bool checkEmpty() const;
  ~Queue();

private:
  Node *front,*rear;
};

Queue::Queue(){
  front = NULL;
  rear = NULL;
}

void Queue::push(const int n){
  Node *temp = new Node;

  temp->data=n; //Set Data
  temp->next=NULL;

  if(front==NULL){ //Front insert
    front=rear=temp;
  }

  else{
    rear->next=temp;
    rear=temp;
  }

  //cout << n << " pushed" << endl;
}

void Queue::display(){
  Node *temp=front;

  if(front==NULL){
    //cout << "Empty Queue" << endl;
    return;
  }

  while(temp){ //Print out the whole list
    cout << temp->data << " ";
    temp=temp->next;
  }
  cout << endl;
}

int Queue::pop(){
  if (front==NULL){
    //cout << "Empty Queue" << endl;
    return 0;
  }

  //cout << front->data <<" is being deleted " << endl;

  if(front==rear)//if only one node is there
    front=rear=NULL;

  else
    front=front->next;
  return 0;
}

bool Queue::checkEmpty() const{
  if(front == NULL){
    //cout << "Empty Queue" << endl;
    return true;
  }
}

Queue ::~Queue()
{
  while(front!=NULL){
    Node *temp=front;
    front=front->next;
    delete temp;
  }
  rear=NULL;
}

#endif
