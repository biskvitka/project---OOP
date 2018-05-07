#include "List.h"
#ifndef LIST1_H
#define LIST1_H

template <typename T>
List<T>::List() {
	start = NULL;
	last = NULL;
}

template <typename T>
List<T>::~List() {
	this->clear();
}

template <typename T>
void List<T>::push_front(const T& value) {
	Node* current = new Node;
	assert(current != NULL);

	current->m_data = value;
	current->m_prev = NULL;

	if (start) {
		current->m_next = start;
		start->m_prev = current;
	} else {
		current->m_next = NULL;
		last = current;

	}
	start = current;
}

template <typename T>
void List<T>::push_back(const T& value) {
	Node* current = new Node;
	assert(current != NULL);
	current->m_data = value;
	current->m_next = NULL;

	if (last != NULL) {
		last->m_next = current;
		current->m_prev = last;
	} else {
		start = current;
		current->m_prev = NULL;
	}
	last = current;

}

template <typename T>
T& List<T>::front() {
	return start->m_data;
}

template <typename T>
T& List<T>::back() {
	return last->m_data;

}

template <typename T>
void List<T>::pop_back() {
	if (last == NULL) {
		Node *current = last;
		if (last->m_prev) {
			last = last->m_prev;
			last->m_next = NULL;
		} else {
			last = NULL;
			start = NULL;
		}
		delete current;
	}

}

template <typename T>
void List<T>::pop_front() {
	if (start) {
		Node *current = start;
		if (start->m_next) {
			start = start->m_next;
			start->m_prev = NULL;
		} else {
			this->last = NULL;
			start = NULL;
		}
		delete current;
	}
}

template <typename T>
int List<T>::size() {
	Node* current = start;
	int size = 0;

	while (current != NULL) {
		size++;
		current = current->m_next;
	}
	return size;
}

template <typename T>
bool List<T>::empty() const {
	return start == NULL;
}


template <typename T>
void List<T>::clear(){

	while (last != NULL) {
		this->pop_back();
	}

}

template<typename T>
void List<T>::insert(iterator& it, const T& value) {

	if (it.iter == start) {
		this->push_front(value);
		it.iter = start;
	} else {
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

template<typename T>
void List<T>::erase(iterator& it) {
	if (it.iter == start) {
		this->pop_front();
		it.iter = start;
	} else if (it.iter == last) {
		this->pop_back();
		it.iter = last;
	} else {
		Node* current = it.iter->m_next;
		current->m_prev = it.iter->m_prev;
		delete it.iter;
		it.iter = current->m_prev;
		it.iter->m_next = current;
		it.iter = current;
	}

}

	
#endif
