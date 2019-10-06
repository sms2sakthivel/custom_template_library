/*
 * Linked_list.h
 *
 *  Created on: Oct 6, 2019
 *      Author: Sakthivel Ganesan
 */
#include "Linked_list.h"
namespace custom
{
	template<typename T>
	Linked_list<T>::Linked_list():_head(0),_tail(0),_temp(0),_size(0)
	{
	}

	template<typename T>
	Linked_list<T>::~Linked_list()
	{
	}

	template<typename T>
	bool Linked_list<T>::is_valid(int pos)
	{
		return pos > -1 && pos < _size;
	}

	template<typename T>
	T Linked_list<T>::get(int pos)
	{
		_temp = _head;
		for (int idx = 0; idx < pos; idx++)
			_temp = _temp->next;
		return _temp->data;
	}

	template<typename T>
	Element* Linked_list<T>::get_ptr(int pos)
	{
		Element *temp = _head;
		for (int idx = 0; idx < pos; idx++)
			temp = temp->next;
		return temp;
	}

	template<typename T>
	T Linked_list<T>::at(int pos)
	{
		if (!is_valid(pos)) return  get(_size - 1);
		return get(pos);
	}

	template<typename T>
	bool Linked_list<T>::assign(int pos, T value)
	{
		if (!is_valid(pos)) return false;
		get_ptr(pos)->data = value;
		return true;
	}

	template<typename T>
	bool Linked_list<T>::insert(int pos, T value)
	{
		if (!is_valid(pos)) return false;

		_temp = new Element;
		if (!_temp) return false;

		_temp->data = value;
		_temp->next = get_ptr(pos);

		if (pos == 0) _head = _temp;
		else get_ptr(pos - 1)->next = _temp;
		_size++;
		return true;
	}

	template<typename T>
	bool Linked_list<T>::push_back(T value)
	{
		_temp = new Element;
		if (!_temp) return false;

		_temp->data = value;
		_temp->next = 0;

		if (!_size) _head = _tail = _temp;
		else
		{
			_tail->next = _temp;
			_tail = temp;
		}
		_size++;
		return true;
	}

	template<typename T>
	bool Linked_list<T>::push_front(T value)
	{
		return insert(0, value);
	}

	template<typename T>
	bool Linked_list<T>::remove(int pos)
	{
		if (!is_valid(pos)) return false;
	
		_temp = get_ptr(pos);
		if (!_temp->next) delete _temp;
		else
		{
			get_ptr(pos - 1)->next = _temp->next;
			delete _temp;
		}
		_size--;
		return true;
	}

	template<typename T>
	bool Linked_list<T>::pop_back()
	{
		if (!_size) return false;

		_temp = get_ptr(_size - 1);
		delete _temp;
		
		if (_size == 1)
			_head = _tail = 0;
		else
		{
			_tail = get_ptr(_size - 2);
			_tail->next = 0;
		}
		_size--;
		return true;
	}

	template<typename T>
	bool Linked_list<T>::pop_front()
	{
		return remove(0);
	}

	template<typename T>
	int Linked_list<T>::size()
	{
		return _size;
	}

	template<typename T>
	Element* Linked_list<T>::begin()
	{
		return _head;
	}

	template<typename T>
	Element* Linked_list<T>::end()
	{
		return _tail;
	}

	template<typename T>
	bool Linked_list<T>::empty()
	{
		return _size == 0;
	}

	template<typename T>
	void Linked_list<T>::print()
	{
		_temp = _head
		for (int idx = 0; idx < _size; idx++)
		{
			std::cout << " " << _temp->data;
			_temp = _temp->next;
		}
		std::cout << std::endl;
	}
}