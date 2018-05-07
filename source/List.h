#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<cassert>
#include<string>

template<typename T>
class List {
public:
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

	struct Node {
		T m_data;
		Node *m_next, *m_prev;
	};
	
    class iterator{
	public:
    	Node* iter;

		iterator() : iter(NULL) {}

		T& operator*() {
			return iter->m_data;
		}

		iterator& operator++() {
			iter = iter->m_next;
			return *this;
		}

		iterator& operator++(int) {
			iterator it = *this;
			iter = iter->m_next;
			return it;
		}

		bool operator!=(const iterator& it) const {
			return iter != it.iter;
		}


	};
	 
	iterator begin(){
		iterator a;
		a.iter = start;
		return a;
	}

	iterator end(){
		iterator a;
		a.iter = last;
		a++;
		return a;
	}

	void insert(iterator& it, const T& value);
	void erase(iterator& it);

private:
	Node *start, *last;

};
#endif

