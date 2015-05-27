#ifndef NODE_GO
#define NODE_GO
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

template <class T>
class Node
{
	//friend class List;
private:
	T mName;
	Node<T>* mNext;
	Node<T>* mPrev;

public:
	
	//********	 Constructors	********
	
	Node()
	{
		mName;
		mNext = NULL;
		mPrev = NULL;
	}
	//OverLoaded constructor. Initilizes object name value with given string.
	//If the string passed is not valid, 0 are added until proper size.
	
	Node(T myName)
	{
		
		mName = myName;
		mNext = NULL;
		mPrev = NULL;
	}
	//OverLoaded constructor. Initilizes object name value with given string, next node pointer to nextNode's 
	//address and previous node pointer to prevNode's address.
	//If the string passed is not valid, 0 are added until proper size.
	
	Node(T myName, Node& nextNode, Node& prevNode)
	{
		
			mName = myName;
		mNext = &nextNode;
		mPrev = &prevNode;
	}
	bool setName(T const &);
	void setNextNode(Node<T>*);
	void setPrevNode(Node<T>*);
	// Accessors
	T getName();
	Node<T>* getNextNode() const;
	Node<T>* getPrevNode() const;
	void testNode();
	//Utility
	void nameValid(T const &nameStr);

	//Expection Classes
	class NametooShort {};
	class NameisEmpty {};
	//Destructors
		~Node();
};


	
	//********		Mutators	********
	//Returns a true value if expection isn't thrown in nameValid function.
	//Returns false otherwise and prints errow message depending on what failed.
	template <class T>
	bool Node<T>::setName(T const &nameStr)
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
			std::string errorMsg = "*Error* Name can not be left empty\n";
			std::cout << errorMsg;

		}
		catch (Node::NametooShort)
		{
			std::string errorMsg = "*Error* Name must be greater than 2 characters\n";
			std::cout << errorMsg;
		}
		return status;
	}
	//Checks to ensure the passed string is not empty or less than 3 characters
	//expection object is thrown if string is empty or to short.
	template <class T>
	void Node<T>::nameValid(T const &nameStr)
	{
		/*if (nameStr.empty())
		{
			throw NameisEmpty();

		}
		else if (nameStr.length() < 3)
		{
			throw NametooShort();
		}*/
	}
	//Sets a Node Pointer to the next Node in the list.
	template <class T>
	void Node<T>::setNextNode(Node* inputPtr)
	{
		mNext = inputPtr;
	}
	//Sets a Node Pointer to the previous Node in the list.
	template <class T>
	void Node<T>::setPrevNode(Node*  inputPtr)
	{
		mPrev = inputPtr;
	}

	// ********		Accessors	********
	//Returns the name value stored in the Node.
	template <class T>
	T Node<T>::getName()
	{
		return mName;
	}

	//Returns a Node Pointer to the next Node in the list.
	template <class T>
	Node<T>* Node<T>::getNextNode() const
	{
		return mNext;
	}

	//Returns a Node Pointer to the previous Node in the list.
	template <class T>
	Node<T>* Node<T>::getPrevNode() const
	{
		return mPrev;
	}
	//a function that tests all the functions of the node class work.
	template <class T>
	void Node<T>::testNode()
	{
		//creates 3 nodes. Two have incorrect sizes to check validation is functioning
		std::cout << "Creating 3 nodes to ensure name validation" << std::endl;
		Node n1;
		Node n2("w");
		Node n3("");
		n1.setName("Jackers");

		std::cout << n1.getName() << std::endl;
		std::cout << n2.getName() << std::endl;
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
	template <class T>
	Node<T>::~Node()
	{
	}

#endif