
#ifndef CONTR_RANDOM_ITERATOR_HPP
#define CONTR_RANDOM_ITERATOR_HPP

namespace ft
{
	template<class T>
	class VectorIterator
	{

	public:
		typedef T value_type;
		typedef value_type *pointer;
		typedef value_type const	*const_pointer;
		typedef value_type			&reference;
		typedef value_type const	&const_reference;
		typedef std::ptrdiff_t difference_type;
	private:
		pointer _pointer;

	public:
		//// Coplen form
		VectorIterator() : _pointer() {}

		VectorIterator(VectorIterator const &other) : _pointer(other._pointer) {};

		VectorIterator(value_type *other) : _pointer(other) {};

		VectorIterator &operator=(VectorIterator const &other) {_pointer = other._pointer; return (*this); };

		~VectorIterator() {};

		//// operators
		VectorIterator &operator++() { ++_pointer; return (*this); };
		VectorIterator operator++(int) {VectorIterator _temp; _temp = *this; ++_pointer; return (_temp); };

		VectorIterator &operator--() { --_pointer; return (*this);};
		VectorIterator operator--(int) {VectorIterator _temp; _temp = *this; --_pointer; return (_temp); };

		reference operator*() {return (*_pointer);};
		const_reference operator*() const {return (*_pointer);};

		pointer operator->() {return (_pointer);};
		const_pointer operator->() const {return (_pointer);};

		reference operator[](int n) {return *(_pointer + n);};
		const_reference operator[](int n) const {return *(_pointer + n);};

		VectorIterator &operator+=(int n) {_pointer+=n; return (*this);};
		VectorIterator operator+(int n) const {VectorIterator _temp; _temp = *this; _temp+=n; return (_temp);};

		VectorIterator &operator-=(int n) {_pointer-=n; return (*this);};
		VectorIterator operator-(int n) const {VectorIterator _temp; _temp = *this; _temp-=n; return (_temp);};

		difference_type operator-(VectorIterator const &other) const {return (_pointer - other._pointer);};

		bool operator==(VectorIterator const &other) const {if (_pointer == other._pointer) return (true); return (false);};
		bool operator!=(VectorIterator const &other) const {if (_pointer != other._pointer) return (true); return (false);};

		bool operator>(VectorIterator const &other) const {if (_pointer > other._pointer) return (true); return (false);};
		bool operator>=(VectorIterator const &other) const {if (_pointer >= other._pointer) return (true); return (false);};

		bool operator<(VectorIterator const &other) const {if (_pointer < other._pointer) return (true); return (false);};
		bool operator<=(VectorIterator const &other) const {if (_pointer <= other._pointer) return (true); return (false);};
	};

	template<class T>
	class ReverVectorIterator
	{

	public:
		typedef T value_type;
		typedef value_type *pointer;
		typedef value_type const *const_pointer;
		typedef value_type &reference;
		typedef value_type const &const_reference;
		typedef std::ptrdiff_t difference_type;
	private:
		pointer _pointer;

	public:
		//// Coplen form
		ReverVectorIterator() : _pointer() {}

		ReverVectorIterator(ReverVectorIterator const &other) : _pointer(other._pointer) {};

		ReverVectorIterator(value_type *other) : _pointer(other) {};

		ReverVectorIterator &operator=(ReverVectorIterator const &other) {_pointer = other._pointer; return (*this); };

		~ReverVectorIterator() {};

		//// operators
		ReverVectorIterator &operator++() { --_pointer; return (*this); };
		ReverVectorIterator operator++(int) {ReverVectorIterator _temp; _temp = *this; --_pointer; return (_temp); };

		ReverVectorIterator &operator--() { ++_pointer; return (*this);};
		ReverVectorIterator operator--(int) {ReverVectorIterator _temp; _temp = *this; ++_pointer; return (_temp); };

		reference operator*() {return (*_pointer);};
		const_reference operator*() const {return (*_pointer);};

		pointer operator->() {return (_pointer);};
		const_pointer operator->() const {return (_pointer);};

		reference operator[](int n) {return *(_pointer - n);};
		const_reference operator[](int n) const {return *(_pointer - n);};

		ReverVectorIterator &operator+=(int n) {_pointer-=n; return (*this);};
		ReverVectorIterator operator+(int n) const {ReverVectorIterator _temp; _temp = *this; _temp-=n; return (_temp);};

		ReverVectorIterator &operator-=(int n) {_pointer+=n; return (*this);};
		ReverVectorIterator operator-(int n) const {ReverVectorIterator _temp; _temp = *this; _temp+=n; return (_temp);};

		difference_type operator-(ReverVectorIterator const &other) const {return (_pointer - other._pointer);};

		bool operator==(ReverVectorIterator const &other) const {if (_pointer == other._pointer) return (true); return (false);};
		bool operator!=(ReverVectorIterator const &other) const {if (_pointer != other._pointer) return (true); return (false);};

		bool operator>(ReverVectorIterator const &other) const {if (_pointer > other._pointer) return (true); return (false);};
		bool operator>=(ReverVectorIterator const &other) const {if (_pointer >= other._pointer) return (true); return (false);};

		bool operator<(ReverVectorIterator const &other) const {if (_pointer < other._pointer) return (true); return (false);};
		bool operator<=(ReverVectorIterator const &other) const {if (_pointer <= other._pointer) return (true); return (false);};
	};
}

#endif //CONTR_RANDOM_ITERATOR_HPP
