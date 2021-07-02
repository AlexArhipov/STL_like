//
// Created by Adeline Vivien on 6/12/21.
//

#include "Vector.hpp"

namespace ft
{
	template<class T, class Container = Vector<T> >
	class Stack
	{
	public:
		typedef T												value_type;
		typedef Container										container_type;
		typedef typename container_type::size_type				size_type;

	private:
		container_type _st;
	public:
		explicit Stack (const container_type& ctnr = container_type()): _st(ctnr) {}

		Stack(const Stack<T> &other) { *this = other; }

		Stack &operator=(const Stack<T> &other) { _st = other._st; return *this; }

		~Stack(){}

		bool empty() const { return _st.empty(); }
		void pop() { return _st.pop_back(); }
		void push (const value_type& val) { return _st.push_back(val); }
		size_type size() const { return _st.size(); }
		value_type& top() { return _st.back(); }
		const value_type& top() const { return _st.back(); }

		friend bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{ return (lhs._st == rhs._st); }
		friend bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{ return lhs._st != rhs._st; }
		friend bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{ return lhs._st < rhs._st; }
		friend bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{ return lhs._st <= rhs._st; }
		friend bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{ return lhs._st > rhs._st; }
		friend bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{ return lhs._st >= rhs._st; }
	};

}