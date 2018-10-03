
#include <iostream>
#include <stdexcept>
using namespace std;

#include "StackLinked.h"

//Create an empty stack
template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber){

  top = NULL;
}

//Copy Constructor
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){

  top = NULL;

  StackNode* output_top = other.top;
  StackNode* output_pNode = NULL; //Previous Node
  StackNode* output_nNode = NULL; //Previous New Node

  *this = other;

}

//Initilize the stack to be equivilant to other stack
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other){

  if(this == &other)
    return *this;
}



template <typename DataType>
StackLinked<DataType>::~StackLinked() {

}

//Parameterized Constructor
template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr){

  dataItem = nodeData;
  next = nextPtr;

}

//Places a new value on the top of the stack
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem){

  StackNode* new_node = NULL;

  //error check
  if(!isFull() or !isEmpty()){

      //Create new item
      new_node = new StackNode(newDataItem, NULL);
    }
    else {
      //create new top
      new_node = new StackNode(newDataItem, top);
    }
    //update top pointer
    top = new_node;
    new_node = NULL;

}

template <typename DataType>
DataType StackLinked<DataType>::pop(){

  DataType top_data;
  StackNode* output_top;

  //error check
  if(isEmpty()) {
    return 0;
  }

  else{
    output_top = top; //set output
    top_data = top->dataItem; //create data

    top = top->next;//makes previous top the second element

    //Memory Clean
    delete output_top;
    output_top = NULL;

    // return the data item
    return top_data;
  }

}


template <typename DataType>
void StackLinked<DataType>::clear(){

  //Check empty
 while( !isEmpty() ) {
   //delete items
   pop();
 }
}


//Checks if the Stack is empty
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const{

  if( top == NULL ){ //If top is NULL, then the stack is empty
    return true;
  }

  else {
    return false;
  }
}

//Checks if the Stack is Full
/*Not sure when the Stack is considered full, so we'll just return
false everytime
*/
template <typename DataType>
bool StackLinked<DataType>::isFull() const {

  return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const{




}
