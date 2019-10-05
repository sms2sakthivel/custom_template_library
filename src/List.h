/*
 * List.h
 *
 *  Created on: Oct 5, 2019
 *      Author: Sakthivel Ganesan
 */

#ifndef LIST_H_
#define LIST_H_

namespace custom
{
template <typename T>
class List
{
	int _size,_capacity;
	T *_container, *_temp;
	bool re_size();
public:
	List();
	~List();
	T at(int pos);
	bool assign(int pos, T value);
	bool insert(int pos, T value);
	bool push_back(T value);
	bool push_front(T value);
	bool remove(int pos);
	bool pop_back();
	bool pop_front();
	bool empty();
	int size();
	int capacity();
	T* begin();
	T* end();
	bool reverse();
	void print();
};
}



#endif /* LIST_H_ */
