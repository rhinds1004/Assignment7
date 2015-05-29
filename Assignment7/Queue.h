#ifndef QUEUE_GO
#define QUEUE_GO
#include "List.h"

template <class T>
class Queue : public List<T>
{
public:
	Queue();
	bool enqueue(const T &);
	T dequeue();
//	std::ostream &operator << (std::ostream&, Queue<T> &);
	~Queue();
};

template <class T>
Queue<T>::Queue()
{
}

// adds a node with string value to the end of the queue.
template <class T>
bool Queue<T>::enqueue(const T &myStr)
{
	bool status = false;
	{
		addLast(myStr);
		status = true;
	}
	return status;
}

//removes of first node in the queue and returns the string value it held.
template <class T>
T Queue<T>::dequeue()
{
	if (isEmpty() == true)
	{
		std::cout << "The queue is empty" << std::endl;
	}
	return removeFirst();
}
//overloaded << operator
template <class T>
std::ostream &operator << (std::ostream& tempStrm, Queue<T> &aQueue)
{
	aQueue.printMe(tempStrm, aQueue, "queue");
	return tempStrm;
}

template <class T>
Queue<T>::~Queue()
{
}
#endif