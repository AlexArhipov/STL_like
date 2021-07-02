//
// Created by Adeline Vivien on 6/16/21.
//

#ifndef CONTR_MAPITERATOR_HPP
#define CONTR_MAPITERATOR_HPP

//#include "MapNode.hpp"

namespace ft
{
	template<class Data, class Val, class Node>
	class MapIterator
	{
	public:
		typedef Data 				mapped_type;
		typedef Node				*node_type;
		typedef Val					&pair_ref;
		typedef Val					*pair_point;
		typedef mapped_type			&mapped_rep;
	//	typedef						*value_point;

		node_type _iter;

		~MapIterator() {}
		MapIterator(): _iter(0) {}
		MapIterator(MapIterator const &other): _iter(other._iter) {}
		MapIterator(node_type iter): _iter(iter) {}

		MapIterator &operator=(MapIterator const &other)
		{
	//		std::cout << "operator= \n";
			_iter = other._iter;
			return (*this);
		}

		pair_ref operator*() const
		{
			if (_iter != NULL)
				return _iter->_conts;
		}

		pair_point operator->() const
		{
			if (_iter != NULL)
				return &_iter->_conts;
		}

		MapIterator operator++(int)
		{
			MapIterator tmp(*this);
			++(*this);
			return (tmp);
		}

		MapIterator operator--(int)
		{
			MapIterator tmp(*this);
			--(*this);
			return (tmp);
		}

		MapIterator &operator--()
		{
			if (_iter->_left == 0 &&_iter->_right == 0 && _iter->_paretn == 0)
				_iter = _iter->_paretn_last;
			else if (_iter->_left)
			{
				_iter = _iter->_left;
				while (_iter->_right)
					_iter = _iter->_right;
			}
			else
			{
				while (_iter->_paretn && _iter->_paretn->_left)
					_iter = _iter->_paretn;
				if (_iter->_paretn)
					_iter = _iter->_paretn;
			}
//			if (_iter == NULL)
//				_iter = _iter->_paretn_last;
			return (*this);
		}

		MapIterator &operator++()
		{
			std::cout <<  "< ========= > "  << "\n";
			if (_iter->_fl == 1)
			{
				std::cout <<  "\n\n < ===!!!!!!====== > "  << "\n";
				_iter = _iter->_paretn_last;
				return (*this);
			}
			if (_iter->_right)
			{
				std::cout <<  "< ++++++ > "  << "\n";
				_iter = _iter->_right;
				while (_iter->_left)
					_iter = _iter->_left;
			}
			else
			{
				std::cout <<  "< ++++++ > "  << "\n";
				while (_iter->_paretn && _iter->_paretn->_right)
					_iter = _iter->_paretn;
//				_iter = _iter->_paretn;
			}

			return (*this);
		}

		bool operator==(const MapIterator & other) { return (_iter == other._iter); }
		bool operator!=(const MapIterator & other) { return (_iter != other._iter); }
	};
}

#endif //CONTR_MAPITERATOR_HPP
