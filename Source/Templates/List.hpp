/*
 * List.hpp
 *
 *  Created on: Oct 5, 2019
 *      Author: Sakthivel Ganesan
 */

#ifndef _LIST_
#define _LIST_
#include <iostream>

namespace custom
{
template <typename T>
class List
{
	int _size,_capacity;
	T *_container, *_temp;
	bool re_size();
	bool is_valid(int pos);
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
	template<typename T>
	List<T>::List() :_size(0), _capacity(8), _container(0), _temp(0)
	{
		_container = new T[_capacity];
	}

	template<typename T>
	List<T>::~List()
	{
		if (_container) delete _container;
	}

	template<typename T>
	bool List<T>::re_size()
	{
		if (_size == _capacity)
			_capacity *= 2;

		_temp = new T[_capacity];
		if (!_temp) return false;

		for (int temp = 0; temp < _size; temp++)
			_temp[temp] = _container[temp];

		delete _container;
		_container = _temp;

		return true;
	}
	template<typename T>
	bool List<T>::is_valid(int pos)
	{
		return pos > -1 && pos < _size;
	}

	/*
	 * returns the value at the position passed in.
	 * returns the last element value if position passed in is not available.
	 * */
	template<typename T>
	T List<T>::at(int pos)
	{
		if (is_valid(pos)) return _container[pos];
		else return _container[_size - 1];
	}

	template<typename T>
	bool List<T>::assign(int pos, T value)
	{
		if (!is_valid(pos)) return false;
		_container[pos] = value;
		return true;
	}

	template<typename T>
	bool List<T>::insert(int pos, T value)
	{
		if (!is_valid(pos)) return false;
		if (_size < _capacity)
		{
			int temp = _size;
			while (temp >= pos)
			{
				_container[temp] = _container[temp - 1];
				temp--;
			}
			_container[pos] = value;
			_size++;
			return true;
		}
		else
		{
			if (!re_size()) return false;
			return insert(pos, value);
		}
	}

	template<typename T>
	bool List<T>::push_back(T value)
	{
		if (_size == _capacity)
			if (!re_size()) return false;
		_container[_size] = value;
		_size++;
		return true;
	}

	template<typename T>
	bool List<T>::push_front(T value)
	{
		return insert(0, value);
	}

	template<typename T>
	bool List<T>::remove(int pos)
	{
		if (!is_valid(pos)) return false;
		int temp = pos;
		while (temp < _size - 1)
		{
			_container[temp] = _container[temp + 1];
			temp++;
		}
		_size--;
		return true;
	}
	template<typename T>
	bool List<T>::pop_back()
	{
		if (!_size) return false;
		_size--;
		return true;
	}

	template<typename T>
	bool List<T>::pop_front()
	{
		return remove(0);
	}

	template<typename T>
	bool List<T>::empty()
	{
		return _size == 0;
	}

	template<typename T>
	int List<T>::size()
	{
		return _size;
	}

	template<typename T>
	int List<T>::capacity()
	{
		return _capacity;
	}


	template<typename T>
	T* List<T>::begin()
	{
		return _container;
	}

	template<typename T>
	T* List<T>::end()
	{
		return _container + _size;
	}

	template<typename T>
	bool List<T>::reverse()
	{
		_temp = new T[_capacity];
		if (!_temp) return false;

		int temp = 0;
		while (temp < _size)
		{
			_temp[temp] = _container[_size - temp - 1];
			temp++;
		}

		delete _container;
		_container = _temp;
		return true;
	}

	template<typename T>
	void List<T>::print()
	{
		int temp = 0;
		while (temp < _size) std::cout << " " << _container[temp++];
		std::cout << std::endl;
	}
}
#endif /* _LIST_ */
