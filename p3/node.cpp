#include "node.hpp"

Node::Node()
{
	this->payload = 0;
	this->next = nullptr;
}

Node::Node(int payload)
{
	this->payload = payload;
	this->next = nullptr;
}

