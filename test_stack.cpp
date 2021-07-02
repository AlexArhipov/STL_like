#include "test_heder.h"

void test_stack()
{
	std::cout << "\n//////////// test STACK ////////////\n";
	std::cout << "ORIG:\n";
	std::stack<int> first;                    // empty stack
	std::stack<int> first12;
	first.push(12);
	first.push(11);
	first.push(10);
	first.push(9);
	std::cout << "size of : " << first.size() << '\n';
	std::cout << "top : " << first.top() << '\n';
	std::cout << "empty first: " << first.empty() << '\n';
	std::cout << "empty first12: " << first12.empty() << '\n';
	first.pop();
	std::cout << "size of : " << first.size() << '\n';
	std::cout << "top : " << first.top() << '\n';
	if (first == first12)
		std::cout << "Ravhi"  << '\n';
	else
		std::cout << "Ne ravhi"  << '\n';

	std::cout << "\nMY:\n";
	ft::Stack<int> first1;
	ft::Stack<int> first2;
	first1.push(12);
	first1.push(11);
	first1.push(10);
	first1.push(9);
	std::cout << "size of : " << first1.size() << '\n';
	std::cout << "top : " << first1.top() << '\n';
	std::cout << "empty first1: " << first1.empty() << '\n';
	std::cout << "empty first2: " << first2.empty() << '\n';
	first1.pop();
	std::cout << "size of : " << first1.size() << '\n';
	std::cout << "top : " << first1.top() << '\n';
	if (first1 == first2)
		std::cout << "Ravhi"  << '\n';
	else
		std::cout << "Ne ravhi"  << '\n';
	std::cout << "\n";
}
