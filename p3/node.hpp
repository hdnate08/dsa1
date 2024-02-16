#ifndef NODE_HPP
#define NODE_HPP

class Node 
{
	public:
		Node();
		Node(int payload);
		int GetValue() {return this->payload;};
		Node* GetNext() {return this->next;};
void SetNext(Node* next) {this->next = next;};
	private:
		int payload;
		Node* next;
};
#endif
