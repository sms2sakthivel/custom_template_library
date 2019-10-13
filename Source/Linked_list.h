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
	struct Node
	{
		Node* next;
		T data;
		typedef Node<T> Element;
	};
	
	template<typename T>
	class Linked_list
	{
		typename Node<T>::Element *_head, *_tail, *_temp;
		int _size;
		bool is_valid(int pos);
		T get(int pos);
		typename Node<T>::Element* get_ptr(int pos);
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
		typename Node<T>::Element* begin();
		typename Node<T>::Element* end();
		bool empty();
		void print();
	};
}
#endif // !LINKED_LIST_H
