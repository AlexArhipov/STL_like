//
// Created by Adeline Vivien on 6/13/21.
//


#include "Vector.hpp"


namespace ft
{
	template<class T, class Container = Vector<T> >
	class Queue
	{
	public:
		typedef T												value_type;
		typedef Container										container_type;
		typedef typename container_type::size_type				size_type;
		typedef typename container_type::iterator				container_iter;

	private:
		container_type _st;
	public:
		explicit Queue (const container_type& ctnr = container_type()): _st(ctnr) {}

		Queue(const Queue<T> &other) { *this = other; }

		Queue &operator=(const Stack<T> &other) { _st = other._st; return *this; }

		~Queue(){}

		value_type& back() { return _st.back(); }
		const value_type& back() const { return _st.back(); }
		bool empty() const { return _st.empty(); }
		value_type& front() { return _st.front(); }
		const value_type& front() const { return _st.front(); }
		void pop() {  _st.erase(_st.begin()); _st.push_back(*(_st.end() - 1));  return _st.pop_back(); }
		void push (const value_type& val) { return _st.push_back(val);}// { container_iter it = _st.begin(); return _st.insert(it-1, 1, &val); }
		size_type size() const { return _st.size(); }


		friend bool operator== (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{ return (lhs._st == rhs._st); }
		friend bool operator!= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{ return lhs._st != rhs._st; }
		friend bool operator<  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{ return lhs._st < rhs._st; }
		friend bool operator<= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{ return lhs._st <= rhs._st; }
		friend bool operator>  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{ return lhs._st > rhs._st; }
		friend bool operator>= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{ return lhs._st >= rhs._st; }
	};

}