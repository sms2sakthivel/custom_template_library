#include <iostream>
#include "Tests/Test.h"
#include <ctime>

int main(int argc, char** argv)
{
	std::clock_t time = std::clock();
	std::cout << "Time = " << time << std::endl;
	std::cout << "Welcome Everyone!" << std::endl;
	Test::Test test;
	test.TestList();
	test.TestLinkedList();
	std::cout << "Time = " << std::clock() << std::endl;
	std::cout << std::clock() - time << std::endl;
	return 0;
}