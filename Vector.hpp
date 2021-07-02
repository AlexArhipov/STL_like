#include <iostream>
#include "Random_Iterator.hpp"

#ifndef CONTR_VECTOR_HPP
#define CONTR_VECTOR_HPP

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;

		typedef VectorIterator<value_type>					iterator;
		typedef VectorIterator<value_type const>			const_iterator;
		typedef ReverVectorIterator<value_type>				reverse_iterator;
		typedef ReverVectorIterator<value_type const>		const_reverse_iterator;

	private:
		pointer	_vector;
		Alloc	_alloc;
		size_type _size;
		size_type _capacity;
	public:

		////// vector default constructor
		explicit Vector (const allocator_type& alloc = allocator_type()):
		_alloc(alloc), _size(0), _capacity(0) {_vector = _alloc.allocate(_capacity);}

		////// vector constructor
		explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
		_alloc(alloc), _size(n), _capacity(n * 1.5)
		{
			_vector = _alloc.allocate(_capacity);
			for(size_type i = 0; i < _size; i++)
				_vector[i] = val;
		}

		////  vector constructor range
		template <class InputIterator>  // enable if
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), char [sizeof(*first)] = NULL)
		{
			_size = std::distance(first, last);
			_capacity = _size * 1.5;
			_vector = _alloc.allocate(_capacity);
			assign(first, last);
		}

		////// coplin form
		Vector &operator=(Vector const &other)
		{
			if (_vector != 0)
				_alloc.deallocate(_vector,_capacity);
			_vector = other._vector;
			_alloc = other._alloc;
			_size = other._size;
			_capacity = other._capacity;
			_vector = _alloc.allocate(_capacity);
			assign(other.begin(), other.end());
			return *this;
		}

		Vector(Vector const &other): _vector(0) { *this = other;}

		virtual ~Vector() { _alloc.deallocate(_vector,_capacity); }

		iterator begin() { return iterator(_vector);}
		const_iterator begin() const { return const_iterator(_vector); }
		iterator end() { return iterator(_vector + _size); }
		const_iterator end() const { return const_iterator(_vector + _size); }
		reverse_iterator rbegin() { return reverse_iterator (_vector + _size - 1); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator (_vector + _size - 1); }
		reverse_iterator rend() { return reverse_iterator(_vector - 1); }
		const_reverse_iterator rend() const { return const_reverse_iterator (_vector - 1); }



		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL)
		{
			size_t dis = 0;
			for(InputIterator iter = first; iter!=last; iter++)
				dis++;
			reserve(dis);
			int i = -1;
			for(InputIterator iter = first; iter!=last; iter++)
				_vector[++i] = *iter;
		}
		void assign (size_type n, const value_type& val)
		{
			clear();
			reserve(n);
			for(size_type i = 0; i < _size; i++)
				_vector[i] = val;  // val[i]
		}

		iterator erase (iterator position)
		{
			for(iterator iter = position; iter + 1 != end(); iter++)
				*iter = *(iter + 1);
			_size--;
			return (position);
		}

		iterator erase (iterator first, iterator last)
		{
			for(iterator iter = last; iter != first; iter--)
				erase(first);
			//reserve(last - first);
			return iterator(first);
		}

		void clear() { erase(begin(), end()); }

		void reserve(size_type size)
		{
			if (size > _capacity)
			{
				size_type temp_capacity = _capacity;
				size_type temp_size = _size;
				_size = size;
				_capacity = _size * 2;

				pointer temp = _alloc.allocate(_capacity);
				for(size_t i = 0; i < temp_size; i++)
					temp[i] = _vector[i];
				_alloc.deallocate(_vector, temp_capacity);
				_vector = temp;
			}
		}
		size_type size() const { return _size; }

		size_type capacity() const { return _capacity; }

		reference			operator[](size_type idx) {return _vector[idx];}
		const_reference		operator[](size_type idx) const {return _vector[idx];}

		void push_back (const value_type& val)
		{
			reserve(++_size);
			_vector[_size - 1] = val;
		}
		void pop_back() { if (_size) _vector[_size--] = 0; }

		bool empty () const
		{
			if (_size == 0)
				return true;
			return false;
		}

		iterator insert (iterator position, const value_type& val)
		{
			insert(position, 1, val);
			return position;
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			_size += n;
			reserve(_size);
			for(size_type i = 0; i < n; i++)
			{
				for(iterator iter = end(); iter != position; iter--)
					*iter = *(iter - 1);
				*position = val;
			}

		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL)
		{
			_size += std::distance(first, last);
			reserve(_size);
			for(InputIterator iter = first; first != last; iter++)
			{
				for(iterator iter1 = end(); iter1 != position; iter1--)
					*iter = *(iter - 1);
				*position = *iter;
			}
		}

		reference at (size_type n)
		{
			if (n >= 0 && n < _size)
				return _vector[n];
			throw std::out_of_range("Error: \"outofrange\"\n");
		}
		const_reference at (size_type n) const
		{
			if (n >= 0 && n < _size)
				return _vector[n];
			throw std::out_of_range("Error: \"outofrange\"\n");
		}

		void resize (size_type n, value_type val = value_type ())
		{
			size_type size = _size;

			if (n > _size)
				while (n-- > size)
					push_back(val);
			else
			{
				while (n++ < size)
					pop_back();
			}
		}

		void swap (Vector& x)
		{
			Vector temp = *this;
			*this = x;
			x = temp;
		}

		allocator_type get_allocator() const { return _alloc; }

		reference back() { return _vector[_size - 1]; }
		const_reference back() const { return _vector[_size - 1]; }
		reference front(){ return _vector[0]; }
		const_reference front() const { return _vector[0]; }
		size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); }
	};

		template <class T, class Alloc>
		bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return false;
			for(size_t i = 0; i < lhs.size(); i++)
				if (lhs[i] != rhs[i])
					return false;
			return true;
		}

		template <class T, class Alloc>
		bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			if (lhs == rhs)
				return false;
			return true;
		}

		template <class T, class Alloc>
		bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			size_t size= std::min(lhs.size(), rhs.size());
			for(size_t i = 0; i < size; i++)
				if (lhs.at(i) >= rhs.at(i))
					return false;
			return true;
		}

		template <class T, class Alloc>
		bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			size_t size= std::min(lhs.size(), rhs.size());
			for(size_t i = 0; i < size; i++)
				if (lhs.at(i) > rhs.at(i))
					return false;
			return true;
		}

		template <class T, class Alloc>
		bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			size_t size= std::min(lhs.size(), rhs.size());
			for(size_t i = 0; i < size; i++)
				if (lhs[i] <= rhs[i])
					return false;
			return true;
		}

		template <class T, class Alloc>
		bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			size_t size= std::min(lhs.size(), rhs.size());
			for(size_t i = 0; i < size; i++)
				if (lhs[i] < rhs[i])
					return false;
			return true;
		}

	template <class T, class Alloc>
	void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y)
	{
		T temp = x;
		x = y;
		y = temp;
	}


}

#endif //CONTR_VECTOR_HPP
