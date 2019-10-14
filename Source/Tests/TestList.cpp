/*
 * Test.h
 *
 *  Created on: Oct 14, 2019
 *      Author: Sakthivel Ganesan
 */
#include "Test.h"
#include "../Templates/List.hpp"
namespace Test
{
	void Test::TestList()
	{
		custom::List<int> list;
		list.push_back(20);
		list.push_back(67);
		list.insert(1, 65);
		list.push_front(89);
		list.pop_back();
		list.push_back(2345);
		list.push_front(500);
		list.push_back(912);
		list.assign(2,679);
		std::cout << "is Empty : " << list.empty() <<" Count : "<< list.size() << std::endl;
		std::cout << "Element At index 3 = " << list.at(3) <<" Capacity is = "<< list.capacity()<< std::endl;
		list.print();
		list.reverse();
		std::cout << "Reversed List" << std::endl;
		list.print();
	}
}

