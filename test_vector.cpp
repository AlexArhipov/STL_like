#include "test_heder.h"

void copy_range()
{
	std::vector<int> b1(5);
	for (int i = 0; i < 5; i++)
		b1[i] = i * 11 + 1;
	std::cout << "original vector" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << " " << b1[i];
	std::cout << std::endl;
	std::cout << std::endl;

	ft::Vector<int> c1(b1.begin(), b1.end());   ///// <----------
	std::cout << "my vector" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << " " << c1[i];
	std::cout << std::endl;
}

void copy_range_2()
{
	std::vector<int> b1(3, 100);
	std::cout << "original vector" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << " " << b1[i];
	std::cout << "\n\n";

	ft::Vector<int> c1(3, 100);   ///// <----------
	std::cout << "my vector" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << " " << c1[i];
	std::cout << std::endl;
}

void test_constructor_NULL()
{
	std::vector<int> b2(5);
	std::cout << "original vector" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << " " << b2[i];
	std::cout << std::endl;
	std::cout << std::endl;
	ft::Vector<int> c2(5);   ///// <----------
	std::cout << "my vector" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << " " << c2[i];
	std::cout << std::endl;
}

void test_copy_constructor()
{
	std::vector<int> b3(5);
	for (int i = 0; i < 5; i++)
		b3[i] = i * 11 + 1;
	std::cout << "original vector" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << " " << b3[i];
	std::cout << "\n\n";

	ft::Vector<int> a3(b3.begin(), b3.end());
	ft::Vector<int> c3(a3);   ///// <----------
	std::cout << "my vector" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << " " << c3[i];
	std::cout << std::endl;
}

void test_operator_ravno()
{
	std::vector<int> b3(5);
	for (int i = 0; i < 5; i++)
		b3[i] = i * 11 + 1;
	std::cout << "original vector" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << " " << b3[i];
	ft::Vector<int> a3(b3.begin(), b3.end());
	std::cout << std::endl;
	std::cout << std::endl;
	ft::Vector<int> c3 = a3;   ///// <----------
	std::cout << "my vector" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << " " << c3[i];
	std::cout << std::endl;
}

void test_assign()
{
	ft::Vector<int> first;
	ft::Vector<int> second;
	ft::Vector<int> third;

	first.assign(7, 100);             // 7 ints with a value of 100
	for (unsigned i = 0; i < first.size(); i++)
		std::cout << ' ' << first[i];

	ft::Vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1); // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3);   // assigning from array.

	std::cout << "\nSize of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
	std::cout << "Size of third: " << int(third.size()) << "\n\n MY: \n";

	ft::Vector<int> first1;
	ft::Vector<int> second1;
	ft::Vector<int> third1;

	first1.assign(7, 100);             // 7 ints with a value of 100
	for (unsigned i = 0; i < first1.size(); i++)
		std::cout << ' ' << first1[i];

	ft::Vector<int>::iterator it1;
	it1 = first1.begin() + 1;

	second1.assign(it1, first1.end() - 1); // the 5 central values of first

	int myints1[] = {1776, 7, 4};
	third1.assign(myints1, myints1 + 3);   // assigning from array.

	std::cout << "\nSize of first: " << int(first1.size()) << '\n';
	std::cout << "Size of second: " << int(second1.size()) << '\n';
	std::cout << "Size of third: " << int(third1.size()) << '\n';
}

void test_clear()
{
	std::vector<int> myvector;
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);
	std::cout << "orig vector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	myvector.clear();
	myvector.push_back(1101);
	myvector.push_back(2202);
	std::cout << "orig vector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	ft::Vector<int> myvector1;
	myvector1.push_back(100);
	myvector1.push_back(200);
	myvector1.push_back(300);
	std::cout << "\nmy vector contains:";
	for (unsigned i = 0; i < myvector1.size(); i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
	myvector1.clear();
	myvector1.push_back(1101);
	myvector1.push_back(2202);
	std::cout << "my vector contains:";
	for (unsigned i = 0; i < myvector1.size(); i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
}

void test_push_back()
{
	ft::Vector<int> myvector;
	std::vector<int> myvector1;

	for (size_t i = 1; i < 10; i++)
		myvector.push_back(i);

	std::cout << "origin vector stores " << int(myvector.size()) << " numbers.\n";

	for (size_t i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];

	for (size_t i = 1; i < 10; i++)
		myvector1.push_back(i);

	std::cout << "\n\n my vector stores " << int(myvector1.size()) << " numbers.\n";

	for (size_t i = 0; i < myvector1.size(); i++)
		std::cout << ' ' << myvector1[i];
}

void test_empty()
{
	std::vector<int> myvector;
	int sum(0);
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);
	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "orig total: " << sum << '\n';

	ft::Vector<int> myvector2;
	int sum2(0);
	for (int i = 1; i <= 10; i++)
		myvector2.push_back(i);
	while (!myvector2.empty())
	{
		sum2 += myvector2.back();
		myvector2.pop_back();
	}
	std::cout << "copy total: " << sum2 << '\n';
}

void test_pop_back()
{
	std::vector<int> myvector;
	int sum(0);
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "The elements of myvector add up to " << sum << '\n';

	ft::Vector<int> myvector1;
	int sum1(0);
	myvector1.push_back(100);
	myvector1.push_back(200);
	myvector1.push_back(300);

	while (!myvector1.empty())
	{
		sum1 += myvector1.back();
		myvector1.pop_back();
	}
	std::cout << "The elements of myvector add up to " << sum1 << '\n';
}

void test_back()
{
	std::vector<int> myvector;
	myvector.push_back(10);
	while (myvector.back() != 0)
		myvector.push_back(myvector.back() - 1);
	std::cout << "orig vector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	ft::Vector<int> myvector1;
	myvector1.push_back(10);
	while (myvector1.back() != 0)
		myvector1.push_back(myvector1.back() - 1);
	std::cout << "  my vector contains:";
	for (unsigned i = 0; i < myvector1.size(); i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
}

void test_begin_end()
{
	std::vector<int> myvector;
	for (int i = 1; i <= 5; i++) myvector.push_back(i);
	std::cout << "orig vector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::Vector<int> myvector1;
	for (int i = 1; i <= 5; i++) myvector1.push_back(i);
	std::cout << "  my vector contains:";
	for (ft::Vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_rbegin_rend()
{
	std::vector<int> myvector(5);  // 5 default-constructed ints
	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	int i = 0;
	for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
		*rit = ++i;
	std::cout << "orig vector:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::Vector<int> myvector1(5);  // 5 default-constructed ints
	ft::Vector<int>::reverse_iterator rit1 = myvector1.rbegin();
	int i1 = 0;
	for (rit1 = myvector1.rbegin(); rit1 != myvector1.rend(); ++rit1)
		*rit1 = ++i1;
	std::cout << "  my vector:";
	for (ft::Vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_max_size_capacity_size()
{
	std::vector<int> myvector;
	std::cout << "orig vector:\n";
	for (int i = 0; i < 100; i++) myvector.push_back(i);
	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";

	ft::Vector<int> myvector1;
	std::cout << "\nmy vector:\n";
	for (int i = 0; i < 100; i++) myvector1.push_back(i);
	std::cout << "size: " << myvector1.size() << "\n";
	std::cout << "capacity: " << myvector1.capacity() << "\n";
	std::cout << "max_size: " << myvector1.max_size() << "\n";
}

void test_reserve()
{
	std::vector<int>::size_type sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::cout << "\ntest my vector: " << '\n';
	ft::Vector<int>::size_type sz1;
	ft::Vector<int> foo1;
	sz1 = foo1.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo1.push_back(i);
		if (sz1 != foo1.capacity())
		{
			sz1 = foo1.capacity();
			std::cout << "capacity changed: " << sz1 << '\n';
		}
	}
	ft::Vector<int> bar1;
	sz1 = bar1.capacity();
	bar1.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar1.push_back(i);
		if (sz1 != bar1.capacity())
		{
			sz1 = bar1.capacity();
			std::cout << "capacity changed: " << sz1 << '\n';
		}
	}
}

void test_erase()
{
	std::vector<int> myvector;
	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);
	// erase the 6th element
	myvector.erase(myvector.begin() + 5);
	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	ft::Vector<int> myvector1;
	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++) myvector1.push_back(i);
	// erase the 6th element
	myvector1.erase(myvector1.begin() + 5);
	// erase the first 3 elements:
	myvector1.erase(myvector1.begin(), myvector1.begin() + 3);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1.size(); ++i)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
}

void test_at()
{
	std::vector<int> myvector(10);   // 10 zero-initialized ints
	// assign some values:
	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;
	std::cout << "orig vector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';

	ft::Vector<int> myvector1(10);   // 10 zero-initialized ints
	// assign some values:
	for (unsigned i = 0; i < myvector1.size(); i++)
		myvector1.at(i) = i;
	std::cout << "  my vector contains:";
	for (unsigned i = 0; i < myvector1.size(); i++)
		std::cout << ' ' << myvector1.at(i);
	std::cout << '\n';
}

void test_at2()
{
	std::vector<int> myvector;
	int *p;
	unsigned int i;
	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);
	// construct values in-place on the array:
	for (i = 0; i < 5; i++) myvector.get_allocator().construct(&p[i], i);
	std::cout << "ORIG: The allocated array contains:";
	for (i = 0; i < 5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';
	// destroy and deallocate:
	for (i = 0; i < 5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p, 5);

	ft::Vector<int> myvector1;
	int *p1;
	unsigned int i1;
	// allocate an array with space for 5 elements using vector's allocator:
	p1 = myvector1.get_allocator().allocate(5);
	// construct values in-place on the array:
	for (i1 = 0; i1 < 5; i1++) myvector1.get_allocator().construct(&p1[i1], i1);
	std::cout << "  MY: The allocated array contains:";
	for (i1 = 0; i1 < 5; i1++) std::cout << ' ' << p1[i1];
	std::cout << '\n';
	// destroy and deallocate:
	for (i1 = 0; i1 < 5; i1++) myvector1.get_allocator().destroy(&p1[i1]);
	myvector1.get_allocator().deallocate(p1, 5);
}

void test_insert()
{
	std::vector<int> myvector(7);// (7, 100);
	for (unsigned i = 0; i < 7; i++)
		myvector.at(i) = i;
	for (int i = 0; i < 7; i++) std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::vector<int>::iterator it;
	it = myvector.begin() + 3;
	it = myvector.insert(it, 777);
	for (int i = 0; i < 9; i++) std::cout << ' ' << myvector[i];
	std::cout << "\n";
	myvector.insert(it, 2, 300);
	for (int i = 0; i < 10; i++) std::cout << ' ' << myvector[i];
	std::cout << "\n\n\n";

	ft::Vector<int> myvector1(7);// (7, 100);
	for (unsigned i = 0; i < 7; i++)
		myvector1.at(i) = i;
	for (int i = 0; i < 7; i++) std::cout << ' ' << myvector1[i];
	std::cout << '\n';
	ft::Vector<int>::iterator it1;
	it1 = myvector1.begin() + 3;
	it1 = myvector1.insert(it1, 777);
	for (int i = 0; i < 9; i++) std::cout << ' ' << myvector1[i];
	std::cout << "\n";
	myvector1.insert(it1, 2, 300);
	for (int i = 0; i < 10; i++) std::cout << ' ' << myvector1[i];
}

void test_resize()
{
	std::vector<int> myvector;

	// set some initial content:
	for (int i = 1; i < 10; i++) myvector.push_back(i);
	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);
	std::cout << "orig vector contains:";
	for (int i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	ft::Vector<int> myvector1;

	// set some initial content:
	for (int i = 1; i < 10; i++) myvector1.push_back(i);
	myvector1.resize(5);
	myvector1.resize(8, 100);
	myvector1.resize(12);
	std::cout << "  my vector contains:";
	for (int i = 0; i < myvector1.size(); i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
}

void test_swap()
{
	std::vector<int> foo(3, 100);   // three ints with a value of 100
	std::vector<int> bar(5, 200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';
	std::cout << "bar contains:";
	for (unsigned i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

	ft::Vector<int> foo1(3, 100);   // three ints with a value of 100
	ft::Vector<int> bar1(5, 200);   // five ints with a value of 200

	foo1.swap(bar1);

	std::cout << "foo contains:";
	for (unsigned i = 0; i < foo1.size(); i++)
		std::cout << ' ' << foo1[i];
	std::cout << '\n';
	std::cout << "bar contains:";
	for (unsigned i = 0; i < bar1.size(); i++)
		std::cout << ' ' << bar1[i];
	std::cout << '\n';
}

void test_opertators_not_member()
{
	std::vector<int> foo(3, 100);   // three ints with a value of 100
	std::vector<int> bar(2, 200);   // two ints with a value of 200
	std::cout << "ORIG\n";
	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
	std::cout << "\nCOPY\n";
	ft::Vector<int> foo1(3, 100);   // three ints with a value of 100
	ft::Vector<int> bar1(2, 200);   // two ints with a value of 200
	if (foo1 == bar1) std::cout << "foo and bar are equal\n";
	if (foo1 != bar1) std::cout << "foo and bar are not equal\n";
	if (foo1 < bar1) std::cout << "foo is less than bar\n";
	if (foo1 > bar1) std::cout << "foo is greater than bar\n";
	if (foo1 <= bar1) std::cout << "foo is less than or equal to bar\n";
	if (foo1 >= bar1) std::cout << "foo is greater than or equal to bar\n";
}

void test_swap_not_member()
{
	std::vector<int> foo(3, 100);   // three ints with a value of 100
	std::vector<int> bar(5, 200);   // five ints with a value of 200
	foo.swap(bar);
	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains:";
	for (std::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n\nMY\n";

	std::vector<int> foo1(3, 100);   // three ints with a value of 100
	std::vector<int> bar1(5, 200);   // five ints with a value of 200
	foo1.swap(bar1);
	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo1.begin(); it != foo1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains:";
	for (std::vector<int>::iterator it = bar1.begin(); it != bar1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_vector()
{
	std::cout << "\n//////////// copy_range ////////////\n";
	 copy_range();
	std::cout << "\n//////////// copy_range ////////////\n";
	 copy_range_2();
	std::cout << "\n//////////// test_constructor_NULL ////////////\n";
	 test_constructor_NULL();
	std::cout << "\n//////////// test_copy_constructor ////////////\n";
	 test_copy_constructor();
	std::cout << "\n//////////// test_operator_ravno ////////////\n";
	 test_operator_ravno();
	std::cout << "\n//////////// test_assign ////////////\n";
	 test_assign();
	std::cout << "\n//////////// test_clear ////////////\n";
	 test_clear();
	std::cout << "\n//////////// test_push_back ////////////\n";
	 test_push_back();
	std::cout << "\n//////////// test_empty ////////////\n";
	 test_empty();
	std::cout << "\n//////////// test_pop_back ////////////\n";
	 test_pop_back();
	std::cout << "\n//////////// test_back ////////////\n";
	 test_back();
	std::cout << "\n//////////// test_begin_end ////////////\n";
	 test_begin_end();
	std::cout << "\n//////////// test_rbegin_rend ////////////\n";
	 test_rbegin_rend();
	std::cout << "\n//////////// test_max_size_capacity_size ////////////\n";
	 test_max_size_capacity_size();
	std::cout << "\n//////////// test_reserve ////////////\n";
	 test_reserve();
	std::cout << "\n//////////// test_erase ////////////\n";
	 test_erase();
	std::cout << "\n//////////// test_at ////////////\n";
	 test_at();
	std::cout << "\n//////////// test_at2 ////////////\n";
	 test_at2();
	std::cout << "\n//////////// test_insert ////////////\n";
	 test_insert();
	std::cout << "\n//////////// test_resize ////////////\n";
	 test_resize();
	std::cout << "\n//////////// test_swap ////////////\n";
	 test_swap();
	std::cout << "\n//////////// test_opertators_not_member ////////////\n";
	 test_opertators_not_member();
	std::cout << "\n//////////// test_swap_not_member ////////////\n";
	 test_swap_not_member();
};