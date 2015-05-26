#include "Node.h"

//********	 Constructors	********
Node::Node()
{
	mName = "";
	mNext = NULL;
	mPrev = NULL;
}
//OverLoaded constructor. Initilizes object name value with given string.
Node::Node(std::string myName)
{
	setName(myName);
	mNext = NULL;
	mPrev = NULL;
}
//OverLoaded constructor. Initilizes object name value with given string, next node pointer to nextNode's 
// address and previous node pointer to prevNode's address.
Node::Node(std::string myName, Node& nextNode , Node& prevNode)
{
	if (setName(myName) == false)
	{
		setName("default");
	}
	mNext = &nextNode;
	mPrev = &prevNode;
}
//********		Mutators	********
//Returns a true value if given parameter is not empty and has more than 2 characters.
//Returns false otherwise.
bool Node::setName(std::string const &nameStr)
{
	bool status = false;
	try
	{
		this->nameValid(nameStr);
		mName = nameStr;
		status = true;
	}
	catch (Node::NameisEmpty)
	{
		std::cout << "*Error* Name can not be left empty" << std::endl;
	}
	catch (Node::NametooShort)
	{
		std::cout << "*Error* Name must be greater than 2 characters" << std::endl;
	}	
	return status;
}
void Node::nameValid(std::string const &nameStr)
{
	if (nameStr.empty())
	{
		throw NameisEmpty();

	}
	else if (nameStr.length() < 3)
	{
		throw NametooShort();
	}
}
//Sets a Node Pointer to the next Node in the list.
void Node::setNextNode(Node* inputPtr) 
{
	mNext = inputPtr;
}
//Sets a Node Pointer to the previous Node in the list.
void Node::setPrevNode(Node*  inputPtr) 
{
	mPrev = inputPtr;
}

// ********		Accessors	********
//Returns the name value stored in the Node.
std::string Node::getName()
{
	return mName;
}

//Returns a Node Pointer to the next Node in the list.
Node* Node::getNextNode() const
{
	return mNext;
}

//Returns a Node Pointer to the previous Node in the list.
Node* Node::getPrevNode() const
{
	return mPrev;
}
//a function that tests all the functions of the node class work.
void Node::testNode()
{
	//creates 3 nodes. Two have incorrect sizes to check validation is functioning
	std::cout << "Creating 3 nodes to ensure name validation" << std::endl;
	Node n1;
	Node n2("w");
	Node n3("");
	n1.setName("Jackers");
	
	std::cout << n1.getName() << std::endl;
	std::cout << n2.getName();
	std::cout << n3.getName() << std::endl;

	//shows node members get properly set.
	std::cout << "showing node member variables being set.\n" << std::endl;
	n1.setNextNode(&n2);
	n2.setNextNode(&n3);
	n2.setPrevNode(&n1);
	std::cout << n1.getNextNode() << std::endl;
	std::cout << n2.getPrevNode() << std::endl;

	//showing constructor that takes arguements 
	std::cout << "Creating a node with a string Nikkers and setting \nthe node's members variable to previously created nodes\n" << std::endl;
	Node n4("Nikkers", n2, n1);
	std::cout << n4.getName() << std::endl;
	std::cout << n4.getNextNode() << std::endl;
	std::cout << n4.getPrevNode() << std::endl << std::endl;
}
//Destorys!!
Node::~Node()
{
}
