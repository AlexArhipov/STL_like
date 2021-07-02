//
// Created by Adeline Vivien on 6/13/21.
//

//
// Created by Adeline Vivien on 5/20/21.
//

#ifndef CONTR_LISTNODE_HPP
#define CONTR_LISTNODE_HPP

#endif //CONTR_LISTNODE_HPP

namespace ft
{
	template <class T1, class T2>class pair
	{
	public:
		pair(): first(), second() {}
		template<class P1, class P2>
		pair(const pair<P1, P2> &other): first(other.first), second(other.second){}//{std::cout <<"!key: " <<first << " , !data: " <<second << "\n";}
		pair(const T1 &a, const T2 &b): first(a), second(b) {}
		pair &operator=(const pair& other)
		{
			first = other.first;
			second = other.second;
			return *this;
		}
		T1 GetKey() { return first; }
		T2 GetData() { return second; }
		void SetKey(T1 ) { first; }
		T1 first;
		T2 second;
	};

	template <class T> struct less : std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {return x<y;}

	};

	///////////////////////////////////////////////////////////////////////
//	template<class pair<const Key, Data> >
//	class MapNode
//	{
//	public:
//		typedef pair					value_type;
//
//	private:
//		MapNode*	_left;
//		MapNode*	_right;
//		value_type	_pair;
//	public:
//
//
//		MapNode() : _left(NULL), _right(NULL), _pair(NULL) {}
//		MapNode(MapNode<pair> *left, MapNode<pair> *right, value_type pai): _left(left), _right(right), _pair(pai) {}
//		MapNode(const MapNode &other) { *this = other; }
//		MapNode operator=(const MapNode &other) { _left = other._left; _right = other._right; _pair = other._pair; return *this; }
//		~MapNode() {}
//
//		void SetLeft(MapNode *left) { _left = left; }
//		void SetRight(MapNode *right) { _right = right; }
//		void SetKey(value_type pai) { _pair = pai; }
//	//	void SetData(ValueData data) { _data = data; }
//		MapNode* GetLeft(void) { return _left; }
//		MapNode* GetRight(void) { return _right; }
//		value_type GetKey(void) { return _pair; }
//	//	ValueData GetData(void) { return _data; }
//	};
}
