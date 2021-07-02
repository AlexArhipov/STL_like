

#ifndef CONTR_LIST_HPP
#define CONTR_LIST_HPP

#include <iostream>
#include "ListNode.hpp"
#include "ListIterator.hpp"
#include <math.h>

#endif //CONTR_LIST_HPP

namespace ft
{
	template<class T, class Alloc = std::allocator <ListNode<T> > >
	class List
	{
	public:
		typedef T													value_type;
		typedef Alloc												allocator_type;
		typedef value_type &										reference;
		typedef value_type const &									const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;

		typedef typename allocator_type::size_type					size_type;
		typedef typename allocator_type::difference_type			difference_type;

		typedef ListNode<value_type>								node_type;
		typedef node_type *											node_point;

		typedef ListIterator<value_type>							iterator;
		typedef ListIterator<value_type const>						const_iterator;

		typedef ListRevIterator <value_type>						reverse_iterator;
		typedef ListRevIterator<value_type const>					const_reverse_iterator;

	private:
		//size_type	_size;
		Alloc		_alloc;
		node_point	_node_end;
		node_point	_node_start;

	public:

		explicit List (const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_node_start = _alloc.allocate(1);
			_node_start->SetNext(_node_start);
			_node_start->SetPrev(_node_start);
			_node_start->SetVal(0);
		}

		iterator begin() { return iterator(_node_start->GetNext());}
		iterator end() { return iterator(_node_start);}

		reverse_iterator rbegin() { return reverse_iterator(_node_start->GetPrev());}
	//	const_reverse_iterator rbegin() const { return const_reverse_iterator(_node_start->GetNext());}

		reverse_iterator rend() { return reverse_iterator(_node_start);}
	//	const_reverse_iterator rend() const { return const_reverse_iterator(_node_start);}

		explicit List (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			node_point temp;
			_node_start = _alloc.allocate(sizeof(_node_start));
			_node_start->SetVal(n);
			temp = _node_start;
			size_t size = 0;
			for(size_type i = 0; i < n; i++)
			{
				_node_end = _alloc.allocate(sizeof(_node_start));
				temp->SetNext(_node_end);
				_node_end->SetVal(val);
				_node_end->SetPrev(temp);
				temp = _node_end;
				size++;
			}
			_node_end->SetNext(_node_start);
			_node_start->SetVal(size);
		}
		template <class InputIterator>
		List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), char (*)[sizeof(*first)] = NULL)
		{
			node_point temp;
			_node_start = _alloc.allocate(sizeof(_node_start));
			temp = _node_start;
			size_t size = 0;
			for(InputIterator iter = first; iter != last; iter++)
			{
				_node_end = _alloc.allocate(sizeof(_node_start));
				temp->SetNext(_node_end);
				_node_end->SetVal(*iter);
				_node_end->SetPrev(temp);
				temp = _node_end;
				size++;
			}
			_node_end->SetNext(_node_start);
			_node_start->SetVal(size);
		}

		List (const List& x) { *this = x; }

		List &operator=(const List& x)
		{
			_node_start = x._node_start;
			_node_end = x._node_end;
			return *this;
		}

		~List() {}

		void pop_front()
		{
			if (_node_start->GetVal() > 0)
			{
				_node_start->SetVal(_node_start->GetVal() - 1);
				node_point temp = _node_start->GetNext();
				(temp->GetNext())->SetPrev(_node_start);
				_node_start->SetNext(temp->GetNext());
				_alloc.deallocate(temp, sizeof(_node_start));
			}
		}

		void pop_back()
		{
			if (_node_start->GetVal() > 0)
			{
				_node_start->SetVal(_node_start->GetVal() - 1);
				node_point temp = _node_end->GetPrev();
				temp->SetNext(_node_start);
				_node_start->SetPrev(temp);
				_alloc.deallocate(_node_end, sizeof(_node_start));
				_node_end = temp;
			}
		}


	//	void nods(){ std::cout << "\nintro " << _node_end->GetVal() << "    size = " << _node_start->GetVal()<< "  begin = " << *begin(); "\n"; }
		void push_back (const value_type& val)
		{
			_node_start->SetVal(_node_start->GetVal() + 1);
			if (_node_start->GetVal() > 1)
			{
				_node_end = _node_start->GetPrev();
				node_point temp = _alloc.allocate(sizeof(_node_start));
				temp->SetVal(val);
				temp->SetNext(_node_start);
				temp->SetPrev(_node_end);
				_node_start->SetPrev(temp);
				_node_end->SetNext(temp);
				_node_end = _node_end->GetNext();
			}
			else
			{
				_node_end = _alloc.allocate(1);
				_node_end->SetVal(val);
				_node_end->SetNext(_node_start);
				_node_end->SetPrev(_node_start);
				_node_start->SetPrev(_node_end);
				_node_start->SetNext(_node_end);
			}
		}

		void push_front (const value_type& val)
		{
			_node_start->SetVal(_node_start->GetVal() + 1);
			if (_node_start->GetVal() > 1)
			{
				node_point temp = _alloc.allocate(sizeof(_node_start));
				temp->SetVal(val);
				temp->SetNext(_node_start->GetNext());
				temp->SetPrev(_node_start);
				(_node_start->GetNext())->SetPrev(temp);
				_node_start->SetNext(temp);
			} else
			{
				_node_end = _alloc.allocate(sizeof(_node_start));
				_node_end->SetVal(val);
				_node_end->SetNext(_node_start);
				_node_end->SetPrev(_node_start);
				_node_start->SetPrev(_node_end);
				_node_start->SetNext(_node_end);
			}
		}

		bool empty() const { if (_node_start->GetVal()) return true; return false; }

		value_type back()
		{
			value_type ref = _node_end->GetVal();
			return ref;
		}

		size_type size() const { return _node_start->GetVal(); }

		iterator erase (iterator position)
		{
			if (_node_start->GetVal() > 0)
			{
				node_point temp = _node_start;
				for(iterator iter = begin(); iter != end(); iter++)
				{
					temp = temp->GetNext();
					if (iter == position)
					{
						_node_start->SetVal(_node_start->GetVal() - 1);
						(temp->GetPrev())->SetNext(temp->GetNext());
						(temp->GetNext())->SetPrev(temp->GetPrev());
						_alloc.deallocate(temp, sizeof(_node_start));
						return ++iter;
					}
				}
			}
			return end();
		}
		iterator erase (iterator first, iterator last)
		{
			iterator it = _node_end;
			if (_node_start->GetVal() > 0)
			{
				node_point temp = _node_start;
				for(iterator iter = begin(); iter != end(); iter++)
				{
					temp = temp->GetNext();
					if (iter == first)
						break;
				}
				temp = temp->GetPrev();
				for(iterator iter = first; iter != last; iter++)
				{
					temp = temp->GetNext();
					{
						_node_start->SetVal(_node_start->GetVal() - 1);
						(temp->GetPrev())->SetNext(temp->GetNext());
						(temp->GetNext())->SetPrev(temp->GetPrev());
						_alloc.deallocate(temp, sizeof(_node_start));
						it = iter;
					}
				}
			}
			return ++it;
		}
		void clear() { if (_node_start->GetVal() > 0) {erase(begin(), end()); _node_start->SetVal(0);}}


		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL)
		{
			clear();
			node_point temp;
			_node_start = _alloc.allocate(sizeof(_node_start));
			temp = _node_start;
			size_t size = 0;
			for(InputIterator iter = first; iter != last; iter++)
			{
				_node_end = _alloc.allocate(sizeof(_node_start));
				temp->SetNext(_node_end);
				_node_end->SetVal(*iter);
				_node_end->SetPrev(temp);
				temp = _node_end;
				size++;
			}
			_node_end->SetNext(_node_start);
			_node_start->SetVal(size);
		}

		void assign (size_type n, const value_type& val)
		{
			clear();
			node_point temp;
			_node_start = _alloc.allocate(sizeof(_node_start));
			_node_start->SetVal(n);
			temp = _node_start;
			size_t size = 0;
			for(size_type i = 0; i < n; i++)
			{
				_node_end = _alloc.allocate(sizeof(_node_start));
				temp->SetNext(_node_end);
				_node_end->SetVal(val);
				_node_end->SetPrev(temp);
				temp = _node_end;
				size++;
			}
			_node_end->SetNext(_node_start);
			_node_start->SetVal(size);
		}

		iterator insert (iterator position, const value_type& val)
		{
			_node_start->SetVal(_node_start->GetVal() + 1);
			node_point temp = _node_start;
			node_point isert_temp;
			for(iterator iter = begin(); iter != end(); iter++)
			{
				if (iter == position)
				{
					isert_temp = _alloc.allocate(sizeof(_node_start));
					isert_temp->SetVal(val);
					isert_temp->SetNext(temp->GetNext());
					isert_temp->SetPrev(temp);
					temp->SetNext(isert_temp);
					(temp->GetNext())->SetPrev(isert_temp);
					return isert_temp;
				}
				temp = temp->GetNext();
			}
			return end();
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			_node_start->SetVal(_node_start->GetVal() + 1);
			node_point temp = _node_start;
			node_point isert_temp;
			for(iterator iter = begin(); iter != end(); iter++)
			{
				if (iter == position)
				{
					for(size_type i = 0; i < n; i++)
					{
						isert_temp = _alloc.allocate(sizeof(_node_start));
						isert_temp->SetVal(val);
						isert_temp->SetNext(temp->GetNext());
						isert_temp->SetPrev(temp);
						temp->SetNext(isert_temp);
						(temp->GetNext())->SetPrev(isert_temp);
					}
				}
				temp = temp->GetNext();
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL)
		{
			size_t size = 0;
			node_point temp = _node_start;
			node_point isert_temp;
			for(iterator iter = begin(); iter != end(); iter++)
			{
				if (iter == position)
				{
					for(InputIterator i = first; i != last; i++)
					{
						size++;
						isert_temp = _alloc.allocate(sizeof(_node_start));
						isert_temp->SetVal(*i);
						isert_temp->SetNext(temp->GetNext());
						isert_temp->SetPrev(temp);
						temp->SetNext(isert_temp);
						(temp->GetNext())->SetPrev(isert_temp);
					}
					_node_start->SetVal(_node_start->GetVal() + size);
					return;
				}
				temp = temp->GetNext();
			}
		}
		size_type max_size () const {return (std::numeric_limits<size_type>::max() / (sizeof(node_type)));}

		void resize (size_type n, value_type val = value_type ())
		{
			if (_node_start->GetVal() < n)
				while (_node_start->GetVal() < n)
					push_back(val);
			else
				while (_node_start->GetVal() > n)
					pop_back();
		}
		reference front() {
			value_type ref = _node_start->GetNext()->GetVal();
			return  ref;
		}
		const_reference front() const
		{
			value_type ref = _node_start->GetNext()->GetVal();
			return  ref;
		}
		const_reference back() const
		{
			value_type ref = _node_start->GetVal();
			return  ref;
		}

		allocator_type get_allocator() const { return _alloc; }

		void sort()
		{
			size_t size = _node_start->GetVal();
			if (_node_start->GetVal() <= 1)
				return;
			node_point tempi = _node_start;
			for(size_t i = 0; i != size; i++)
			{
				tempi = tempi->GetNext();
				node_point tempj = tempi;
				for (size_t j = i; j != size - 1; j++)
				{
					tempj = tempj->GetNext();
					if (tempi->GetVal() > tempj->GetVal())
					{
						value_type tempval = tempj->GetVal();
						tempj->SetVal(tempi->GetVal());
						tempi->SetVal(tempval);
					}
				}
			}
		}
		template <class Compare>
		void sort (Compare comp)
		{
			size_t size = _node_start->GetVal();
			if (_node_start->GetVal() <= 1)
				return;
			node_point tempi = _node_start;
			for(size_t i = 0; i != size; i++)
			{
				tempi = tempi->GetNext();
				node_point tempj = tempi;
				for (size_t j = i; j != size - 1; j++)
				{
					tempj = tempj->GetNext();
					if (comp(tempi->GetVal() > tempj->GetVal()))
					{
						value_type tempval = tempj->GetVal();
						tempj->SetVal(tempi->GetVal());
						tempi->SetVal(tempval);
					}
				}
			}
		}

		void merge (List& x)
		{
			for (iterator i = x.begin(); i != x.end(); i++)
			{
				node_point temp = _node_start->GetNext();
				while ((value_type)*i > (value_type)(temp->GetVal()) && temp != _node_start)
					temp = temp->GetNext();
				if (temp == _node_start)
					push_back((value_type) *i);
				else
					insert(temp, 1, (value_type) *i);
			}
			x.clear();
		}
		template <class Compare>
		void merge (List& x, Compare comp)
		{
			for (iterator i = x.begin(); i != x.end(); i++)
			{
				node_point temp = _node_start->GetNext();
				while (!(comp((value_type)*i, (value_type)(temp->GetVal()))) && temp != _node_start)
					temp = temp->GetNext();
				if (temp == _node_start)
					push_back((value_type) *i);
				else
					insert(temp, 1, (value_type) *i);
			}
		}

		void splice (iterator position, List& x)
		{
			node_point temp = _node_start;
			for (iterator iter_temp = begin(); iter_temp != position && iter_temp != end(); iter_temp++)
				temp = temp->GetNext();
			int dist = 0;
			for (iterator iter_temp = x.begin(); iter_temp != x.end(); iter_temp++)
				dist++;
			if (x._node_start->GetVal() < 1)
				return;
			_node_start->SetVal(_node_start->GetVal() + dist);
			x._node_start->SetVal(0);
			node_point next_razr = temp->GetNext();
			x._node_start->GetNext()->SetPrev(temp);
			temp->SetNext(x._node_start->GetNext());
			next_razr->SetPrev(x._node_start->GetPrev());
			x._node_start->GetPrev()->SetNext(next_razr);
			x._node_start->SetNext(x._node_start);
			x._node_start->SetPrev(x._node_start);
		}

		void splice (iterator position, List& x, iterator i)
		{
			node_point temp = _node_start;
			node_point temp_x = x._node_start;
			for (iterator iter_temp = begin(); iter_temp != position && iter_temp != end(); iter_temp++)
				temp = temp->GetNext();
			for (iterator iter_temp = x.begin(); iter_temp != i && iter_temp != x.end(); iter_temp++)
				temp_x = temp_x->GetNext();
			temp_x = temp_x->GetNext();
			_node_start->SetVal(_node_start->GetVal() + 1);
			x._node_start->SetVal(x._node_start->GetVal() - 1);
			temp_x->GetNext()->SetPrev(temp_x->GetPrev());
			temp_x->GetPrev()->SetNext(temp_x->GetNext());
			node_point next_razr = temp->GetNext();
			temp_x->SetPrev(temp);
			temp_x->SetNext(next_razr);
			next_razr->SetPrev(temp_x);
			temp->SetNext(temp_x);
		}

		void splice (iterator position, List& x, iterator first, iterator last)
		{
			node_point temp = _node_start;
			node_point temps = x._node_start;
			node_point tempe = temps;
			int dist = 0;
			for (iterator iter_temp = first; iter_temp != last; iter_temp++)
				dist++;
			for (iterator iter_temp = begin(); iter_temp != position && iter_temp != end(); iter_temp++)
				temp = temp->GetNext();
			for (iterator iter_temp = x.begin(); iter_temp != first && iter_temp != x.end(); iter_temp++)
				temps = temps->GetNext();
			for (iterator iter_temp = x.begin(); iter_temp != last && iter_temp != x.end(); iter_temp++)
				tempe = tempe->GetNext();
			temps = temps->GetNext();
			_node_start->SetVal(_node_start->GetVal() + dist);
			x._node_start->SetVal(x._node_start->GetVal() - dist);
			temps->GetPrev()->SetNext(tempe->GetNext());
			tempe->GetNext()->SetPrev(temps->GetPrev());
			node_point next_razr = temp->GetNext();
			temps->SetPrev(temp);
			temp->SetNext(temps);
			next_razr->SetPrev(tempe);
			tempe->SetNext(next_razr);
		}

		void remove (const value_type & val)
		{
			for (iterator iter_temp = begin(); iter_temp != end(); iter_temp++)
				if (*iter_temp == val)
				erase(iter_temp);
		}

		template <class Predicate>
		void remove_if (Predicate pred)
		{
			for (iterator iter_temp = begin(); iter_temp != end(); iter_temp++)
				if (pred(*iter_temp))
					erase(iter_temp);
		}

		void reverse()
		{
			node_point temp_t;
			node_point temp = _node_start;
			int len = size()+1;
			for (size_t  i  = 0; i != len; i++)
			{
				temp_t = temp->GetNext();
				temp->SetNext(temp->GetPrev());
				temp->SetPrev(temp_t);
				temp = temp_t;
			}
		}

		void swap (List& x)
		{
			node_point temp = _node_start;
			_node_start = x._node_start;
			x._node_start = temp;
			temp = _node_end;
			_node_end = x._node_end;
			x._node_end - temp;
		}

		void unique()
		{
			iterator it = begin();
			it++;
			for (iterator iter_temp = begin(); iter_temp != end(); iter_temp++)
			{
				if (*iter_temp == *it)
					erase(iter_temp);
				it++;
			}
		}

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			iterator it = begin();
			it++;
			for (iterator iter_temp = begin(); iter_temp != end(); iter_temp++)
			{
				if (binary_pred(*iter_temp, *it))
					erase(iter_temp);
				it++;
			}
		}

	};

	template <class T, class Alloc>
	void swap (List<T, Alloc>& x, List<T,Alloc>& y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::List<T>::iterator lhs_b = lhs.begin();
		typename ft::List<T>::iterator lhs_e = lhs.end();
		typename ft::List<T>::iterator rhs_b = rhs.begin();
		typename ft::List<T>::iterator rhs_e = rhs.end();
		for(lhs_b; lhs_b != lhs_e; lhs_b++)
			if (*lhs_b != *rhs_b++)
				return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs){ return (!(lhs == rhs));}

	template <class T, class Alloc>
	bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size())
			return false;
		typename ft::List<T>::iterator lhs_b = lhs.begin();
		typename ft::List<T>::iterator lhs_e = lhs.end();
		typename ft::List<T>::iterator rhs_b = rhs.begin();
		typename ft::List<T>::iterator rhs_e = rhs.end();
		for(lhs_b; lhs_b != lhs_e; lhs_b++)
			if (*lhs_b < *rhs_b++)
				return false;
		return true;
	}
	template <class T, class Alloc>
	bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		if (lhs.size() <= rhs.size())
			return false;
		typename ft::List<T>::iterator lhs_b = lhs.begin();
		typename ft::List<T>::iterator lhs_e = lhs.end();
		typename ft::List<T>::iterator rhs_b = rhs.begin();
		typename ft::List<T>::iterator rhs_e = rhs.end();
		for(lhs_b; lhs_b != lhs_e; lhs_b++)
			if (*lhs_b <= *rhs_b++)
				return false;
		return true;
	}
	template <class T, class Alloc>
	bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		if (lhs.size() > rhs.size())
			return false;
		typename ft::List<T>::iterator lhs_b = lhs.begin();
		typename ft::List<T>::iterator lhs_e = lhs.end();
		typename ft::List<T>::iterator rhs_b = rhs.begin();
		typename ft::List<T>::iterator rhs_e = rhs.end();
		for(lhs_b; lhs_b != lhs_e; lhs_b++)
			if (*lhs_b > *rhs_b++)
				return false;
		return true;
	}
	template <class T, class Alloc>
	bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		if (lhs.size() >= rhs.size())
			return false;
		typename ft::List<T>::iterator lhs_b = lhs.begin();
		typename ft::List<T>::iterator lhs_e = lhs.end();
		typename ft::List<T>::iterator rhs_b = rhs.begin();
		typename ft::List<T>::iterator rhs_e = rhs.end();
		for(lhs_b; lhs_b != lhs_e; lhs_b++)
			if (*lhs_b >= *rhs_b++)
				return false;
		return true;
	}
}