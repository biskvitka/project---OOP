#include "List.h"
#ifndef LIST1_H
#define LIST1_H


// Construktor
template <typename T>
List<T>::List()
{
	start = NULL;
	_end = NULL;
}

// Destructor
template <typename T>
List<T>::~List(){
	this->clear();
}


// Adds element to the front of the list
template <typename T>
void List<T>::push_front(const T& value){
	Node* current = new Node;
	assert(current != NULL);

	current->m_data = value;
	current->m_prev = NULL;

	if (start){
		current->m_next = start;
		start->m_prev = current;
	}
	else{
		current->m_next = NULL;
		_end = current;

	}
	start = current;
}

// Adds a node to the end of the list
template <typename T>
void List<T>::push_back(const T& value){
	Node* current = new Node;
	assert(current != NULL);
	current->m_data = value;
	current->m_next = NULL;

	if (_end != NULL){
		_end->m_next = current;
		current->m_prev = _end;
	}
	else
	{
		start = current;
		current->m_prev = NULL;
	}
	_end = current;

}

// Shows the element at the beginning of the list
template <typename T>
T& List<T>::front() {
	return start->m_data;
}

// Shows the element at the end of the list
template <typename T>
T& List<T>::back(){
	return _end->m_data;

}

// Deletes the last element of the list
template <typename T>
void List<T>::pop_back(){
	if (_end)
	{
		Node *current = _end;
		if (_end->m_prev)
		{
			_end = _end->m_prev;
			_end->m_next = NULL;
		}
		else{
			_end = NULL;
			start = NULL;
		}
		delete current;
	}

}

// Delete the first element of the list
template <typename T>
void List<T>::pop_front(){
	if (start)
	{
		Node *current = start;
		if (start->m_next){
			start = start->m_next;
			start->m_prev = NULL;
		}
		else{
			_end = NULL;
			start = NULL;
		}
		delete current;
	}
}

// Gives the size of the list
template <typename T>
int List<T>::size(){
	Node* current = start;
	int size = 0;

	while (current != NULL){
		size++;
		current = current->m_next;
	}
	return size;
}

// Is the list empty?
template <typename T>
bool List<T>::empty() const{
	return start == NULL;
}


// Deletes the nodes of the list
template <typename T>
void List<T>::clear(){

	while (_end != NULL){
		this->pop_back();
	}

}

//
// Functions with the iterator:
//

// Insert an element on position iterator
template<typename T>
void List<T>::insert(iterator& it, const T& value){

	if (it.iter == start){
		this->push_front(value);
		it.iter = start;
	}
	else{
		Node *current = it.iter;
		it.iter = new Node;
		assert(it.iter != NULL);
		it.iter->m_next = current;
		it.iter->m_prev = current->m_prev;
		current->m_prev = it.iter;
		current = it.iter->m_prev;
		current->m_next = it.iter;
		it.iter->m_data = value;
	}

}


// Function that let the user erese the element on position iterator

template<typename T>
void List<T>::erase(iterator& it){
	if (it.iter == start)
	{
		this->pop_front();
		it.iter = start;
	}
	else if (it.iter == _end)
	{
		this->pop_back();
		it.iter = _end;
	}
	else{
		Node* current = it.iter->m_next;
		current->m_prev = it.iter->m_prev;
		delete it.iter;
		it.iter = current->m_prev;
		it.iter->m_next = current;
		it.iter = current;
	}

}

	
#endif LIST1_H
