//#ifndef LIST_GO
//#define LIST_GO
//#include "Node.h"
//class List;  //declaring it list here so the complier knows that it will exist when it sees the overloaded operator
//
////overloaded operators
//std::ostream &operator << (std::ostream &, List &);
//
//class List
//{
//	
//private:
//	Node* mHeadNode;
//	Node* mRearNode;
//protected:
//	
//public:
//	// constructors
//	List();
//	List(std::string );
//	// mutators
//	void setHeadNode(Node *);
//	void setRearNode(Node *);
//	bool listStarterNode(Node* );
//	bool addFirst(const std::string &myStr);
//	bool addLast(const std::string &myStr);
//	std::string removeFirst();
//	std::string removeLast();
//	//Utility
//	int sizeMe();
//	bool isEmpty();
//	//tests node functions
//	void nodeTest();
//	virtual void printMe(std::ostream&, List &, const std::string&) const;
//	//friends
//	friend std::ostream &operator << (std::ostream&,  List & );
//	// Destructors
//	~List();
//};
//
//#endif