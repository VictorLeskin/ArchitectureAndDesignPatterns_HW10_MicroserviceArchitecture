///************************* OUTS HOMEWORK ****************************************
#ifndef CGAMESERVER_HPP
#define CGAMESERVER_HPP

#include "cMessagesDeque.hpp"
#include "cGameId.hpp"

class cGameServer
{
public:
	void push_back(const cMessage& item)
	{
		deque.push_back(item);
	}

	bool pop_front(cMessage& item)
	{
		return deque.pop_front(item);
	}


	cGameId getGameId();

protected:
	cMessagesDeque deque;
};

#endif //#ifndef CGAMESERVER_HPP
