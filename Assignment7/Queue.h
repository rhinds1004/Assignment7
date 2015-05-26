#ifndef QUEUE_GO
#define QUEUE_GO
#include "List.h"
class Queue : private List
{
public:
	Queue();
	bool enqueue(const std::string &);
	std::string dequeue();
	friend std::ostream &operator << (std::ostream&, Queue &);
	~Queue();
};

#endif