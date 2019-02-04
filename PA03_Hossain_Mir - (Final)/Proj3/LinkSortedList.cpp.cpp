/*
Mir Hossain
LinkSortedList
CS302
*/



#include <iostream>
#include <stdlib.h>
using namespace std;

/*
nodeData is just going to be used for the data and traversal of the list
*/
template <class T>
struct node{
	T data;
	struct node<T> *m_next;
};

template<class T>
class linkedList{

private:
	node<T>* m_head;
	node<T>* m_tail;

public:
	linkedList();
	void insert(T number);
	void deleteNode();
	void display();
	void getHead();
	void getTail();
};

//Default constructor
template<class T>
linkedList<T>::linkedList(){

	m_head = NULL;
	m_tail = NULL;

}

//Push function for linked list
template<class T>
void linkedList<T>::insert(T number){

	node<T> *buffer = new node<T>; //create a buffer
	buffer -> data = number; // place value
	buffer -> m_next = m_head;
	m_head = buffer; //creates new head

}

//Pop function
template<class T>
void linkedList<T>::deleteNode(){

	node<T> *buffer = m_head; //Make buffer to head
	m_head = m_head -> m_next; //Make next value the new head
	delete buffer;
}
//Gets head of linked list
template<class T>
void linkedList<T>::getHead(){

	node<T> *buffer = m_head; //set value to buffer

	cout << endl <<"First element: " << buffer -> data;
}

//Gets tail of list
template<class T>
void linkedList<T>::getTail(){

	int tail = 0;
	node<T> *buffer = m_head;
	while(buffer != NULL) //while buffer is true
	{
		tail = buffer -> data; //set value
		buffer = buffer -> m_next; //traverse the list
		//tail = buffer;
		//cout << endl << "Last Element: " << tail -> data;

	}

 cout << endl << "Last Element: " <<  tail;

}
//Display the linked list
template<class T>
void linkedList<T>::display(){

	node<T> *buffer = m_head; //set value to buffer
	cout << endl << "Current LinkedList:";

	while(buffer != NULL)
	{
		cout << " " << buffer -> data; //Display the list
		buffer = buffer -> m_next; //as it traverses
	}

}



 int main() {

	 int value;
	 int option = 1;
	 linkedList<int> object;
	 int count = 0;


	 return 0;
 }
