
#include "test_heder.h"

void test_queue()
{
	std::cout << "\n//////////// test QUEUE ////////////\n";
	std::cout << "ORIG: " << '\n';
	std::queue<int> first;                 // empty queue
	std::queue<int,std::vector<int> > third; // empty queue with list as underlying container
	first.push(10);
	first.push(11);
	first.push(12);
	third.push(13);
	third.push(14);
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "first.front() : " << first.front() << '\n';
	std::cout << "first.back() : " << first.back() << '\n';
	while (!first.empty())
	{
		std::cout << first.front() << ' ';
		first.pop();
	}
	std::cout << "\nsize of first: " << first.size() << '\n';
	std::cout << "\n";


	std::cout << "MY: " << '\n';
	ft::Queue<int> first1;                 // empty queue
	ft::Queue<int,ft::Vector<int> > third1; // empty queue with list as underlying container
	first1.push(10);
	first1.push(11);
	first1.push(12);
	third1.push(13);
	third1.push(14);
	std::cout << "size of first: " << first1.size() << '\n';
	std::cout << "size of third: " << third1.size() << '\n';
	std::cout << "first1.front() : " << first1.front() << '\n';
	std::cout << "first1.back() : " << first1.back() << '\n';
	while (!first1.empty())
	{
		std::cout << first1.front() << ' ';
		first1.pop();
	}
	std::cout << "\nsize of first: " << first1.size() << '\n';
}