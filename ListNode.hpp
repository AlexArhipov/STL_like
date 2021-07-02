//
// Created by Adeline Vivien on 5/20/21.
//

//#ifndef CONTR_LISTNODE_HPP
//#define CONTR_LISTNODE_HPP
//
//#endif //CONTR_LISTNODE_HPP

namespace ft
{
	template<class ValueType>
	class ListNode
	{
	private:
		ListNode*	_prev;
		ListNode*	_next;
		ValueType	_val;
	public:
		ListNode() : _prev(NULL), _next(NULL), _val(NULL) {}
		ListNode(ListNode<ValueType> *prev, ListNode<ValueType> *next, ValueType val): _prev(prev), _next(next), _val(val) {}
		ListNode(const ListNode &other) { *this = other; }
		ListNode operator=(const ListNode &other) { _prev = other._prev; _next = other._next; _val = other._val; return *this; }
		~ListNode() {}

		void SetPrev(ListNode *prev) { _prev = prev; }
		void SetNext(ListNode *next) { _next = next; }
		void SetVal(ValueType val) { _val = val; }
		ListNode* GetPrev(void) { return _prev; }
		ListNode* GetNext(void) { return _next; }
		ValueType GetVal(void) { return _val; }
	};
}