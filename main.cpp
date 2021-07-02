#include "test_heder.h"
#include "Map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main()
{
//	std::map<char,int> mymap;
//
//	// first insert function version (single parameter):
//	mymap.insert ( std::pair<char,int>('a',100) );
//	mymap.insert ( std::pair<char,int>('z',200) );
//
//	std::pair<std::map<char,int>::iterator,bool> ret;
//	ret = mymap.insert ( std::pair<char,int>('z',500) );
//	if (ret.second==false)
//	{
//		std::cout << "element 'z' already existed";
//		std::cout << " with a value of " << ret.first->second << '\n';
//	}
//////
//	// second insert function version (with hint position):
//	std::map<char,int>::iterator it = mymap.begin();
//	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
//	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
////
////	// third insert function version (range insertion):
//	std::map<char,int> anothermap;
//	anothermap.insert(mymap.begin(),mymap.find('c'));
////
////	// showing contents:
//	std::cout << "mymap contains:\n";
//	for (it=mymap.begin(); it!=mymap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
////
//	std::cout << "anothermap contains:\n";
//	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//
//
//	std::cout << "\n\nMY ______\n";
//
//	ft::Map<char,int> mymap1;
////	 first insert function version (single parameter):
//	mymap1.insert (ft::pair<char,int>('a', 100));
//	mymap1.insert ( ft::pair<char,int>('z',200) );
////
//	ft::pair<ft::Map<char,int>::iterator,bool> ret1;
//	ret1 = mymap1.insert ( ft::pair<char,int>('z',500) );
//	if (ret.second==false)
//	{
//		std::cout << "element 'z' already existed";
//		std::cout << " with a value of " << ret.first->second << '\n';
//	}
//
////	// second insert function version (with hint position):
//	ft::Map<char,int>::iterator it1 = mymap1.begin();
//
////	std::cout << (*it).first << "\n";
//	it1++;
//	mymap1.insert(it1, ft::pair<char,int>('b',300));  // max efficiency inserting
//	mymap1.insert (it1, ft::pair<char,int>('c',400));  // no max efficiency inserting
//
//	// third insert function version (range insertion):
//	ft::Map<char,int> anothermap1;
////	it1 = mymap1.find('c');
////	std::cout << (*it1).first << " <-- find\n";
//	anothermap1.insert(mymap1.begin(),mymap1.find('c'));
////
////	mymap1.show();
////	// showing contents:
//	std::cout << "mymap1.begin():" << mymap1.begin()->first << " " << mymap1.begin()->second << "\n";
//	ft::Map<char,int>::iterator it12 = mymap1.end();
//
//	std::cout << "mymap1.end():" << it12->first << " " << it12->second << "\n";
//	std::cout << "mymap contains:\n";
//	for (it1 = mymap1.begin(); it1 != mymap1.end(); ++it1)
//		std::cout << it1->first << " => " << it1->second << '\n';
////
//	std::cout << "anothermap contains:\n";
//	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//


	//////////////////////////////////////////



//	std::map<char,int> first;
//
//	first['a']=10;
//	first['b']=30;
//	first['c']=50;
//	first['d']=70;
//
//	for (std::map<char,int>::iterator it = first.begin(); it != first.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//	std::map<char,int> second (first.begin(),first.end());
//
//	std::map<char,int> third (second);
//
//	std::map<char,int,classcomp> fourth;                 // class as Compare
//
//	bool(*fn_pt)(char,char) = fncomp;
//	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
//
//	std::cout <<  "\n\n < ========= > "  << "\n";
//
	ft::Map<char,int> first1;

	first1['b']=10;
	first1['a']=30;
	first1['c']=50;
	first1['d']=70;

	ft::Map<char,int>::iterator it = first1.begin();
//	it++;
//	first1.erase(it);
//	first1.show();
	for (ft::Map<char,int>::iterator it1 = first1.begin(); it1 != first1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';
	std::cout << "\n";
//	ft::Map<char,int> second1 (first1.begin(),first1.end());
//	for (ft::Map<char,int>::iterator it1 = second1.begin(); it1 != second1.end(); ++it1)
//		std::cout << it1->first << " => " << it1->second << '\n';
//
//	ft::Map<char,int> third1 (second1);
//
//	ft::Map<char,int,classcomp> fourth1;                 // class as Compare
//
//	bool(*fn_pt1)(char,char) = fncomp;
//	ft::Map<char,int,bool(*)(char,char)> fifth1 (fn_pt1); // function pointer as Compare



}
