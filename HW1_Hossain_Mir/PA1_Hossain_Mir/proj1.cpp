/*
Mir Hossain
proj1
CS302
*/

/*
This is a simple templated linkedList project where there is a menu for the
user to choose
what they would like to do with data that they enter. The type of the data can
be changed from editing the types in the variable declaration in main. I made
the types int because that feels normal to do.
/*
Note:The spacing is kinda weird because I made the project in a non template
version first then converted it into a template version afterwards.
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
	node<T> *m_head;
	node<T> *m_tail;

public:
	linkedList();
	void insert(T);
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

	 do{
	 cout << endl << "Choose an option";
	 cout << endl << "1.) Push";
	 cout << endl << "2.) Pop";
	 cout << endl << "3.) Show number of elements";
	 cout << endl << "4.) Find first element";
	 cout << endl << "5.) Find last element";
	 cout << endl << "6.) Terminate Program";
	 cout << endl << "Choose an option: ";



	 cin >> option;
	 switch(option)
	 {
		 case 1:
			 cout << "Enter node to be pushed: ";
			 cin >> value;
			 object.insert(value);
			 object.display();
			 count++;
			 break;

		 case 2:
			 object.deleteNode();
			 object.display();
			 count--;
			 break;

		 case 3:
			 cout << endl << "Current number of elements are: " << count;
			 break;

		 case 4:
			 object.getHead();
			 break;

		 case 5:
			 object.getTail();
			 break;

		 case 6:
			 break;

		 default:
		 cout << "Choose an option between 1 and 6" << endl;

		}
	}
	 while(option != 6);
	 return 0;
 }
