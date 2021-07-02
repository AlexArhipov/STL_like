
#include "test_heder.h"
////////////////////////////////////////////////////
///// test constructor

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

void  test_l_constructor()
{
	std::list<int> first;                                // empty list of ints
	std::cout << "first:";
	for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	std::list<int> second(4, 100);                       // four ints with value 100
	std::cout << "second:\n";
	for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	std::list<int> third(second.begin(), second.end());  // iterating through second
	std::cout << "third:\n";
	for (std::list<int>::iterator it = third.begin(); it != third.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	std::list<int> fourth(third);                       // a copy of third
	std::cout << "fourth:\n";
	for (std::list<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	int myints[] = {16, 2, 77, 29};
	std::list<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "fifth:\n";
	for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n\n";

	ft::List<int> first1;                                // empty list of ints
	std::cout << "first:";
	for (ft::List<int>::iterator it = first1.begin(); it != first1.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	ft::List<int> second1(4, 100);                       // four ints with value 100
	std::cout << "second:\n";
	for (ft::List<int>::iterator it = second1.begin(); it != second1.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	ft::List<int> third1(second1.begin(), second1.end());  // iterating through second
	std::cout << "third:\n";
	for (ft::List<int>::iterator it = third1.begin(); it != third1.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	ft::List<int> fourth1(third1);                       // a copy of third
	std::cout << "fourth:\n";
	for (ft::List<int>::iterator it = fourth1.begin(); it != fourth1.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	int myints1[] = {16, 2, 77, 29};
	ft::List<int> fifth1(myints1, myints1 + sizeof(myints1) / sizeof(int));
	std::cout << "fifth:\n";
	for (ft::List<int>::iterator it = fifth1.begin(); it != fifth1.end(); it++)
		std::cout << *it << ' ';
}
////////////////////////////////////////////////////
///// test push_back
void	test_l_push_back()
{
		std::cout << "ORIG list\n";
		std::list<int> mylist;
		for(size_t i = 0; i < 10; i++)
			mylist.push_back (i);
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
			std::cout << ' ' << *it;
		std::cout << "\nmylist stores " << mylist.size() << " numbers.\n\n";

		std::cout << "  MY list\n";
		ft::List<int> mylist1;
		for(size_t i = 0; i < 10; i++)
			mylist1.push_back (i);
		for (ft::List<int>::iterator it=mylist1.begin(); it!=mylist1.end() ; ++it)
			std::cout << ' ' << *it;
		std::cout << "\nmylist stores " << mylist1.size() << " numbers.\n";
}
////////////////////////////////////////////////////
///// test back
void	test_l_back()
{
	std::list<int> mylist;
	mylist.push_back(10);
	while (mylist.back() != 0)
		mylist.push_back(mylist.back() - 1);
	std::cout << "ORIG contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::List<int> mylist1;
	mylist1.push_back(10);
	while (mylist1.back() != 0)
		mylist1.push_back(mylist1.back() - 1);
	std::cout << "  MY contains:";
	for (ft::List<int>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// test push fornt
void	test_l_fornt()
{
		std::list<int> mylist (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);
		mylist.push_front (400);
		mylist.push_front (500);
		std::cout << "ORIG contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		ft::List<int> mylist1 (2,100);         // two ints with a value of 100
		mylist1.push_front (200);
		mylist1.push_front (300);
		mylist1.push_front (400);
		mylist1.push_front (500);
		std::cout << "  MY contains:";
		for (ft::List<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
}
////////////////////////////////////////////////////
///// test pop back
void	test_l_pop_back()
{
	std::cout << "ORIG contains:\n";
	int myints[] = {16,2,77,29};
	std::list<int> l1 (myints, myints + sizeof(myints) / sizeof(int) );
  	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) // auto it =
  		std::cout << *it << ' ';
	std::cout << "\n";
  	l1.pop_back();
  	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) // auto it =
  		std::cout << *it << ' ';
  	std::cout << "\n\n";

	std::cout << "MY contains:\n";
  	int myints1[] = {16,2,77,29};
	  ft::List<int> l2 (myints1, myints1 + sizeof(myints1) / sizeof(int) );
  	for(ft::List<int>::iterator it = l2.begin(); it != l2.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	l2.pop_back();
	for(ft::List<int>::iterator it = l2.begin(); it != l2.end(); it++)
		std::cout << *it << ' ';
}
////////////////////////////////////////////////////
///// test pop front
void test_l_pop_front()
{
	std::cout << "ORIG contains:\n";
	int myints[] = {16,2,77,29};
	std::list<int> l1 (myints, myints + sizeof(myints) / sizeof(int) );
	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) // auto it =
		std::cout << *it << ' ';
	std::cout << "\n";
	l1.pop_front();
	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) // auto it =
		std::cout << *it << ' ';
	std::cout << "\n\n";

	std::cout << "MY contains:\n";
	int myints1[] = {16,2,77,29};
	ft::List<int> l2 (myints1, myints1 + sizeof(myints1) / sizeof(int) );
	for(ft::List<int>::iterator it = l2.begin(); it != l2.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	l2.pop_front();
	for(ft::List<int>::iterator it = l2.begin(); it != l2.end(); it++)
		std::cout << *it << ' ';
}
////////////////////////////////////////////////////
///// earse 1 - elem;
void test_l_erase_one()
{
	std::cout << "ORIG contains:\n";
	int myints[] = {16,2,77,29};
	std::list<int> l1 (myints, myints + sizeof(myints) / sizeof(int) );
	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) // auto it =
		std::cout << *it << ' ';
	std::cout << "\n";
	std::list<int>::iterator it = l1.begin();
	it++;
	it++;
	std::cout << "iter " << *it << '\n';
	std::cout << "return "<< *l1.erase(it) << "\n";
	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) // auto it =
		std::cout << *it << ' ';
	std::cout << "\n\n";

	std::cout << "MY contains:\n";
	int myints1[] = {16,2,77,29};
	ft::List<int> l2 (myints1, myints1 + sizeof(myints1) / sizeof(int) );
	for(ft::List<int>::iterator it = l2.begin(); it != l2.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	ft::List<int>::iterator it1 = l2.begin();
	it1++;
	it1++;
	std::cout << "iter " << *it1 << '\n';
	std::cout << "return "<< *l2.erase(it1) << "\n";
	for(ft::List<int>::iterator it = l2.begin(); it != l2.end(); it++)
		std::cout << *it << ' ';
}
////////////////////////////////////////////////////
///// earse 1 - range
void test_l_erase_range()
{
	std::cout << "ORIG contains:\n";
	int myints[] = {16,2,77,29, 99, 44, 12, 21, 42};
	std::list<int> l1 (myints, myints + sizeof(myints) / sizeof(int) );
	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) // auto it =
		std::cout << *it << ' ';
	std::cout << "\n";
	std::list<int>::iterator itb = l1.begin();
	std::list<int>::iterator ite = l1.begin();
	itb++;
	itb++;
	ite++;
	ite++;
	ite++;
	ite++;
	ite++;
	std::cout << "iter " << *itb << '\n';
	std::cout << "return "<< *l1.erase(itb, ite) << "\n";
	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) // auto it =
		std::cout << *it << ' ';
	std::cout << "\n\n";

	std::cout << "MY contains:\n";
	int myints1[] = {16,2,77,29, 99, 44, 12, 21, 42};
	ft::List<int> l2 (myints1, myints1 + sizeof(myints1) / sizeof(int) );
	for(ft::List<int>::iterator it = l2.begin(); it != l2.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
	ft::List<int>::iterator it1b = l2.begin();
	ft::List<int>::iterator it1n = l2.begin();
	it1b++;
	it1b++;
	it1n++;
	it1n++;
	it1n++;
	it1n++;
	it1n++;
	std::cout << "iter " << *it1b << '\n';
	std::cout << "return "<< *l2.erase(it1b, it1n) << "\n";
	for(ft::List<int>::iterator it = l2.begin(); it != l2.end(); it++)
		std::cout << *it << ' ';
}
////////////////////////////////////////////////////
///// clear
void test_l_clear()
{
		std::cout << "ORIG list:\n";
		std::list<int> mylist;
		std::list<int>::iterator it;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);
		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		mylist.clear();
		mylist.push_back (1101);
		mylist.push_back (2202);
		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "MY list:\n";
		ft::List<int> mylist1;
		ft::List<int>::iterator it1;
		mylist1.push_back (100);
		mylist1.push_back (200);
		mylist1.push_back (300);
		std::cout << "mylist contains:";
		for (it1 = mylist1.begin(); it1!=mylist1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << '\n';
		mylist1.clear();
		mylist1.push_back (1101);
		mylist1.push_back (2202);
		std::cout << "mylist contains:";
		for (it1=mylist1.begin(); it1 != mylist1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << '\n';
}
////////////////////////////////////////////////////
///// assign
void test_l_assign()
{
		std::cout << "ORIG :\n";
		std::list<int> first;
		std::list<int> second;
		first.assign (7,100);                      // 7 ints with value 100
		second.assign (first.begin(),first.end()); // a copy of first
		int myints[]={1776,7,4};
		first.assign (myints,myints + 3);            // assigning from array
		for (std::list<int>::iterator it=first.begin(); it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << "\nSize of first: " << int (first.size()) << '\n';
		for (std::list<int>::iterator it=second.begin(); it != second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << "\nSize of second: " << int (second.size()) << '\n';

		std::cout << "\nMY :\n";
		ft::List<int> first1;
		ft::List<int> second1;
		first1.assign (7, 100);                      // 7 ints with value 100
		second1.assign (first1.begin(),first1.end()); // a copy of first
		int myints1[]={1776, 7, 4};
		first1.assign (myints1, myints1 + 3);            // assigning from array
		for (ft::List<int>::iterator  it1=first1.begin(); it1 != first1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << "\nSize of first: " << int (first1.size()) << '\n';
		for (ft::List<int>::iterator  it1=second1.begin(); it1 != second1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << "\nSize of second: " << int (second1.size()) << '\n';
}
////////////////////////////////////////////////////
///// insert
void test_l_insert()
{
		std::cout << "ORIG\n";
		std::list<int> mylist;
		std::list<int>::iterator it;
		for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5
		it = mylist.begin();
		++it;       // it points now to number 2           ^
		std::cout << "iter_begin = " << *mylist.insert (it, 10) << '\n';
		mylist.insert (it, 2, 20);                      // 1 10 20 20 2 3 4 5
		std::vector<int> myvector (2, 30);
		mylist.insert (it, myvector.begin(), myvector.end());
		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "\n\nMY\n";
		ft::List<int> mylist1;
		ft::List<int>::iterator it1;
		// set some initial values:
		for (int i=1; i<=5; ++i) mylist1.push_back(i); // 1 2 3 4 5
		it1 = mylist1.begin();
		++it1;       // it points now to number 2           ^
		std::cout << "iter_begin = " << *mylist1.insert (it1, 10) << '\n';                        // 1 10 2 3 4 5
		mylist1.insert (it1, 2, 20);                      // 1 10 20 20 2 3 4 5
		std::vector<int> myvector1 (2, 30);
		mylist1.insert(it1, myvector1.begin(), myvector1.end());
		std::cout << "mylist contains:";
		for (it1 = mylist1.begin(); it1 !=mylist1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << '\n';
}
////////////////////////////////////////////////////
///// test_max_size
void test_l_max_size()
{
		unsigned int i = 10;
		std::list<int> mylist;
		std::cout << "ORIG Enter number of elements: " << mylist.max_size() << "\n";
		if (i < mylist.max_size()) mylist.resize(i);
		else std::cout << "That size exceeds the limit.\n";

		unsigned int i1 = 10;
		ft::List<int> mylist1;
		std::cout << "  MY Enter number of elements: " << mylist1.max_size() << "\n";
		if (i1 < mylist1.max_size()) mylist1.resize(i1);
		else std::cout << "That size exceeds the limit.\n";
}
////////////////////////////////////////////////////
///// test_resize
void test_l_resize()
{
		std::list<int> mylist;
		for (int i = 1; i < 10; ++i) mylist.push_back(i);
		mylist.resize(5);
		mylist.resize(8,100);
		std::cout << "\nORIG list contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		ft::List<int> mylist1;
		for (int i = 1; i < 10; ++i) mylist1.push_back(i);
		mylist1.resize(5);
		mylist1.resize(8,100);
		std::cout << "\n  MY list contains:";
		for (ft::List<int>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
}
////////////////////////////////////////////////////
///// test_sort
void test_l_sort()
{
		std::list<int> mylist;
		std::list<int>::iterator it;
		mylist.push_back (7);
		mylist.push_back (9);
		mylist.push_back (2);
		mylist.push_back (8);
		mylist.push_back (6);
		mylist.push_back (1);
		for (it = mylist.begin(); it !=mylist.end(); ++it)
			std::cout << ' ' << *it;
		mylist.sort();
		std::cout << "\nORIG list contains:\n";
		for (it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::list<std::string> mylist2;
		std::list<std::string>::iterator it2;
		mylist2.push_back ("one");
		mylist2.push_back ("two");
		mylist2.push_back ("Three");
		mylist2.sort();
		std::cout << "\nORIG list contains:";
		for (it2 = mylist2.begin(); it2!=mylist2.end(); ++it2)
			std::cout << ' ' << *it2;
		std::cout << '\n';
		mylist2.sort(compare_nocase);
		std::cout << "ORIG list contains:";
		for (it2 = mylist2.begin(); it2 !=mylist2.end(); ++it2)
			std::cout << ' ' << *it2;
		std::cout << "\n\n";

		ft::List<int> mylist1;
		ft::List<int>::iterator it1;
		mylist1.push_back (7);
		mylist1.push_back (9);
		mylist1.push_back (2);
		mylist1.push_back (8);
		mylist1.push_back (6);
		mylist1.push_back (1);
		for (it1 = mylist1.begin(); it1 !=mylist1.end(); ++it1)
			std::cout << ' ' << *it1;
		mylist1.sort();
		std::cout << "\nMY list contains:\n";
		for (it1 = mylist1.begin(); it1 != mylist1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::list<std::string> mylist3;
		std::list<std::string>::iterator it3;
		mylist3.push_back ("one");
		mylist3.push_back ("two");
		mylist3.push_back ("Three");
		mylist3.sort();
		std::cout << "\nMY list contains:";
		for (it3 = mylist3.begin(); it3 !=mylist3.end(); ++it3)
			std::cout << ' ' << *it3;
		std::cout << '\n';
		mylist3.sort(compare_nocase);
		std::cout << "MY list contains:";
		for (it3 = mylist3.begin(); it3 !=mylist3.end(); ++it3)
			std::cout << ' ' << *it3;
		std::cout << '\n';
}
////////////////////////////////////////////////////
///// test_merge
void test_l_merge()
{
	std::list<double> first, second;
	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);
	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);
	first.sort();
	second.sort();
	first.merge(second);
	// (second is now empty)
	std::cout << "\n";
	second.push_back (2.1);
	first.merge(second, mycomparison);
	std::cout << "first contains:";
	for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n";

	ft::List<double> first1, second1;
	first1.push_back (3.1);
	first1.push_back (2.2);
	first1.push_back (2.9);
	first1.sort();
	second1.push_back (3.7);
	second1.push_back (7.1);
	second1.push_back (1.4);
	second1.sort();
	first1.merge(second1);
//	 (second is now empty)
	second1.push_back (2.1);
	first1.merge(second1, mycomparison);
	std::cout << "\nfirst contains:";
	for (ft::List<double>::iterator it1 =  first1.begin(); it1 != first1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// test_splice
void test_l_splice()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;
	// set some initial values:
	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);   // mylist2: 10 20 30
	it = mylist1.begin();
	++it;                         // points to 2
	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
	// mylist2 (empty)
//	 "it" still points to 2 (the 5th element)
	mylist2.splice (mylist2.begin(),mylist1, it);
//	// mylist1: 1 10 20 30 3 4
//	// mylist2: 2
//	// "it" is now invalid.
	it = mylist1.begin();
	it++;
	it++;
	it++;
	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
//	// mylist1: 30 3 4 1 10 20
	std::cout << "mylist1 contains:";
	for (it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "mylist2 contains:";
	for (it=mylist2.begin(); it!=mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n\n";

	ft::List<int> mylist11, mylist12;
	ft::List<int>::iterator it1;
	// set some initial values:
	for (int i=1; i<=4; ++i)
		mylist11.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		mylist12.push_back(i*10);   // mylist2: 10 20 30
	it1 = mylist11.begin();
	++it1;                         // points to 2
	mylist11.splice (it1, mylist12); // mylist1: 1 10 20 30 2 3 4
	// mylist2 (empty)
	// "it" still points to 2 (the 5th element)
	mylist12.splice (mylist12.begin(),mylist11, it1);
//	// mylist1: 1 10 20 30 3 4
//	// mylist2: 2
//	// "it" is now invalid.
	it1 = mylist11.begin();
	it1++;
	it1++;
	it1++;
	mylist11.splice(mylist11.begin(), mylist11, it1, mylist11.end());
//	// mylist1: 30 3 4 1 10 20
	std::cout << "mylist1 contains:";
	for (it1=mylist11.begin(); it1!=mylist11.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	std::cout << "mylist2 contains:";
	for (it1=mylist12.begin(); it1!=mylist12.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// remove
void test_l_remove()
{
	int myints[]= {17,89,7,14};
	std::list<int> mylist (myints,myints+4);
	mylist.remove(89);
	std::cout << "ORiG list contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n\n";

	int myints1[]= {17, 89, 7, 14};
	ft::List<int> mylist1 (myints1,myints1 + 4);
	mylist1.remove(89);
	std::cout << "  MY list contains:";
	for (ft::List<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// remove if
void test_l_remove_if()
{
	std::cout << "ORIG:\n";
	int myints[]= {15,36,7,17,20,39,4,1};
	std::list<int> mylist (myints, myints + 8);   // 15 36 7 17 20 39 4 1
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.remove_if (single_digit);           // 15 36 17 20 39
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "MY:\n";
	int myints1[]= {15,36,7,17,20,39,4,1};
	ft::List<int> mylist1 (myints1, myints1 + 8);   // 15 36 7 17 20 39 4 1
	for (ft::List<int>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist1.remove_if(single_digit);           // 15 36 17 20 39
	std::cout << "mylist contains:";
	for (ft::List<int>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// reverse
void test_l_reverse()
{
	std::cout << "ORIG:\n";
	std::list<int> mylist;
	for (int i=1; i<10; ++i) mylist.push_back(i);
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.reverse();
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n\n";

	std::cout << "MY:\n";
	ft::List<int> mylist1;
	for (int i=1; i<10; ++i) mylist1.push_back(i);
	for (ft::List<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist1.reverse();
	std::cout << "mylist contains:";
	for (ft::List<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// swap
void test_l_swap()
{
	std::list<int> first (3,100);   // three ints with a value of 100
	std::list<int> second (5,200);  // five ints with a value of 200
	first.swap(second);
	std::cout << "first contains:";
	for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "second contains:";
	for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << "\n\n";

	ft::List<int> first1 (3,100);   // three ints with a value of 100
	ft::List<int> second1 (5,200);  // five ints with a value of 200
	first1.swap(second1);
	std::cout << "first contains:";
	for (ft::List<int>::iterator it=first1.begin(); it!=first1.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "second contains:";
	for (ft::List<int>::iterator it=second1.begin(); it!=second1.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// union
void test_l_unique()
{
	double mydoubles[]={ 12,  2, 73,  12,  3, 12, 73, 72, 15,  72 };
	std::list<double> mylist (mydoubles,mydoubles+10);
	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	// 15.3,  72.25, 72.25, 73.0,  73.35
	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
	// 15.3,  72.25, 73.0,  73.35
	mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
	std::cout << "ORIG list contains:";
	for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	double mydoubles1[]={ 12,  2, 73,  12,  3, 12, 73, 72, 15,  72 };
	ft::List<double> mylist1 (mydoubles1, mydoubles1 + 10);
	mylist1.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	// 15.3,  72.25, 72.25, 73.0,  73.35
	mylist1.unique();           //  2.72,  3.14, 12.15, 12.77
	// 15.3,  72.25, 73.0,  73.35
	mylist1.unique(same_integral_part);  //  2.72,  3.14, 12.15
	std::cout << "  MY list contains:";
	for (ft::List<double>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// operator
void test_l_operator_rav()
{
	std::cout << "ORIG:\n";
	std::list<int> first (3);      // list of 3 zero-initialized ints
	std::list<int> second (5);     // list of 5 zero-initialized ints
	second = first;
	first = std::list<int>();
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';

	std::cout << "\nMY:\n";
	ft::List<int> first1 (3);      // list of 3 zero-initialized ints
	ft::List<int> second1 (5);     // list of 5 zero-initialized ints
	second1 = first1;
	first1 = ft::List<int>();
	std::cout << "Size of first: " << int (first1.size()) << '\n';
	std::cout << "Size of second: " << int (second1.size()) << '\n';
}
////////////////////////////////////////////////////
///// rbegin, rend
void test_l_rbegin_rend()
{
	std::list<int> mylist;
	for (int i=1; i<=5; ++i) mylist.push_back(i);
	std::cout << "mylist backwards:";
	for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';

	ft::List<int> mylist1;
	for (int i=1; i<=5; ++i) mylist1.push_back(i);
	std::cout << "mylist backwards:";
	for (ft::List<int>::reverse_iterator rit=mylist1.rbegin(); rit!=mylist1.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';
}
////////////////////////////////////////////////////
///// non-member overloads:
///// swap
void test_l_swap_not_member()
{
	std::list<int> a, b, c;
	for (int i=1; i<=5; ++i) a.push_back(i);
	for (int i=1; i<=5; ++i) b.push_back(i);
	for (int i=1; i<=5; ++i) c.push_back(i*2);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n\n";

	std::list<int> a1, b1, c1;
	for (int i=1; i<=5; ++i) a1.push_back(i);
	for (int i=1; i<=5; ++i) b1.push_back(i);
	for (int i=1; i<=5; ++i) c1.push_back(i*2);

	if (a1 == b1) std::cout << "a and b are equal\n";
	if (b1 != c1) std::cout << "b and c are not equal\n";
	if (b1 < c1) std::cout << "b is less than c\n";
	if (c1 > b1) std::cout << "c is greater than b\n";
	if (a1 <= b1) std::cout << "a is less than or equal to b\n";
	if (a1 >= b1) std::cout << "a is greater than or equal to b\n";
}
///// +-><
void test_l_srav_not_member()
{
	std::list<int> foo (3,100);   // three ints with a value of 100
	std::list<int> bar (5,200);   // five ints with a value of 200
	std::swap(foo,bar);
	std::cout << "foo contains:";
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains:";
	for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::List<int> foo1 (3,100);   // three ints with a value of 100
	ft::List<int> bar1 (5,200);   // five ints with a value of 200
	ft::swap(foo1, bar1);
	std::cout << "foo contains:";
	for (ft::List<int>::iterator it = foo1.begin(); it!=foo1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains:";
	for (ft::List<int>::iterator it = bar1.begin(); it!=bar1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
void test_list()
{
	std::cout << "\n//////////// test constructors ////////////\n";
	test_l_constructor();
	std::cout << "\n//////////// test push_back ////////////\n";
	test_l_push_back();
	std::cout << "\n//////////// test back ////////////\n";
	test_l_back();
	std::cout << "\n//////////// test fornt ////////////\n";
	test_l_fornt();
	std::cout << "\n//////////// test pop_back ////////////\n";
	test_l_pop_back();
	std::cout << "\n//////////// test pop_front ////////////\n";
	test_l_pop_front();
	std::cout << "\n//////////// test erase_one ////////////\n";
	test_l_erase_one();
	std::cout << "\n//////////// test erase_range ////////////\n";
	test_l_erase_range();
	std::cout << "\n//////////// test clear ////////////\n";
	test_l_clear();
	std::cout << "\n//////////// test assign ////////////\n";
	test_l_assign();
	std::cout << "\n//////////// test insert ////////////\n";
	test_l_insert();
	std::cout << "\n//////////// test max_size ////////////\n";
	test_l_max_size();
	std::cout << "\n//////////// test resize ////////////\n";
	test_l_resize();
	std::cout << "\n//////////// test sort ////////////\n";
	test_l_sort();
	std::cout << "\n//////////// test merge ////////////\n";
	test_l_merge();
	std::cout << "\n//////////// test splice ////////////\n";
	test_l_splice();
	std::cout << "\n//////////// test remove ////////////\n";
	test_l_remove();
	std::cout << "\n//////////// test remove_if ////////////\n";
	test_l_remove_if();
	std::cout << "\n//////////// test reverse ////////////\n";
	test_l_reverse();
	std::cout << "\n//////////// test swap ////////////\n";
	test_l_swap();
	std::cout << "\n//////////// test unique ////////////\n";
	test_l_unique();
	std::cout << "\n//////////// test operator_ravno ////////////\n";
	test_l_operator_rav();
	std::cout << "\n//////////// test rbegin_rend ////////////\n";
	test_l_rbegin_rend();
	std::cout << "\n//////////// test swap_not_member ////////////\n";
	test_l_swap_not_member();
	std::cout << "\n//////////// test sravnenie_not_member ////////////\n";
	test_l_srav_not_member();
}