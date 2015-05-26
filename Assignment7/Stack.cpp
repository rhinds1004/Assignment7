#include "Stack.h"

//constructor
Stack::Stack()
{
}

//removes of first node in the stack and returns the string value it held.
std::string Stack::pop()
{
	if (isEmpty() == true)
	{
		std::cout << "The stack is empty" << std::endl;
	}
	return removeFirst();
}

// adds a node with string value to the top of the stack.
bool Stack::push(const std::string &myStr)
{
	bool status = false;
	{
		addFirst(myStr);
		status = true;
	}
	return status;
}
std::ostream &operator << (std::ostream &tempStrm, Stack &aList)
{
	aList.printMe(tempStrm, aList, "stack");
	return tempStrm;
}
//destructor
Stack::~Stack()
{
}
