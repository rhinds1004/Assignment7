#ifndef STACK_GO
#define STACK_GO
#include "List.h"
class Stack : private List
{
public:
	Stack();
	std::string pop();  //removes top node and returns the string value.
	bool push(const std::string &);   // adds a node with string value to the top of the list.
	friend std::ostream &operator << (std::ostream&, Stack &);
	~Stack();
};

#endif