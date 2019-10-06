/*
 * Linked_list.h
 *
 *  Created on: Oct 6, 2019
 *      Author: Sakthivel Ganesan
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace custom
{
	template<typename T>
	class Linked_list
	{
		struct Node 
		{
			Node* next;
			T data;
		}Element;
		Element *_head, *_tail, *_temp;
		int _size;
		bool is_valid(int pos);
		T get(int pos);
		Element* get_ptr(int pos);
	public:
		Linked_list();
		~Linked_list();
		T at(int pos);
		bool assign(int pos, T value);
		bool insert(int pos,T value);
		bool push_back(T value);
		bool push_front(T value);
		bool remove(int pos);
		bool pop_back();
		bool pop_front();
		int size();
		Element* begin();
		Element* end();
		bool empty();
		void print();
	};
}
#endif // !LINKED_LIST_H
