#ifndef STACK_HPP
#define STACK_HPP
#include "node.hpp"

class Stack
{
	public:
		Stack();
		void Push(int payload);
		bool IsEmpty();
		int Pop();
		~Stack();
	private:
		Node* head;
};

#endif
