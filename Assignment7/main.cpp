//=========================================================================================
// Name : Robert Hinds
// Date : 5/12/15
// Class : TCES 203
// Description : This program creates and uses several abstract data types through
//	inheritance as well aggregation. The ADT’s used are nodes, lists, stacks,
//	and queues. The Node class is the base class which contains two pointers
//	to the next node and the previous node and a string for data. List is
//	comprised of a node by aggregation as well as node pointers to the front
//	and back of the list. Queue and Stack inherit list, meaning they ARE a
// kind of list, and each are comprised of a limited measure of the
// functionality of their base class List. Queue displays the classic
//	functionality of a queue, allowing for enqueuing (adding to the back) and
//	dequeuing (removing from the front). Stack also displays its classic
//	characteristics of push (adding to the top of the stack) and pop
//	(removing from the top of the stack). Throughout this program is
//	implemented a plethora of additional pre-requisite functionality such as
//	checking if a list is empty, determining the size of a list, overloaded
//	operators and etc.
//=========================================================================================


#include "Node.h"
//#include "List.h"
//#include "Stack.h"
//#include "Queue.h"
using namespace std;
//void listTest();
//void stackTest();
//void queueTest();
int main()
{
	// Node class testing
	//cout << " calling function that tests all the functions of the node class." << endl;
	//List nodeTest;
	//nodeTest.nodeTest();
	//
	////List class testing 
	//listTest();
	//
	////Stack class testing
	//stackTest();
	//
	////Queue class testing
	//queueTest();
	//std::cout << "Creating 3 nodes to ensure name validation" << std::endl;
	//Node<string> n1("");
	//Node<string> n2("w");
	//Node<string> n3("");
	//n1.setName("Jackers");

	//std::cout << n1.getName() << std::endl;
	//std::cout << n2.getName() << std::endl;
	//std::cout << n3.getName() << std::endl;

	////shows node members get properly set.
	//std::cout << "showing node member variables being set.\n" << std::endl;
	//n1.setNextNode(&n2);
	//n2.setNextNode(&n3);
	//n2.setPrevNode(&n1);
	//std::cout << n1.getNextNode() << std::endl;
	//std::cout << n2.getPrevNode() << std::endl;

	////showing constructor that takes arguements 
	//std::cout << "Creating a node with a string Nikkers and setting \nthe node's members variable to previously created nodes\n" << std::endl;
	//Node<string> n4("Nikkers", n2, n1);
	//std::cout << n4.getName() << std::endl;
	//std::cout << n4.getNextNode() << std::endl;
	//std::cout << n4.getPrevNode() << std::endl << std::endl;
	//
	Node<int> n5(5);
	
	cin.get();
	return 0;
}

//tests list's members.
//void listTest()
//{
//	//list constructor in action
//	string str1 = "wee";
//	List alist(str1);
//	cout << "Created a list" << endl;
//	cout << alist << endl;
//	//showing addFirst() and addLast() 
//	cout << "Added a node to the front of the list with the string first" << endl;
//	alist.addFirst("first");
//	cout << "Added a node to the back of the list with the string last" << endl;
//	alist.addLast("last");
//	cout << alist << endl;
//	//shows sizeMe() in action.
//	cout << "\nThe list is checked to see if the list is empty with isEmpty() function" << endl;
//	if (alist.isEmpty() != true)
//	{
//		cout << "I have Stuff!" << endl;
//	}
//	//shows sizeMe() in action.
//	cout << "\nThe list size is checked with sizeMe() function" << endl;
//	cout << "my size is: " << alist.sizeMe() << endl << endl;
//	//removing nodes with removeFirst() and removeLast()
//	
//	cout << "this was the removed string of the last node in the list:" << alist.removeLast() << endl;
//	cout << alist << endl;
//	
//	cout << "this was the removed string of the first node in the list::" << alist.removeFirst() << endl;
//	cout << alist << endl<<endl;
//
//}
//
////tests the stack class
//void stackTest()
//{
//	Stack myStack;
//	//pushing nodes onto the stack .
//	cout << "Pushing number 1, number 2, number 3 onto the stack" << endl;
//	myStack.push("Number 1");
//	myStack.push("Number 2");
//	myStack.push("Number 3");
//	cout << myStack << endl;
//	//popping nodes off the stack
//	cout << "Popped " << myStack.pop() << " off the stack." << endl;
//	cout << "Popped " << myStack.pop() << " off the stack." << endl;	
//	cout << myStack << endl;
//	cout << myStack.pop() << endl;
//	//showing if the stack is empty.
//	cout << myStack.pop() << endl;
//}
//
////tests queue class
//void queueTest()
//{
//	Queue myQueue;
//	//adding items into the queue
//	cout << "Pushing number 4, number 5, number 6 and number 7 into the queue" << endl;
//	myQueue.enqueue("Number 4");
//	myQueue.enqueue("Number 5");
//	myQueue.enqueue("Number 6");
//	myQueue.enqueue("Number 7");
//	cout << myQueue << endl;
//	//removing items from the queue
//	cout << "Dequeued " << myQueue.dequeue() << " from the front of the queue" << endl;
//	cout << "Dequeued " << myQueue.dequeue() << " from the front of the queue" << endl;
//	cout << "Dequeued " << myQueue.dequeue() << " from the front of the queue" << endl;
//	cout << "Dequeued " << myQueue.dequeue() << " from the front of the queue" << endl;
//	//showing checks to see if queue is empty
//	myQueue.dequeue();
//
//}