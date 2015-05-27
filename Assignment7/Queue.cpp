//#include "Queue.h"
//
//
//Queue::Queue()
//{
//}
//// adds a node with string value to the end of the queue.
//bool Queue::enqueue(const std::string &myStr)
//{
//	bool status = false;
//	{
//		addLast(myStr);
//		status = true;
//	}
//	return status;
//}
////removes of first node in the queue and returns the string value it held.
//std::string Queue::dequeue()
//{
//	if (isEmpty() == true)
//	{
//		std::cout << "The stack is empty" << std::endl;
//	}
//	return removeFirst();
//}
//std::ostream &operator << (std::ostream& tempStrm, Queue &aQueue)
//{
//	aQueue.printMe(tempStrm, aQueue, "queue");
//	return tempStrm;
//}
//Queue::~Queue()
//{
//}
