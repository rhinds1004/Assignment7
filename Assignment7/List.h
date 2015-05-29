#ifndef LIST_GO
#define LIST_GO
#include "Node.h"

template <class T>
class List;  //declaring it list here so the complier knows that it will exist when it sees the overloaded operator

//overloaded operators
template <class T>
std::ostream &operator << (std::ostream &, List<T> &);
template <class T>
class List
{
	
private:
	Node<T>* mHeadNode;
	Node<T>* mRearNode;
protected:
	
public:
	// constructors
	List();
	List(const T &);
	// mutators
	void setHeadNode(Node<T> *);
	void setRearNode(Node<T> *);
	bool listStarterNode(Node<T>* );
	bool addFirst(const T &);
	bool addLast(const T &);
	T removeFirst();
	T removeLast();
	//Utility
	int sizeMe();
	bool isEmpty();
	class emptyObj {};
	//tests node functions
	virtual void printMe(std::ostream&, List<T> &, const string&) const;
	//friends
	//friend std::ostream &operator << (std::ostream&,  List<T> & );
	// Destructors
	~List();
};


//********	 Constructors	********
template <class T>
List<T>::List()
{
	mHeadNode = NULL;
	mRearNode = NULL;
}

template <class T>
List<T>::List(const T &myName)
{
	Node<T> * newNode = new Node<T>(myName);
	setHeadNode(newNode);
	setRearNode(newNode);

}

//********		Mutators	********
//sets pointer to the last node in the list
template <class T>
void List<T>::setRearNode(Node<T>* aNode)
{
	mRearNode = aNode;
}
//sets pointer to the first node in the list
template <class T>
void List<T>::setHeadNode(Node<T>* aNode)
{
	mHeadNode = aNode;
}

//adds a node in an empty list
template <class T>
bool List<T>::listStarterNode(Node<T>* aNode)
{
	bool status = false;

	setHeadNode(aNode);
	setRearNode(aNode);
	status = true;

	return status;
}

//adds node to the beginning of list
template <class T>
bool List<T>::addFirst(const T &myStr)
{
	bool status = false;
	Node<T> * aNode = new Node<T>(myStr);
	if (mHeadNode == NULL)
	{
		return listStarterNode(aNode);

	}
	else
	{
		aNode->setNextNode(mHeadNode);
		mHeadNode->setPrevNode(aNode);
		mHeadNode = aNode;
		status = true;
	}
	return status;
}
//adds node to the end of list
template <class T>
bool List<T>::addLast(const T &myStr)
{
	bool status = false;
	Node<T> * aNode = new Node<T>(myStr);
	if (mHeadNode == NULL)
	{
		return listStarterNode(aNode);
	}
	else
	{
		aNode->setPrevNode(mRearNode);
		mRearNode->setNextNode(aNode);
		mRearNode = aNode;
		status = true;
	}
	return status;
}
//removal of first node in the list
template <class T>
T List<T>::removeFirst()
{

	string errorMsg = "Nothing to remove";
	T retStr;
	if (isEmpty() == true)

		throw errorMsg;
	if (mHeadNode == mRearNode)
	{
		if (mHeadNode != NULL && mRearNode != NULL)
		{
			retStr = mHeadNode->getName();
			delete mHeadNode;
			mHeadNode = NULL;
			mRearNode = NULL;
		}
	}
	if (mHeadNode != NULL)
	{
		Node<T> * tempNode = mHeadNode->getNextNode();
		if (tempNode != NULL)
		{
			tempNode->setPrevNode(mHeadNode->getPrevNode()); //sets tempNode's rear to NULL;
			retStr = mHeadNode->getName();
			delete mHeadNode;
		}
		mHeadNode = tempNode;

	}
	return retStr;
}
//removal of last node in the list
template <class T>
T List<T>::removeLast()
{
	string errorMsg = "Nothing to remove";
	T retStr;
	if (isEmpty() == true)
	
		throw errorMsg;
	if (mHeadNode == mRearNode)
	{
		if (mHeadNode != NULL && mRearNode != NULL)
		{
			retStr = mHeadNode->getName();
			delete mHeadNode;
			mHeadNode = NULL;
			mRearNode = NULL;
		}

	}
	if (mHeadNode != NULL)
	{
		Node<T> * tempNode = mRearNode->getPrevNode();
		if (tempNode != NULL)
		{
			tempNode->setNextNode(mRearNode->getNextNode()); //sets tempNode's next to NULL;
			retStr = mRearNode->getName();
			delete mRearNode;
		}
		mRearNode = tempNode;
	}
	return retStr;
}
//returns the amount of nodes within a list.
template <class T>
int List<T>::sizeMe()
{
	int size = 0;
	Node<T>* tempNode = mHeadNode;
	while (tempNode != NULL)
	{
		size++;
		tempNode = tempNode->getNextNode();
	}
	return size;
}

//checks to see if the list is empty.
template <class T>
bool List<T>::isEmpty()
{
	bool status = true;
	if (mHeadNode == NULL)
		return status;
	return status = false;
}
//member function that will	print	the	corresponding	class	members to	ostream
template <class T>
void List<T>::printMe(std::ostream& tempStrm, List<T> &aList, const string & type) const
{
	//case 1: string is empty

	if (aList.isEmpty())
	{
		tempStrm << "The " << type << " is empty.";

	}
	//case 2: there is only one node in the list
	else if (aList.mHeadNode == aList.mRearNode)
	{
		tempStrm << "Printing " << type << " by name:" << "NULL<--" << aList.mHeadNode->getName() << "-->NULL";
	
	}
	//case 3: standard case, there is more than one node in the list
	else
	{
		Node<T>* temp = aList.mHeadNode;
		tempStrm << "Printing " << type << " by name:" << "NULL";
		while (temp != NULL)
		{
			tempStrm << "<--" << temp->getName() << "-->";
			temp = temp->getNextNode();
		}
		tempStrm << "NULL";
	}

}
//overloaded operators
//overloads ostream cout to print a List object by displaying the nodes in the list in order by name
template <class T>
std::ostream &operator << (std::ostream &tempStrm, List<T> &aList)
{
	aList.printMe(tempStrm, aList, "list");
	return tempStrm;
}

//check if dynamically allocated Node needs to be deleted.
template <class T>
List<T>::~List()
{
	if (mHeadNode != NULL)
	{

		Node<T>* tempNode = mHeadNode->getNextNode();
		do
		{
			delete mHeadNode;
			mHeadNode = NULL;
			mHeadNode = tempNode;
			if (mHeadNode != NULL)
			{
				tempNode = mHeadNode->getNextNode();
			}
			else
				tempNode = NULL;
		} while (tempNode != NULL);
	}
	mRearNode = NULL;
}

#endif