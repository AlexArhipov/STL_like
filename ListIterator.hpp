//
// Created by Adeline Vivien on 5/21/21.
//

#ifndef CONTR_LISTITERATOR_HPP
#define CONTR_LISTITERATOR_HPP

#endif //CONTR_LISTITERATOR_HPP

namespace ft
{
	template<class T >
	class ListIterator
	{

	public:
		typedef T value_type;
		typedef ListNode<value_type>	node_type;
		typedef node_type*				node_pointer;
		typedef value_type*				pointer;
//		typedef node_type *node_pointer;
		typedef value_type const		*const_pointer;
		typedef value_type				&reference;
		typedef value_type const		&const_reference;
		typedef std::ptrdiff_t difference_type;
	private:

		node_pointer _pointer;

	public:
		ListIterator() : _pointer(NULL){}

		ListIterator(node_pointer node): _pointer(node) {}

		ListIterator(const ListIterator &other) { _pointer = other._pointer; }

		~ListIterator() {}

		ListIterator &operator=(const ListIterator &other) { _pointer = other._pointer; return *this; }

		ListIterator &operator++() { _pointer = _pointer->GetNext(); return *this; }

		ListIterator operator++(int) { ListIterator temp = *this; _pointer = _pointer->GetNext(); return temp; }

		ListIterator &operator--() { _pointer = _pointer->GetPrev(); return *this; }

		ListIterator operator--(int) { ListIterator temp = *this; _pointer = _pointer->GetPrev(); return temp; }

		ListIterator &operator->() { return _pointer->GetVal(); }

		reference operator*() { value_type temp = _pointer->GetVal(); return temp; }
		const_reference operator*() const { value_type temp = _pointer->GetVal(); return temp; }

		ListIterator &operator+(int n) const { return *this += n; }
		ListIterator &operator-(int n) const { return *this -= n; }

		void operator+=(int n) { for(size_t i = 0; i < n; i++) *this = this->_pointer->GetNext(); }
		void operator-=(int n) { for(size_t i = 0; i < n; i++) *this = this->_pointer->GetPrev(); }

		bool operator==(ListIterator const &other) const { if (_pointer == other._pointer) return (true); return (false); }
		bool operator!=(ListIterator const &other) const { if (_pointer != other._pointer) return (true); return (false); }
		bool operator>(ListIterator const &other) const { if (_pointer->GetVal() > other._pointer->GetVal()) return (true); return (false); }
		bool operator<(ListIterator const &other) const { if (_pointer < other._pointer) return (true); return (false); }
		bool operator>=(ListIterator const &other) const { if (_pointer >= other._pointer) return (true); return (false); }
		bool operator<=(ListIterator const &other) const { if (_pointer <= other._pointer) return (true); return (false); }
	};

	template<class T >
	class ListRevIterator
	{

	public:
		typedef T value_type;
		typedef ListNode<value_type>	node_type;
		typedef node_type*				node_pointer;
		typedef value_type*				pointer;
//		typedef node_type *node_pointer;
		typedef value_type const		*const_pointer;
		typedef value_type				&reference;
		typedef value_type const		&const_reference;
		typedef std::ptrdiff_t difference_type;
	private:

		node_pointer _pointer;

	public:
		ListRevIterator() : _pointer(NULL){}

		ListRevIterator(node_pointer node): _pointer(node) {}

		ListRevIterator(const ListRevIterator &other) { _pointer = other._pointer; }

		~ListRevIterator() {}

		ListRevIterator &operator=(const ListRevIterator &other) { _pointer = other._pointer; return *this; }

		ListRevIterator &operator++() { _pointer = _pointer->GetPrev(); return *this; }

		ListRevIterator operator++(int) { ListRevIterator temp = *this; _pointer = _pointer->GetPrev(); return temp; }

		ListRevIterator &operator--() { _pointer = _pointer->GetNext(); return *this; }

		ListRevIterator operator--(int) { ListRevIterator temp = *this; _pointer = _pointer->GetNext(); return temp; }

		ListRevIterator &operator->() { return _pointer->GetVal(); }

		reference operator*() { value_type temp = _pointer->GetVal(); return temp; }
		const_reference operator*() const { value_type temp = _pointer->GetVal(); return temp; }

		ListRevIterator &operator+(int n) const { return *this -= n; }
		ListRevIterator &operator-(int n) const { return *this += n; }

		void operator+=(int n) { for(size_t i = 0; i < n; i++) *this = this->_pointer->GetPrev(); }
		void operator-=(int n) { for(size_t i = 0; i < n; i++) *this = this->_pointer->GetNext(); }

		bool operator==(ListRevIterator const &other) const { if (_pointer == other._pointer) return (true); return (false); }
		bool operator!=(ListRevIterator const &other) const { if (_pointer != other._pointer) return (true); return (false); }
		bool operator>(ListRevIterator const &other) const { if (_pointer->GetVal() > other._pointer->GetVal()) return (true); return (false); }
		bool operator<(ListRevIterator const &other) const { if (_pointer < other._pointer) return (true); return (false); }
		bool operator>=(ListRevIterator const &other) const { if (_pointer >= other._pointer) return (true); return (false); }
		bool operator<=(ListRevIterator const &other) const { if (_pointer <= other._pointer) return (true); return (false); }
	};
}