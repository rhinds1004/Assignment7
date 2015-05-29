#ifndef STACK_GO
#define STACK_GO
#include "List.h"
template <class T>
class Stack : public List<T>
{
public:
	Stack();
	T pop();  //removes top node and returns the  value.
	bool push(const T &);   // adds a node with type value to the top of the list.
	//friend std::ostream &operator << (std::ostream&, Stack<T> &);
	~Stack();
};

//constructor
template <class T>
Stack<T>::Stack()
{
}

//removes of first node in the stack and returns the value it held.
template <class T>
T Stack<T>::pop()
{
	if (isEmpty() == true)
	{
		std::cout << "The stack is empty" << std::endl;
	}
	return removeFirst();
}

// adds a node with value to the top of the stack.
template <class T>
bool Stack<T>::push(const T &myStr)
{
	bool status = false;
	{
		addFirst(myStr);
		status = true;
	}
	return status;
}
//overloaded << operator
template <class T>
std::ostream &operator << (std::ostream &tempStrm, Stack<T> &aList)
{
	aList.printMe(tempStrm, aList, "stack");
	return tempStrm;
}
//destructor
template <class T>
Stack<T>::~Stack()
{
}

#endif