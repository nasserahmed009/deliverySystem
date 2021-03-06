#include "Node.h"
#include <iostream>
using namespace std;
template <typename T> 
class LinkedList {
private: 
	Node<T>* Head;
	Node <T> * Tail; // to insert in O(1)
public:
	LinkedList(); 
	~LinkedList();
	bool insert_at_end(T item) ; 
	bool remove (T& item); 
	bool removeFront(T& item);
	bool remove_at_end(T& item);
	bool is_empty(); 
	Node<T>* getHead();
	void test(); // to print elements (for test only );
};
template<typename T>
LinkedList<T> ::LinkedList() {
	Head = NULL; 
	Tail = NULL; 
}

template<typename T>
bool LinkedList<T> ::is_empty() {
	if (Head == NULL) return true;
	else return false;
}
template<typename T>
Node<T>* LinkedList<T>::getHead()
{
	return Head;
}

template<typename T>
bool LinkedList <T>::insert_at_end (T item) {
	if (is_empty()) {
	Node<T> *temp = new Node<T>(item);
	Head = temp; 
	Tail = Head; 
	return true;
	}
	else {
		Node <T> *temp = new Node<T>(item);
		Tail->setNext(temp);
		Tail = temp;
		return true;
	}
	return false;
}

template<typename T>
inline bool LinkedList<T>::removeFront(T & item)
{
	if (is_empty()) {
		return false;
	}
	else if (Head == Tail) {
		item = Head->getItem();
		delete Head;
		Head = Tail = NULL;
		return true;
	}
	else {
		Node <T> * temp;
		temp = Head->getNext();
		item = Head->getItem();
		delete Head;
		Head = temp;
		if (!Head) {
			Tail = NULL;
		}
		return true;
	}
	return false;
}

template<typename T>
bool LinkedList<T>::remove_at_end(T &item) { //to remove an order when it's served 
	if (is_empty()) {
		return false;
	}
	else if (Head == Tail ) {
		item = Head->getItem();
		delete Head;
		Head= Tail = NULL;
		return true; 
	}
	else {
		Node <T> * temp;
		temp = Head->getNext();
		item = Head->getItem();
		delete Head;
		Head = temp;
		if (!Head) {
			Tail = NULL;
		}
		return true; 
	}
	return false;
}
template <typename T> 
bool LinkedList <T> ::remove (T &item) { // to delete an order if it's cancelled or promoted to VIP
	Node <T> * temp = Head; 
	if (is_empty()) {
	return false;
	}
	else if (Head->getItem () == item) {
		temp = Head->getNext(); 
		item = Head->getItem(); 
		delete Head;
		Head = temp; 
		if (!Head) {
		Tail =NULL;
		}
		return true;
	}

	else 
	{
	while (temp != NULL ) {
		if (temp->getNext()!= NULL &&  temp->getNext()->getItem() == item) {
			Node <T> * temp2= temp->getNext();
			temp->setNext(temp2->getNext());
			item = temp2->getItem();
			delete temp2;
			if (!temp->getNext()) {
			Tail = Head;
			}
			return true;
		}
		else {
			temp = temp->getNext();
		}
	}
	return false;
	}
}

template <typename T> 
LinkedList<T> ::~LinkedList() {
	while (!is_empty()) {
		T junk;
		remove_at_end(junk);
	}
}
template <typename T>
void LinkedList<T> ::test() {
	if (is_empty()) {
		cout << "no Elements" << endl;
		return;
	}
	Node <T> *temp = Head; 
	while (temp)
	{
		cout << temp->getItem() << "    ";
		temp = temp->getNext();
	}
	cout << endl; 
}
