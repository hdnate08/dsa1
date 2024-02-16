#include "stack.hpp"
#include <limits>

Stack::Stack()
{
	this->head = nullptr;
}

void Stack::Push(int payload)
{
	Node* n = new Node(payload);
	n->SetNext(this->head);
	this->head = n;	
}

Stack::~Stack()
{
	while(this->head != nullptr)
	{
		this->Pop();
	}
}

bool Stack::IsEmpty()
{
	if(this->head == nullptr)
	{
		return true;
	}
	return false;
}

int Stack::Pop()
{
	if(this->head !=nullptr)
	{
		Node* node = this->head;
		int temp = this->head->GetValue();
		this->head = this->head->GetNext();
		delete node;
		return temp;
	}
	else
	{
		return std::numeric_limits<int>::min();
	}
}
