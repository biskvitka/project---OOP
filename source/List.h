#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<cassert>
#include<string>

template<typename T>
class List
{
public:
	
	// Node's structure (elements of the list)
	struct Node{
		T m_data;
		Node *m_next, *m_prev;
	};

	// List's functions:
	List();
	~List();
	void push_front(const T& value);
	void push_back(const T& value);
	T& front();
	T& back();
	void pop_back();
	void pop_front();
	int size();
	bool empty() const;
	void clear();

	//
	// Implementation of the iterator class
	//
	class iterator{
	public:
		Node* iter;

		// Konstructor
		iterator() : iter(NULL) {}

		// Operator that returns the value of the node where the iterator points to
		T& operator*(){
			return iter->m_data;
		}

		// Predefinition of prefix operator++ 
		iterator& operator++()
		{
			iter = iter->m_next;
			return *this;
		}

		// Predefinition of postfix operator++
		iterator& operator++(int)
		{
			iterator it = *this;
			iter = iter->m_next;
			
			return it;
			
		}

		// Predefinition of operator!=
		bool operator!=(const iterator& it) const {
			return iter != it.iter;
		}


	};
	 
	//
	// List's funcionts with iterator
	//

	// The iterator goes to the front of the list
	iterator begin(){
		iterator a;
		a.iter = start;
		return a;
	}

	//The iterator goes to the end of the list
	iterator end(){
		iterator a;
		a.iter = _end;
		a++;
		return a;
	}

	// Insert an element where the iterator is
	void insert(iterator& it, const T& value);
	// Erase the elemnt on position iterator
	void erase(iterator& it);

private:
	// Pointers for the end and the beggining of the list
	Node *start, *_end;

};
#endif

