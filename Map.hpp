//
// Created by Adeline Vivien on 6/13/21.
//

//#ifndef CONTR_MAP_HPP
//#define CONTR_MAP_HPP
//
//#endif //CONTR_MAP_HPP

#include <iostream>
#include "MapNode.hpp"
#include "MapIterator.hpp"
//#include <map>
//#include "ListIterator.hpp"
#include <math.h>

namespace ft
{
	template<class Key, class Data, class Compare = ft::less <Key>, class Alloc = std::allocator<ft::pair<const Key, Data> > >
	class Map
	{
	private:
		struct Node
		{
			ft::pair<const Key, Data>						_conts;
			Node*											_paretn;
			Node*											_paretn_last;
			Node*											_left;
			Node*											_right;
			Node*											_max;
			Node*											_min;
			int												_fl;
		};

	public:
		typedef Key											key_type;
		typedef Compare										key_compare;
		typedef Data 										mapped_type;
		typedef Alloc										allocator_type;
		typedef typename std::allocator<Node>				n_alloc;

		typedef ft::pair<const key_type, mapped_type>		value_type;

		typedef mapped_type									&reference;
		typedef mapped_type const							&const_reference;
		typedef mapped_type									*pointer;
		typedef mapped_type	const							*const_pointer;

		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;

		typedef typename ft::MapIterator<Data, value_type, Node>		iterator;
		typedef typename ft::MapIterator<Data, value_type const, Node>	const_iterator;
//		typedef typename ft::map_iterator<Key, T, Compare, Node, false>     iterator;

		class value_compare
		{
			friend class Map;

		protected:

			key_compare comp;

			value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object

		public:

			typedef bool        result_type;
			typedef value_type  first_argument_type;
			typedef value_type  second_argument_type;

			bool operator()(const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

//		typedef ListIterator<value_type>							iterator;
//		typedef ListIterator<value_type const>						const_iterator;
//		typedef ListRevIterator <value_type>						reverse_iterator;
//		typedef ListRevIterator<value_type const>					const_reverse_iterator;

	private:
		Node* createNode(const value_type& pair)
		{
			Node* newNode = _n_alloc.allocate(1);
			_alloc.construct(&newNode->_conts, pair);
			newNode->_fl =0;
			newNode->_left = 0;
			newNode->_right = 0;
			newNode->_paretn = 0;
			return newNode;
		}

		template<class T1, class T2>
		ft::pair<T1, T2> make_pair(T1 x, T2 y) const
		{
//			std::cout <<"key: " <<x << " , data: " <<y << "\n";
			return ft::pair<T1, T2> (x, y);
		}

		//size_type	_size;
		Alloc			_alloc;
		n_alloc			_n_alloc;
//		node_point	_node_end;
		key_compare		_comp;
		Node*			_root;
		Node*			_temp;
		Node*			_last;
		size_t			_size;
		size_t 			_caunt;
		size_t			_find;


	public:
		explicit Map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _alloc(alloc)
		{
//			std::cout << "TEST 001 \n";
			_last = createNode(pair<const key_type, mapped_type>());
			_last->_left = 0;
			_last->_right = 0;
			_last->_paretn = 0;
			_size = 0;
			_caunt = 0;
			_root = _last;
			_root->_paretn_last  = _last;
		}

		template <class InputIterator>
		Map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		{
			_last = createNode(pair<const key_type, mapped_type>());
			_last->_left = 0;
			_last->_right = 0;
			_last->_paretn = 0;
			_size = 0;
			_caunt = 0;
			_root = _last;
			insert(first, last);
		}


		ft::pair<iterator,bool> insert (const value_type& val)
		{
			Node *temp = find_Node(val.first);
			if (temp)
			{
				return ft::pair<iterator, bool>(iterator(temp), false);
			}
			temp = insert_Node(val.first, _root, val);
			return ft::pair<iterator, bool>(iterator(temp), true);
		}

		iterator insert(iterator position, const value_type& val)
		{
			while(_comp(val.first, (*position).first) && position != end())
				position--;
			return insert_Node(val.first, _root, val);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			Node *temp;
			for(InputIterator i = first; i != last; i++)
			{
				temp = find_Node((*i).first);
				if (!temp)
					insert_Node((*i).first, _root, *i);
			}
		}

		mapped_type &operator=(const key_type k)
		{

		}

		void erase (iterator position)
		{
			Node *temp = find_Node((*position).first);
		//	if (position->_right != NULL)
				Map<Key, Data> R_insert(find_Min(temp), find_Max(temp));
		//	if (position->_left != NULL)
//				Map<Key, Data> L_insert(find_Min(position->_left), find_Max(position->_left));
		//	insert(R_insert->_root.begin)
		}

//		size_type erase (const key_type& k);

//		void erase (iterator first, iterator last);

		mapped_type &operator[](const key_type k)
		{
			if (find_Node(k))
				return (find_Node(k))->_conts.second;
			value_type val = make_pair<key_type, mapped_type>(k, mapped_type());
//			std::cout << "first: " << _root->_conts.first << ", second = " << _root->_conts.second << "\n";
			return insert_Node(k, _root, val)->_conts.second;
		}

		void show()
		{
			Node *TP = _root;
			treeprint(_root);
		}

		void treeprint(Node *tree)
		{
			if (tree!=NULL) { //Пока не встретится пустой узел
				treeprint(tree->_left); //Рекурсивная функция для левого поддерева
				std::cout << "SHOW  first: " << tree->_conts.first << " , second: " << tree->_conts.second << "\n";
				treeprint(tree->_right); //Рекурсивная функция для правого поддерева
			}
		}

		void fidn_treeprint(Node *tree, key_type k)
		{
			if (tree!=NULL) { //Пока не встретится пустой узел
				fidn_treeprint(tree->_left, k); //Рекурсивная функция для левого поддерева
				if (_comp(k, tree->_conts.first) == (_comp(tree->_conts.first, k)))
					_temp = tree;
				fidn_treeprint(tree->_right, k); //Рекурсивная функция для правого поддерева
			}
		}

		Node* insert_Node(const key_type k, Node *root, const value_type &pair)
		{
			if (_size == 0)
			{
				Node *temp = createNode(pair);
//				_n_alloc.deallocate(_root, 1);
				_root = temp;
				_size++;
				return _root;
			}
			if (_comp(k, root->_conts.first) && root->_left)
				return insert_Node(k, root->_left, pair);
			else if (!_comp(k, root->_conts.first) && root->_right)
				return insert_Node(k, root->_right, pair);
			Node *temp = createNode(pair);
			if (_comp(k, root->_conts.first))
				root->_left = temp;
			else
				root->_right = temp;
			temp->_paretn = root;
			_size++;
			return temp;
		}
		iterator find (const key_type& k)
		{
			return find_Node(k);
		}
		const_iterator find (const key_type& k) const
		{

		}

		Node* find_Node(key_type k)
		{
			_temp = 0;
			fidn_treeprint(_root, k);
			return _temp;
		}

		Node* find_Min(Node *root)
		{
			_temp = 0;
			_temp = root;
			while (_temp->_left)
				_temp = _temp->_left;
			return _temp;
		}

		Node* find_Max(Node *root)
		{
			_temp = 0;
			_temp = root;
			while (_temp->_right)
				_temp = _temp->_right;
			return _temp;
		}

		iterator begin()
		{
			_last = find_Max(_root);
			find_Max(_root)->_fl = 1;
//			std::cout << find_Max(_root)->_conts.first << "< ========= > "  << "\n";
//			std::cout << _root->_max->_conts.first << "< ========= > "  << "\n";
			return find_Min(_root); }

		iterator end()
		{
			_last = find_Max(_root);
			return _root->_paretn_last;
		}
		const_iterator begin() const
		{ return find_Min(_root); }
	};
}