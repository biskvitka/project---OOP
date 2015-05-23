#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<cassert>


template<typename T>
class List
{
public:
	//node's structure (elements of the list)

	struct Node{
		T m_data;
		Node *m_next, *m_prev;
	};

	//List's functions
	List();//fine
	~List();//fine
	void push_front(const T& value);//fine
	void push_back(const T& value);//fine
	T& front();//fine
	T& back();//feni
	void pop_back();//fine
	void pop_front();//fine
	int size();//fine
	bool empty() const;//fine
	void clear();//fine


	//implementation of the iterator class
	class iterator{
	public:
		Node* iter;
		//konstructor
		iterator() : iter(NULL) {}
		// operator that returns the value of the node where the iterator points to
		T& operator*(){
			return iter->m_data;
		}
		iterator & operator++()
		{
			iter = iter->m_next;
			return *this;
		}
		iterator& operator++(int)
		{
			iterator it = this;
			++this;
			return it;
			
		}

		bool operator!=(const iterator& it) const {
			return iter != it.iter;
		}


	};
	//fine
	iterator begin(){
		iterator a;
		a.iter = start;
		return a;
	}
	//fine
	iterator end(){
		iterator a;
		a.iter = _end;
		return a;
	}
	void insert(iterator& it, const T& value);
	void erase(iterator& it);

private:
	Node *start, *_end;

};
#endif

