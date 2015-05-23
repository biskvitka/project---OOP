#include<iostream>
#include "List.h"
#include"List.cpp"
using namespace std;
int main(){

	List<int> list1;

	list1.push_back(1);
	list1.push_back(3213);
	list1.push_back(3);
	List<int>::iterator it = list1.begin();
	++it;
	//list1 -   1  1111  3213     3 
	cout << *it << endl;
	list1.insert(it, 1111);
	for (it=list1.begin(); it != list1.end(); it++){
		cout << *it << endl;
	}
	cout << "  size: " << list1.size() << "  iterator: " << *it << endl;
	list1.erase(it);
	cout << "  size: " << list1.size() << "  iterator: " << *it << endl;
	cout << "sdfa";
	system("pause");
	return 0;
}
